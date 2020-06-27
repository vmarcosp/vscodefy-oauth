module Styles = {
  open Css;

  let container =
    style([
      //
      marginLeft(24->px),
    ]);

  let stepId =
    style([
      color("9AA0A8"->hex),
      fontFamily(Theme.font),
      fontSize(1.2->rem),
      textTransform(`uppercase),
    ]);

  let title =
    style([
      color(white),
      fontFamily(Theme.font),
      fontSize(2.->rem),
      margin(0->px),
      textTransform(`uppercase),
    ]);
};

[@react.component]
let make = (~step, ~title as stepTitle, ~description) => {
  Styles.(
    <div className=container>
      <span className=stepId> "Step "->React.string step->React.int </span>
      <h3 className=title> stepTitle->React.string </h3>
    </div>
  );
};
