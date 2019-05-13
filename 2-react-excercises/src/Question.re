/*
    <div class="question">
      <QuestionText />
      <div class="grid">
        <Answer />
        <Answer />
        <Answer />
        <Answer />
      </div>
    </div>
 */

[@react.component]
let make =
    (
      ~question: Core.question,
      ~answeringState: Core.answeringState,
      ~onAnswerClick: Core.answerId => unit,
    ) => {
  <div className="question">
    <QuestionText text={question.text} />
    <div className="grid">
      {React.array(
         Belt.List.toArray(
           Belt.List.map(
             question.answers,
             answer => {
               let state: Answer.state =
                 switch (answeringState) {
                 | NotHighlighted => Initial
                 | Highlighted(highlightedId) when highlightedId == answer.id =>
                   Highlighted
                 | Highlighted(_) => Initial
                 | AnsweredCorrect(correctId)
                 | AnsweredWrong({correctId}) when correctId == answer.id =>
                   Correct
                 | AnsweredWrong({answeredId}) when answeredId == answer.id =>
                   Wrong
                 | AnsweredCorrect(_)
                 | AnsweredWrong(_) => Initial
                 };
               <Answer
                 id={answer.id}
                 text={answer.text}
                 key={answer.text}
                 onClick={_ => onAnswerClick(answer.id)}
                 state
               />;
             },
           ),
         ),
       )}
    </div>
  </div>;
};
