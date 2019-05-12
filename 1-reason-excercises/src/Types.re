type answerId =
  | A
  | B
  | C
  | D;

type answer = {
  id: answerId,
  text: string,
};

type question = {
  text: string,
  answers: list(answer),
  correctAnswerId: answerId,
};

/*

  inne przykładowe typy:

 type answer =
   | CorrectAnswer(string, int)
   | WrongAnswer(string);

 type question = {
   text: string,
   answers: list(answer),
 };

 */