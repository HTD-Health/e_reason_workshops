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
let make = () => {
  <TODO message="Question">
    <QuestionText />
    <div> <Answer /> <Answer /> <Answer /> <Answer /> </div>
  </TODO>;
};
