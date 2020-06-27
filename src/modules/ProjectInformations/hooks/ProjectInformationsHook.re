[@decco]
type downloads = {amount: int};

[@decco]
type githubData = {
  [@decco.key "stargazers_count"]
  stars: int,
  forks: int,
};

type response =
  | ProjectData(githubData, downloads)
  | Loading
  | Error;

let githubApi = "https://api.github.com/repos/iagolaguna/vscodefy";
let downloadsApi = "http://localhost:3000/downloads";

let useProjectInformations = () => {
  let (githubResult, downloadsResult) =
    AxiosHooks.(
      useGet(githubApi, githubData_decode),
      useGet(downloadsApi, downloads_decode),
    );

  switch (githubResult, downloadsResult) {
  | (Data(github), Data(downloads)) => ProjectData(github, downloads)
  | (Loading | Data(_), Loading | Data(_)) => Loading
  | (_, Error(_) | DecodeError)
  | (Error(_) | DecodeError, _) => Error
  };
};
