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
