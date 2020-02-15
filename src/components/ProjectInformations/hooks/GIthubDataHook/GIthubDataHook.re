module RePromise = Promise.Js

let githubApi = "https://api.github.com/repos/iagolaguna/vscodefy";

type githubData = {
  stars: int,
  forks: int,
};

let createGithubData = data => {
  stars: data##stargazers_count,
  forks: data##forks,
};

let useGithubData = () => {
  let result = AxiosHook.useGet(githubApi)
  
  switch(result){
    | Data(data) => AxiosHook.Data(createGithubData(data))
    | Loading => AxiosHook.Loading
    | Error => AxiosHook.Error
  }
}
