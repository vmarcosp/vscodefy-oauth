module Styles = {
  open Css;

  let button =
    style([
      background(`transparent),
      listStyleType(`none),
      borderStyle(`none),
      display(`flex),
      cursor(`pointer),
      alignItems(`center),
      padding2(~v=0->px, ~h=32->px),
      height(`auto),
      margin(0->px),
      fontSize(22->px),
      color(white),
      fontWeight(`num(500)),
      fontFamily(Theme.font),
      selector("a", [display(`flex), alignItems(`center)]),
    ]);
};

[@react.component]
let make = (~url, ~label) => {
  let push = (url, _) => ReasonReactRouter.push(url);

  <li>
    <button className=Styles.button onClick={push(url)}> label </button>
  </li>;
};
