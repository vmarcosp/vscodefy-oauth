open ReactReveal;

type menuItem =
  | Link(string, React.element)
  | GitHubLink;

let items =
  React.(
    [|
      Link("/", "Home"->string),
      Link("/oauth", "OAuth"->string),
      GitHubLink,
    |]
  );

let renderItem =
  fun
  | Link(url, label) => <MenuItem.Link url label />
  | GitHubLink => <MenuItem.GitHubLink />;

[@react.component]
let make = () => {
  Menu_Styles.(
    <Fade delay=600 right=true cascade=true>
      <ul className=container> {items->Render.map(renderItem)} </ul>
    </Fade>
  );
};
