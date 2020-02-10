open ReactReveal;

let topIconUrl = Utils.import("./top.svg");
let bottomIconUrl = Utils.import("./bottom.svg");

[@react.component]
let make = (~children) => Layout_Styles.(
  <div className=container>
    <Fade right=true>
      <img 
        className=topIcon 
        src=topIconUrl 
        alt="Background" 
      />
    </Fade>

    <Fade left=true>
      <img 
        className=bottomIcon 
        src=bottomIconUrl 
        alt="Background" 
      />
    </Fade>
    <div className=content>
      children
    </div>
  </div>
);
