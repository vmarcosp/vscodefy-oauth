let toPx = value => Js.Float.toString(value) ++ "px";
let toMedia = (rule, value) => "(" ++ rule ++ ":" ++ value ++ ")";

type medias =
  | MAX
  | MIN;

let createMedia = (mediaType, value) => {
  let rule =
    switch (mediaType) {
    | MAX => "max-width"
    | MIN => "min-width"
    };

  let mediaQuery = value->toPx |> toMedia(rule);

  Css.media(mediaQuery);
};

let maxWidth = createMedia(MAX);
let minWidth = createMedia(MIN);

let xs = maxWidth(576.0);
let sm = minWidth(576.0);
let md = minWidth(768.0);
let lg = minWidth(992.0);
let xl = minWidth(1200.0);
