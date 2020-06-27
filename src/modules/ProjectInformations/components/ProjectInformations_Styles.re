open Css;

let list =
  style([
    margin(0->px),
    padding(0->px),
    listStyleType(`none),
    color(white),
    fontFamily(Theme.font),
    fontSize(24->px),
    display(`flex),
    justifyContent(`center),
    alignItems(`center)
  ]);

let divider = style([
  width(8->px),
  height(8->px),
  backgroundColor(Theme.Colors.secondary->hex),
  borderRadius(50.0->pct),
  margin2(~v=0->px, ~h=16->px)
])
