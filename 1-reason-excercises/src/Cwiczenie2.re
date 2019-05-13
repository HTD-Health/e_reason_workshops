open Types;

let checkQuestion = (answerId, {correctAnswerId}) => {
  correctAnswerId == answerId;
};

/*
 alternatywna funkcja do sprawdzenia pytania
 (wykorzystująca drugi zestaw przykładowych typów)

 let checkQuestion = (selectedAnswer, question: question) => {
   question.answers
   |> List.exists(answer =>
        switch (answer) {
        | CorrectAnswer(_) => answer == selectedAnswer
        | WrongAnswer(_) => false
        }
      );
 };

 */