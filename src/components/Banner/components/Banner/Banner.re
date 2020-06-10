open ReactReveal;

let titleContent = "Use Spotify inside vscode"->React.string;
let subtitleContent = "Provides integration with Spotify Web API and remote-control resources"->React.string;

[@react.component]
let make = () => {
  Banner_Styles.(
    <div className=container>

      <Fade delay=600 bottom=true>
        <h1 className=title>
          {titleContent}
        </h1>
      </Fade>

      <Fade delay=900 bottom=true>
        <p className=subtitle>
          {subtitleContent}
        </p>
      </Fade>

      <Fade delay=1000 bottom=true>
        <div className=buttonContainer>
          <Button
            label="GET VSCODE EXTENSION"
          />
        </div>
      </Fade>

    </div>
  )
};
