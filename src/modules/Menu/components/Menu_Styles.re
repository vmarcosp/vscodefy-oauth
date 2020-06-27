open Css;

let container =
  style([
    display(`flex),
    margin(0->px),
    padding(0->px),
    alignItems(`center),
  ]);

let item =
  style([
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
  ]);

let button =
  style([
    background(`transparent),
    borderStyle(`none),
    padding(0->px),
    color(white),
    fontSize(1.5->rem),
    fontFamily(Theme.font),
    cursor(`pointer),
    outlineStyle(`none)
  ]);
