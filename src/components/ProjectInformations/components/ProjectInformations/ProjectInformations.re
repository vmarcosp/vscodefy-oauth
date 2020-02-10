open ProjectInformationsHook;
open ReactReveal;

[@react.component]
let make = () => {
  let {stars, forks} = useProjectInformations();

  ProjectInformations_Styles.(
    <Fade delay=800 bottom=true>
      <ul className=list>
        <li> "5k Downloads"->React.string </li>
        <span className=divider />
        <li> stars->Render.int " Stars"->React.string </li>
        <span className=divider />
        <li> forks->Render.int " Forks"->React.string </li>
      </ul>
    </Fade>
  );
};
