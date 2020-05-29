open Optional;

type downloads = {amount: option(int)};

type githubData = {
  stargazers_count: option(int),
  forks: option(int),
};

type projectData = {
  stars: int,
  forks: int,
  downloadsAmount: int,
};

type response =
  | ProjectData(projectData)
  | Loading
  | Error;

let githuApi = "https://api.github.com/repos/iagolaguna/vscodefy";
// let downloadsApi = "http://localhost:3000/downloads";
let downloadsApi = "http://www.mocky.io/v2/5ec9bb063000000d00a6ce5d";

let getDownloadsAmount =
  fun
  | Some({amount}) => amount >? 0
  | None => 0;

let parseGithubData =
  fun
  | Some({stargazers_count, forks}) => (stargazers_count >? 0, forks >? 0)
  | None => (0, 0);

let mergeData = (githubData, downloads) => {
  let (stars, forks) = parseGithubData(githubData);
  let downloadsAmount = getDownloadsAmount(downloads);

  ProjectData({stars, forks, downloadsAmount});
};

let useProjectInformations = () => {
  let githubResult: AxiosHooks.result(githubData) =
    AxiosHooks.useGet(~url=githuApi);

  let downloadsResult: AxiosHooks.result(downloads) =
    AxiosHooks.useGet(~url=downloadsApi);

  Js.log((githubResult, downloadsResult));
  switch (githubResult, downloadsResult) {
  | (Data(github), Data(downloads)) => mergeData(github, downloads)
  //
  | (Loading, Data(_))
  | (Data(_), Loading)
  | (Loading, Loading) => Loading
  //
  | (Error | _, Error | _) => Error
  };
};
