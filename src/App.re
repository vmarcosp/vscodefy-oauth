/**
 * Global Styles
 */
Css.(
  global(
    "html, body, #root",
    [width(100.0->vw), height(100.0->vh), padding(0->px), margin(0->px)],
  )
);

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  Js.log(url);
  switch (url.path) {
  | ["home"] => <Home />
  | ["login"] => <div />
  | _ => <Home />
  };
};
