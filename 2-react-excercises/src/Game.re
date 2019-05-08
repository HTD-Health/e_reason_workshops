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

type wrong = {
  answeredId: Core.answerId,
  correctId: Core.answerId,
};

type answeringState =
  | NotHighlighted
  | Higlighted(Core.answerId)
  | AnsweredCorrect(Core.answerId)
  | AnsweredWrong(wrong);

type state = {
  currentQuestion: Core.question,
  answeringState: answeringState,
};

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
