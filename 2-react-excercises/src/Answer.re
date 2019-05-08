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

   Selected:
   <div class="answer answer-selected">
     B. Treść odpowiedzi
   </div>

   Correct:
   <div class="answer answer-correct">
     C. Treść odpowiedzi
   </div>

   Wrong:
   <div class="answer answer-wrong">
     D. Treść odpowiedzi
   </div>

 */
[@react.component]
let make = () => {
  <div> <TODO message="Answer" /> </div>;
};
