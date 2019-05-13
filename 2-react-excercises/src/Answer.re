type state =
  | Initial
  | Highlighted
  | Correct
  | Wrong;

/*
   Initial:
   <div class="answer">
     A. Treść odpowiedzi
   </div>

   Highlighted:
   <div class="answer highlighted">
     B. Treść odpowiedzi
   </div>

   Correct:
   <div class="answer correct">
     C. Treść odpowiedzi
   </div>

   Wrong:
   <div class="answer wrong">
     D. Treść odpowiedzi
   </div>

 */
[@react.component]
let make =
    (~id: Core.answerId, ~text: string, ~onClick: unit => unit, ~state: state) => {
  let id =
    switch (id) {
    | A => "A"
    | B => "B"
    | C => "C"
    | D => "D"
    };
  let className =
    switch (state) {
    | Initial => "answer"
    | Highlighted => "answer highlighted"
    | Correct => "answer correct"
    | Wrong => "answer wrong"
    };
  <div className onClick={_ => onClick()}>
    {React.string(id ++ ". " ++ text)}
  </div>;
};
