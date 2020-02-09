
module Styles = {
  open Css;
  let container = style([
    width(100.0 -> vw),
    height(100.0 -> vh),
    boxSizing(`borderBox)
  ])
}
