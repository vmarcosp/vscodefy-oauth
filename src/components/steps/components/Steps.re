// type stepContext = {currentStep: int};

// let stepsContext = React.createContext({currentStep: 0});

//module StepsProvider = {
//  let make = React.Context.provider(stepsContext);
//  let makeProps = (~value, ~children, ()) => {
//    "value": value,
//    "children": children,
//  };

/*module type StepConfig = {
  type t;
  let initialStep: t;
};

module Make = (Config: StepConfig) => {
  type stepContext = {currentStep: Config.t};

  let stepsContext = React.createContext({currentStep: Config.initialStep});

  module StepsProvider = {
    let make = React.Context.provider(stepsContext);

    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
  };

  [@react.component]
  let make = (~children) => {
    let (state, setState) = React.useReducer(_ => Config.initialStep);
    let
    <StepsProvider value={currentStep: state}> children </StepsProvider>;
  };
};*/

[@react.component]
let make = () => <div />;
