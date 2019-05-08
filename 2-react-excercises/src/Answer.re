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
let make = () => {
  <div> <TODO message="Answer" /> </div>;
};
