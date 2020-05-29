open ReactReveal;

let githubIconUrl = Utils.import("./github-icon.svg");

[@react.component]
let make = () =>
  Menu_Styles.(
    <Fade delay=600 right=true cascade=true>
      <ul className=container>
        <li> "Home"->React.string </li>
        <li> "OAuth"->React.string </li>
        <li>
          <a href="https://github.com">
            <img src=githubIconUrl alt="Github Icon" />
          </a>
        </li>
      </ul>
    </Fade>
  );
