open Css

let container = style([
  display(`flex),
  margin(0->px),
  padding(0->px),
  alignItems(`center),
  selector("li", [
    // border(1->px, `solid, red),
    listStyleType(`none),
    display(`flex),
    alignItems(`center),
    padding2(~v=0->px, ~h=32->px),
    height(`auto),
    margin(0->px),
    fontSize(22->px),
    color(white),
    fontWeight(`num(500)),
    fontFamily(Theme.font),
    selector("a", [
      display(`flex),
      alignItems(`center)
    ])
  ])
])
