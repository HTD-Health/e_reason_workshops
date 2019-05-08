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

type tier =
  | Normal
  | Guaranteed
  | Grand;

type prize = {
  amount: int,
  tier: tier,
  question: question,
};

type wrong = {
  answeredId: answerId,
  correctId: answerId,
};

type answeringState =
  | NotHighlighted
  | Highlighted(answerId)
  | AnsweredCorrect(answerId)
  | AnsweredWrong(wrong);
