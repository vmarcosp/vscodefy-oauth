open Css;
open StepsTypes;

let getCircleColor =
  fun
  | Active
  | Done => Theme.Colors.secondary->hex
  | Inactive => "dbdbdb"->hex;

let container =
  style([
    display(`flex),
    flexDirection(column),
    alignItems(`center),
    justifyContent(`center),
  ]);

let circle = status =>
  style([
    background(getCircleColor(status)), //
    borderRadius(50.0->pct),
    boxSizing(`borderBox),
    width(52->px),
    height(52->px),
    display(`flex),
    alignItems(`center),
    justifyContent(`center),
  ]);

let border =
  style([
    display(`flex),
    boxSizing(`borderBox),
    alignItems(`center),
    justifyContent(`center),
    background(transparent),
    width(42->px),
    height(42->px),
    border(1->px, `solid, white),
    borderRadius(50.0->pct),
    color(white),
    fontFamily(Theme.font),
    fontSize(1.375->rem),
  ]);

let divider = (~color, ~display as displayValue) =>
  style([
    height(50->px),
    boxSizing(`borderBox),
    width(2->px),
    background(color),
    display(displayValue),
  ]);

let dividerBottom = (step, total, status) =>
  divider(
    ~display=step == total ? `none : `flex,
    ~color=
      switch (status) {
      | Done => Theme.Colors.secondary->hex
      | Inactive
      | Active => "dbdbdb"->hex
      },
  );

let dividerTop = (step, status) =>
  divider(
    ~display=step == 1 ? `none : `flex,
    ~color=
      switch (status) {
      | Done
      | Active => Theme.Colors.secondary->hex
      | Inactive => "dbdbdb"->hex
      },
  );
