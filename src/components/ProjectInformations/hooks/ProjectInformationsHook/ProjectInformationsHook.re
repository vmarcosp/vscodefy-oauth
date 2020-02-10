module RePromise = Promise.Js;
let githubApi = "https://api.github.com/repos/iagolaguna/vscodefy";

type githubData = {
  stars: int,
  forks: int,
};

let createGithubData = data => {
  stars: data##stargazers_count,
  forks: data##forks,
};

let always = value => _ => value

let useProjectInformations = () => {
  let (githubData, setGitHubData) = React.useState(always({ 
    stars: 0, forks: 0
  }));

  let saveData = response => response##data
      ->createGithubData
      ->always
      ->setGitHubData

  let requestGithubData = () =>
    Axios.get(githubApi)
      ->RePromise.fromBsPromise
      ->RePromise.get(saveData);

  React.useEffect1(
    () => {
      requestGithubData();
      None;
    },
    [|requestGithubData|],
  );

  (githubData);
};
