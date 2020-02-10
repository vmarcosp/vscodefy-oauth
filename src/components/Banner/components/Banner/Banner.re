
let title = "Use Spotify inside vscode"->React.string;
let subtitle = "Provides integration with Spotify Web API and remote-control resources"->React.string;

[@react.component]
let make = () => {
  Banner_Styles.(
    <div className=container>
      <h1>{title}</h1>
      <p>{subtitle}</p>
    </div>
  )
};
