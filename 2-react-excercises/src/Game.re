[@react.component]
let make = () =>
  <div>
    <div className="left-column">
      <Logo />
      <Question />
    </div>
    <div className="right-column">
      <NewGameButton />
      <PrizeTrack />
    </div>
  </div>;
