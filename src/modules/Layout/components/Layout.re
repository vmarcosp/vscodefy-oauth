open ReactReveal;

let topGreenUrl = Utils.import("./assets/top-green.svg");
let bottomGreenUrl = Utils.import("./assets/bottom-green.svg");
let topBlueUrl = Utils.import("./assets/top-blue.svg");
let bottomBlueUrl = Utils.import("./assets/bottom-blue.svg");

[@react.component]
let make = (~children) =>
  Layout_Styles.(
    <div className=container>
      <Fade delay=200 right=true>
        <img className=topIcon src=topBlueUrl alt="Background" />
      </Fade>
      <Fade delay=600 right=true>
        <img className=topIcon src=topGreenUrl alt="Background" />
      </Fade>
      <Fade delay=200 left=true>
        <img className=bottomIcon src=bottomBlueUrl alt="Background" />
      </Fade>
      <Fade delay=600 left=true>
        <img className=bottomIcon src=bottomGreenUrl alt="Background" />
      </Fade>
      <div className=content> children </div>
    </div>
  );
