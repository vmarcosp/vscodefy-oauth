/**
 * Global Styles
 */
Css.(
  global("html, body, #root", [
    width(100.0 -> vw),
    height(100.0 -> vh),
    padding(0 -> px),
    margin(0 -> px)
  ])
);

module App = {
  [@react.component]
  let make = () => <div> {React.string("teste")} </div>;
};

ReactDOMRe.renderToElementWithId(<App />, "root");
