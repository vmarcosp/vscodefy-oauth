open ReactReveal

[@react.component]
let make = () => 
  Header_Styles.(
    <div className=container>
      <Fade delay=600 left=true>
        <Logo />
      </Fade>

      <Menu />
    </div>
  )
