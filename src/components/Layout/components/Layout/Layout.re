let topIconUrl = Utils.import("./top.svg");
let bottomIconUrl = Utils.import("./bottom.svg");

[@react.component]
let make = (~children) => Layout_Styles.(
  <div className=container>
    <img 
      className=topIcon 
      src=topIconUrl 
      alt="Background" 
    />

    <img 
      className=bottomIcon 
      src=bottomIconUrl 
      alt="Background" 
    />
    <div className=content>
      children
    </div>
  </div>
);
