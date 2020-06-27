let logoUrl = Utils.import("./logo.svg");

[@react.component]
let make = () => Logo_Styles.(
  <img 
    src=logoUrl 
    className=logo
    alt="VSCodefy Logo"
  />
)
