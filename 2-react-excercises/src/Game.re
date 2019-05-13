let firstQuestion = Core.firstQuestion;

type state = {
  prizes: list(Core.prize),
  currentPrizeIndex: int,
  answeringState: Core.answeringState,
};

type action =
  | NewGame
  | SelectAnswer(Core.answerId);

let reducer = (state: state, action: action) => {
  let currentPrize = Belt.List.getExn(state.prizes, state.currentPrizeIndex);

  switch (action) {
  | NewGame => {
      prizes: Core.prizes,
      currentPrizeIndex: 0,
      answeringState: NotHighlighted,
    }
  | SelectAnswer(answerId) =>
    switch (state.answeringState) {
    | NotHighlighted => {...state, answeringState: Highlighted(answerId)}
    | Highlighted(highlightedAnswerId) when highlightedAnswerId === answerId =>
      if (answerId === currentPrize.question.correctAnswerId) {
        {...state, answeringState: AnsweredCorrect(answerId)};
      } else {
        {
          ...state,
          answeringState:
            AnsweredWrong({
              answeredId: answerId,
              correctId: currentPrize.question.correctAnswerId,
            }),
        };
      }
    | Highlighted(_) => {...state, answeringState: Highlighted(answerId)}
    | AnsweredCorrect(_) => {
        ...state,
        currentPrizeIndex: state.currentPrizeIndex + 1,
        answeringState: NotHighlighted /* TODO: next question */
      }
    | AnsweredWrong(_) => state
    }
  };
};

let initialState = {
  prizes: Core.prizes,
  currentPrizeIndex: 0,
  answeringState: NotHighlighted,
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let answeringState = state.answeringState;
  let currentPrize = Belt.List.getExn(state.prizes, state.currentPrizeIndex);

  React.useEffect0(() => {
    let _ =
      Fetch.fetch("http://localhost:8001/prizes.json")
      |> Js.Promise.then_(Fetch.Response.json)
      |> Js.Promise.then_(json => {
           Js.log2("Received json: ", json);
           let prizes = Api.parse(json);
           Belt.List.forEach(
             prizes,
             prize => {
               let tier =
                 switch (prize.tier) {
                 | Normal => "normal"
                 | Guaranteed => "guaranteed"
                 | Grand => "grand"
                 };

               Js.log3("Prize: ", prize.amount, tier);
             },
           );
           /* TODO: dispatch an action to load prizes into state */
           Js.Promise.resolve();
         })
      |> Js.Promise.catch(error => {
           Js.log2("Error with parsing data: ", error);
           Js.Promise.resolve();
         });
    None;
  });

  <div className="root">
    <div className="left-column">
      <Logo />
      <Question
        question={currentPrize.question}
        answeringState
        onAnswerClick={id => dispatch(SelectAnswer(id))}
      />
    </div>
    {switch (state.answeringState) {
     | AnsweredCorrect(_) =>
       <Confetti recycle=false numberOfPieces=100 gravity=0.5 />
     | _ => React.null
     }}
    <div className="right-column">
      <NewGameButton onClick={_ => dispatch(NewGame)} />
      <PrizeTrack
        prizes={state.prizes}
        currentPrizeIndex={state.currentPrizeIndex}
      />
    </div>
  </div>;
};
