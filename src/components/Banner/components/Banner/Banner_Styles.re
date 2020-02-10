open Css;

let container = style([
  flex(`num(3.0)),
  display(`flex),
  flexDirection(`column),
  justifyContent(`center),
  paddingLeft(64->px),
  selector("> h1, > p", [
    color(white),
    fontFamily(Theme.font)
  ]),
  selector("h1", [
    fontSize(64->px),
    fontWeight(`bold),
    margin(0->px),
    marginBottom(24->px)
  ]),
  selector("p", [
    fontSize(38->px),
    fontWeight(`num(300)),
    margin(0->px)
  ])
])
