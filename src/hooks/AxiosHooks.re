module RePromise = Promise.Js;
module Promise = Js.Promise;
module Result = Belt.Result;

type axiosError('a, 'header) = {
  .
  "status": string,
  "response": Axios_types.response('a, 'header),
};

external fromPromiseError: Js.Promise.error => axiosError('a, 'header) =
  "%identity";

type axiosHooksError('a) = {
  data: 'a,
  status: string,
};

type result('data, 'dataError) =
  | Data('data)
  | Error(axiosHooksError('dataError))
  | DecodeError
  | Loading;

let toOk = response =>
  response //
  ->Result.Ok
  ->Promise.resolve;

let toError = error =>
  error //
  ->fromPromiseError
  ->Result.Error
  ->Promise.resolve;

let get = url => {
  Axios.get(url)
  |> Promise.then_(toOk)
  |> Promise.catch(toError)
  |> RePromise.fromBsPromise;
};

let useGet = (url, decoder) => {
  let (result, setResult) = Hooks.useState(Loading);

  let whenSuccess = response => {
    let decoded = decoder(response##data);

    switch (decoded) {
    | Ok(content) => Data(content) |> Hooks.always |> setResult
    | Error(_) => DecodeError |> Hooks.always |> setResult
    };
  };

  let whenError = error =>
    Error({data: error##response##data, status: error##status})
    ->Hooks.always
    ->setResult;

  let processResponse = result => {
    switch (result) {
    | Ok(response) => whenSuccess(response)
    | Error(error) => whenError(error)
    };
    ();
  };

  let request = () => {
    get(url)->RePromise.get(processResponse);
    None;
  };

  React.useEffect1(request, [|url|]);

  result;
};
