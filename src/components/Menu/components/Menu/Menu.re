let githubIconUrl = Utils.import("./github-icon.svg");

[@react.component]
let make = () =>
  Menu_Styles.(
    <ul className=container>
      <li>{"home"->React.string}</li>
      <li>{"login"->React.string}</li>
      <li>
        <a href="https://github.com">
          <img src=githubIconUrl alt="Github Icon"/>
        </a>
      </li>
    </ul>
  );
