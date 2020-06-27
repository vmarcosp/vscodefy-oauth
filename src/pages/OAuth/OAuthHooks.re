type steps =
 | ConnectAccount
 | CopyCode
 | OpenVSCode;

type hookResult = {
  step: steps,
  goTo: steps => unit,
};

let getStepId = fun
  | ConnectAccount => 1
  | CopyCode => 2
  | OpenVSCode => 3;

let useOAuth = (initialStep) => {
  let (step, setStep) = React.useState(_ => initialStep);

  let goTo = step => step->Hooks.always->setStep;

  {step, goTo };
};
