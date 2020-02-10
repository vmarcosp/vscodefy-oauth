module Fade = {
  [@bs.module "react-reveal"][@react.component]
  external make: (
    ~children: React.element,
    ~bottom: bool=?,
    ~top: bool=?,
    ~left: bool=?,
    ~right: bool=?,
    ~delay: int=?,
    ~duration: int=?,
    ~cascade: bool=?
  ) => 'b = "Fade";
};
