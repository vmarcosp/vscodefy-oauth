type stepContext = {
  currentStep: int,
  stepsAmount: int
};

let stepsContext = React.createContext({
  currentStep: 0,
  stepsAmount: 0
});

let useSteps = () => React.useContext(stepsContext);

module Provider = {
 let make = React.Context.provider(stepsContext);
 let makeProps = (~value, ~children, ()) => {
   "value": value,
   "children": children,
 };
};

