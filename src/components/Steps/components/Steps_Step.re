open StepsTypes;

let checkIcon = Utils.import("./check.svg");

let getStepStatus =
  fun
  | (step, current) when step == current => Active
  | (step, current) when step < current => Done
  | (step, current) when step > current => Inactive
  | (_, _) => Inactive;

[@react.component]
let make = (~stepId) => {
  let value = StepsContext.useSteps();
  let status = getStepStatus((stepId, value.currentStep));

  Steps_StepStyles.(
    <div className=container>
      <div className={dividerTop(stepId, status)} />
      <div className={circle(status)}>
        <div className=border>
          {switch (status) {
           | Done => <img src=checkIcon />
           | _ => stepId->Render.int
           }}
        </div>
      </div>
      <div className={dividerBottom(stepId, value.stepsAmount, status)} />
    </div>
  );
};
