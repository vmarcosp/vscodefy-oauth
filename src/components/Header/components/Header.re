open ReactReveal

[@react.component]
let make = () => 
  Header_Styles.(
    <div className=container>
      <Fade left=true>
        <Logo />
      </Fade>
      
      <Menu />
    </div>
  )
