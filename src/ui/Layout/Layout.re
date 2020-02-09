
module Styles = {
  open Css;
  let container = style([
    width(100.0 -> vw),
    height(100.0 -> vh),
    boxSizing(`borderBox),
    backgroundColor(Theme.Colors.black -> hex)
  ])
};

[@react.component]
let make = (~children) => <div className=Styles.container>{children}</div>
