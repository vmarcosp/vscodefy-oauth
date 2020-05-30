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
let downloadsApi = "http://localhost:3000/downloads";

let mergeData = ({ stargazers_count, forks }, { amount }) =>
  ProjectData({
    stars: stargazers_count >? 0,
    forks: forks >? 0,
    downloadsAmount: amount >? 0
  });

let useProjectInformations = () => {
  let githubResult: AxiosHooks.result(githubData, _) =
    AxiosHooks.useGet(~url=githuApi);

  let downloadsResult: AxiosHooks.result(downloads, _) =
    AxiosHooks.useGet(~url=downloadsApi);

  switch (githubResult, downloadsResult) {
  | (Data(github), Data(downloads)) => mergeData(github, downloads)
  | (Loading | Data(_), Loading | Data(_)) => Loading
  | (Error(_) | _, Error(_) | _) => Error
  };
};
