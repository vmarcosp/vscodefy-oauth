open Css;

let button = style([
  backgroundColor(Theme.Colors.primary->hex),
  color(white),
  borderRadius(4->px),
  height(60->px),
  borderStyle(`none),
  fontSize(16->px),
  fontWeight(`num(600)),
  padding2(~v=0->px, ~h=32->px),
  boxSizing(`borderBox),
  cursor(`pointer)
])
