module RePromise = Promise.Js;

type responseError = {
  status: int,
  log: string,
};

type result('a) =
  | Data(option('a))
  | Error
  | Loading;

let useGet = (~url) => {
  let (result, setResult) = Hooks.useState(Loading);

  let whenSuccess = response =>
    Data(Some(response##data))  //
    |> Hooks.always
    |> setResult;

  let request = () => {
    RePromise.(
      Axios.get(url) //
      ->fromBsPromise
      ->get(whenSuccess)
    );

    None;
  };

  React.useEffect1(request, [|url|]);

  result;
};
