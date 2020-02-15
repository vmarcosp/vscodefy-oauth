module RePromise = Promise.Js

type responseError = {
  status: int,
  log: string,
}

type result('a) =
  | Data('a)
  | Error
  | Loading

let useGet = url => {
  let (result, setResult) = Hooks.useState(Loading)

  let whenSucess = response => Data(response##data)
      |>Hooks.always 
      |>setResult

  let request = () => { RePromise.(
      Axios.get(url)
        ->fromBsPromise
        ->get(whenSucess)
    )

    None
  }

  Hooks.useEffectOnce(request)

  result
}
