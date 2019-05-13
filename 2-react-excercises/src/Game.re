let firstQuestion: Core.question = {
  text: "W jakim jezyku napisana jest aplikacja Milion w Rozumie?",
  answers: [
    {id: A, text: "ReasonML"},
    {id: B, text: "JavaScript"},
    {id: C, text: "Elm"},
    {id: D, text: "Dart"},
  ],
  correctAnswerId: A,
};

let firstPrize: Core.prize = {
  amount: 500,
  tier: Normal,
  question: firstQuestion,
};

let prizes = [firstPrize];

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
  prizes: prizes,
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
