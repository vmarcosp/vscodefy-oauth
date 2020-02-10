open ProjectInformationsHook;

[@react.component]
let make = () => {
  let { stars, forks } = useProjectInformations();

  ProjectInformations_Styles.(
    <ul className=list>
      <li>{"5k Downloads"->React.string}</li>
      <span className=divider/>
      <li>
        {stars->Render.int} {" Stars"->React.string}
      </li>
      <span className=divider/>
      <li>
        {forks->Render.int} {" Forks"->React.string}
      </li>
    </ul>
  );
};
