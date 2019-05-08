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

type state = {
  currentPrize: Core.prize,
  answeringState: Core.answeringState,
};

type action =
  | SelectAnswer(Core.answerId);

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
