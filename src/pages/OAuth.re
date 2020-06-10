module Styles = {
  open Css;

  let container =
    style([
      display(`flex), //
      flexDirection(`row),
    ]);
};

[@react.component]
let make = () => {
  Styles.(
    <div className=container>
      <Steps currentStep=3>
        <Steps.Step stepId=1 />
        <Steps.Step stepId=2 />
        <Steps.Step stepId=3 />
        <Steps.Step stepId=4 />
      </Steps>
      <div> "Content"->React.string </div>
    </div>
  );
};
