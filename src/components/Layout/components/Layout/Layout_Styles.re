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
    right(0->px),
    height(`auto),
    MediaQuery.xs([
      display(none)
    ]),
    MediaQuery.sm([
      width(270->px),
    ]),
    MediaQuery.md([
      width(470->px),
    ]),
    MediaQuery.lg([
      width(670->px),
    ]),
    MediaQuery.xl([
      width(870->px),
    ])
]);

let bottomIcon = style([
    position(`fixed), 
    bottom(0->px), 
    left(0->px),
     MediaQuery.xs([
      display(none)
    ]),
    MediaQuery.md([
      width(200->px),
    ]),
    MediaQuery.lg([
      width(400->px),
    ]),
    MediaQuery.xl([
      width(570->px),
    ])
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
