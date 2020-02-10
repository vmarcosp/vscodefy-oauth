
[@react.component]
let make = (~label) => Button_Styles.(
  <button className=button>
    {React.string(label)}
  </button>
)
