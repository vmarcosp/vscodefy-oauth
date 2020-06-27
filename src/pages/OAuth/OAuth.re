open OAuthHooks;

module ConnectStep = {
  [@react.component]
  let make = (~id) => <StepContent
      step=id
      title="Welcome! to start connect your spotify account"
      description="Welcome to vscodefy!"
    />
};

[@react.component]
let make = () => {
  let { step } = useOAuth(ConnectAccount);

  OAuth_Styles.(
    <div className=container>

      <Steps currentStep=getStepId(step)>
        <Steps.Step stepId=ConnectAccount->getStepId/>
        <Steps.Step stepId=CopyCode->getStepId />
        <Steps.Step stepId=OpenVSCode->getStepId />
      </Steps>

      {switch step {
        | ConnectAccount => <ConnectStep id={getStepId(ConnectAccount)} />
        | _ => <div />
      }}
    </div>
  );
};
