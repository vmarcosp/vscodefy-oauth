let githubIconUrl = Utils.import("./github-icon.svg");

module GitHubLink = {
  [@react.component]
  let make = () => {
    Menu_Styles.(
      <li className=item>
        <a href="https://github.com/vscodefy/vscodefy-oauth">
          <img src=githubIconUrl alt="Github Icon" />
        </a>
      </li>
    );
  };
};

module Link = {
  [@react.component]
  let make = (~url, ~label) => {
    let push = (url, _) => ReasonReactRouter.push(url);
    Menu_Styles.(
      <li className=item>
        <button className=button onClick={push(url)}> label </button>
      </li>
    );
  };
};
