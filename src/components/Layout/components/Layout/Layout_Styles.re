open Css;
open Theme;

let container = style([
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
  width(100.0->pct),
  height(100.0->pct),
  zIndex(100),
  position(`fixed),
  top(0->px),
  left(0->px),
  padding(70->px),
  boxSizing(`borderBox)
])
