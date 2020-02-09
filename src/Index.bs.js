'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");

Css.$$global("html, body, #root", /* :: */[
      Css.width(Css.vw(100.0)),
      /* :: */[
        Css.height(Css.vh(100.0)),
        /* :: */[
          Css.padding(Css.px(0)),
          /* :: */[
            Css.margin(Css.px(0)),
            /* [] */0
          ]
        ]
      ]
    ]);

function Index$App(Props) {
  return React.createElement("div", undefined, "teste");
}

var App = {
  make: Index$App
};

ReactDOMRe.renderToElementWithId(React.createElement(Index$App, { }), "root");

exports.App = App;
/*  Not a pure module */
