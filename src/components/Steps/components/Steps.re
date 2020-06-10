module Step = Steps_Step;

[@react.component]
let make = (~currentStep, ~children) => {
  StepsContext.(
    <StepsContext.Provider
      value={currentStep, stepsAmount: React.Children.count(children)}>
      <div> children </div>
    </StepsContext.Provider>
  );
};
