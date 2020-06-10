open ReactReveal;

let githubIconUrl = Utils.import("./github-icon.svg");

type menuItem = {
  url: string,
  label: React.element,
};

let items =
  React.(
    [|
      {label: "Home"->string, url: "/"},
      {label: "OAuth"->string, url: "/oauth"},
    |]
  );

[@react.component]
let make = () => {
  Menu_Styles.(
    <Fade delay=600 right=true cascade=true>
      <ul className=container>
        {items->Render.map(item =>
           <MenuItem url={item.url} label={item.label} />
         )}
        <li>
          <a href="https://github.com">
            <img src=githubIconUrl alt="Github Icon" />
          </a>
        </li>
      </ul>
    </Fade>
  );
};
