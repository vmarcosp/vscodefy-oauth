open Css;
open Theme;

let container =
  style([
    width(100.0->vw),
    height(100.0->vh),
    boxSizing(`borderBox),
    backgroundColor(Colors.black->hex)
]);

let topIcon = style([
    position(`fixed), 
    top(0->px), 
    right(0->px)
]);

let bottomIcon = style([
    position(`fixed), 
    bottom(0->px), 
    left(0->px)
]);

let content = style([
  position(`fixed),
  width(100.0->vw),
  height(100.0->vh),
  boxSizing(`borderBox),
  overflow(`auto),
  MediaQuery.sm([
    padding(70->px),
  ]),
])
