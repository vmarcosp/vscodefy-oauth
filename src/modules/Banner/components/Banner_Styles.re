open Css;

let container = style([
    flex(`num(3.0)),
    display(`flex),
    flexDirection(`column),
    justifyContent(`center),
    paddingLeft(64->px),
    selector("> h1, > p", [color(white), fontFamily(Theme.font)]),
  ]);

let title = style([
    fontWeight(`bold),
    margin(0->px),
    marginBottom(6->px),
     MediaQuery.md([
      fontSize(48->px)
    ]),
    MediaQuery.lg([
      fontSize(52->px)
    ]),
    MediaQuery.xl([
      fontSize(64->px)
    ])
  ]);

let subtitle = style([
  fontWeight(`num(300)), 
  margin(0->px),
  MediaQuery.md([
    fontSize(22->px)
  ]),
  MediaQuery.lg([
    fontSize(26->px)
  ]),
  MediaQuery.xl([
    fontSize(38->px)
  ])
]);

let buttonContainer = style([marginTop(42->px)]);
