module RePromise = Promise.Js;

type responseError = {
  status: int,
  log: string,
};

type result('a) =
  | Data(option('a))
  | Error
  | Loading;

external fromPromiseError: Js.Promise.error => Js.t('a) = "%identity";

module Fetcher = {
  module JsPromise = Js.Promise;
  module Result = Belt.Result;

  let toPromiseError = error => {
    let realError = fromPromiseError(error);
    Js.Promise.resolve(realError);
  };

  let toPromiseSuccess = response => JsPromise.resolve(response);

  let toResult = promise =>
    promise  //
    |> JsPromise.then_(toPromiseSuccess)
    |> JsPromise.catch(toPromiseError);

  let get = url =>
    url  //
    |> Axios.get
    |> toResult
    |> RePromise.fromBsPromise
    |> RePromise.toResult;
};

let useGet = (~url) => {
  let (result, setResult) = Hooks.useState(Loading);

  let whenSuccess = response =>
    Data(Some(response##data))  //
    |> Hooks.always
    |> setResult;

  let request = () => {
    Fetcher.get(url) //
    ->Promise.getOk(Js.log);
    None;
  };

  React.useEffect1(request, [|url|]);

  result;
};
