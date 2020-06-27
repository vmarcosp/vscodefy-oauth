/**
 * Global Styles
 */
Css.(
  global(
    "html, body, #root",
    [
      width(100.0->vw), //
      height(100.0->vh),
      padding(0->px),
      margin(0->px),
    ],
  )
);

[@react.component]
let make = (~text) => {
  let url = ReasonReactRouter.useUrl();

  <Layout>
    {React.string(text)}
    <Header />
    {switch (url.path) {
     | ["home"] => <Home />
     | ["oauth"] => <OAuth />
     | _ => <Home />
     }}
  </Layout>;
};
