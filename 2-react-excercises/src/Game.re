let firstQuestion = Core.firstQuestion;

type state = {
  prizes: list(Core.prize),
  currentPrizeIndex: int,
  answeringState: Core.answeringState,
};

type action =
  | SelectAnswer(Core.answerId);

let reducer = (state: state, action: action) => {
  switch (action) {
  | SelectAnswer(_) => state /* TODO */
  };
};

let initialState = {
  prizes: Core.prizes,
  currentPrizeIndex: 0,
  answeringState: NotHighlighted,
};

[@react.component]
let make = () => {
  /*
  let (state, dispatch) = React.useReducer(reducer, initialState);
  */

  <div className="root">
    <div className="left-column">
      <Logo />
      <Question />
    </div>
    <div className="right-column">
      <NewGameButton />
      <PrizeTrack />
    </div>
  </div>;
};
