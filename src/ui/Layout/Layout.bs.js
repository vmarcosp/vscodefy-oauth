'use strict';

var Css = require("bs-css/src/Css.js");

var container = Css.style(/* :: */[
      Css.width(Css.vw(100.0)),
      /* :: */[
        Css.height(Css.vh(100.0)),
        /* :: */[
          Css.boxSizing(/* borderBox */9307263),
          /* [] */0
        ]
      ]
    ]);

var Styles = {
  container: container
};

exports.Styles = Styles;
/* container Not a pure module */
