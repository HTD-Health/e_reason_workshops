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

/* Quiz questions below... No peeking! ;) */

let firstQuestion: question = {
  text: "W jakim jezyku napisana jest aplikacja Milion w Rozumie?",
  answers: [
    {id: A, text: "ReasonML"},
    {id: B, text: "JavaScript"},
    {id: C, text: "Elm"},
    {id: D, text: "Dart"},
  ],
  correctAnswerId: A,
};

let prizes: list(prize) = [
  {amount: 500, tier: Normal, question: firstQuestion},
  {
    amount: 1000,
    tier: Guaranteed,
    question: {
      text: "Jaka firma stoi za frameworkiem React.js?",
      answers: [
        {id: A, text: "Google"},
        {id: B, text: "Facebook"},
        {id: C, text: "Microsoft"},
        {id: D, text: "Amazon"},
      ],
      correctAnswerId: B,
    },
  },
  {
    amount: 2000,
    tier: Normal,
    question: {
      text: "\"Camel\" po angielsku to?",
      answers: [
        {id: A, text: {j|Osioł|j}},
        {id: B, text: {j|Koń|j}},
        {id: C, text: {j|Wielbłąd|j}},
        {id: D, text: {j|Muł|j}},
      ],
      correctAnswerId: C,
    },
  },
  {
    amount: 5000,
    tier: Normal,
    question: {
      text: "ReasonML to...?",
      answers: [
        {id: A, text: {j|Zupełnie nowy język programowania|j}},
        {id: B, text: {j|Przyszły standard ES2030|j}},
        {id: C, text: {j|Framework JavaScriptowy|j}},
        {id: D, text: {j|Alternatywny syntax dla OCaml|j}},
      ],
      correctAnswerId: D,
    },
  },
  {
    amount: 10000,
    tier: Normal,
    question: {
      text: {j|Jak nazywa się kompilator ReasonML do JavaScript?|j},
      answers: [
        {id: A, text: {j|Babel|j}},
        {id: B, text: {j|BuckleScript|j}},
        {id: C, text: {j|ghc|j}},
        {id: D, text: {j|gcc|j}},
      ],
      correctAnswerId: B,
    },
  },
  {
    amount: 20000,
    tier: Normal,
    question: {
      text: {j|Jak nazywa się biblioteka standardowa ReasonML?|j},
      answers: [
        {id: A, text: {j|Belt|j}},
        {id: B, text: {j|Loadsh|j}},
        {id: C, text: {j|Ramda|j}},
        {id: D, text: {j|Utils|j}},
      ],
      correctAnswerId: A,
    },
  },
  {
    amount: 40000,
    tier: Guaranteed,
    question: {
      text: "Kto jest pierwszym autorem frameworka React.js?",
      answers: [
        {id: A, text: {j|Dan Abramov|j}},
        {id: B, text: {j|Jordan Walke|j}},
        {id: C, text: {j|Sebastian Markbåge|j}},
        {id: D, text: {j|Mark Zuckerberg|j}},
      ],
      correctAnswerId: B,
    },
  },
  {
    amount: 75000,
    tier: Normal,
    question: {
      text: {j|Ile edycji konferencji Reason-Conf odbyło się dotychczas?|j},
      answers: [
        {id: A, text: {j|1|j}},
        {id: B, text: {j|2|j}},
        {id: C, text: {j|3|j}},
        {id: D, text: {j|4|j}},
      ],
      correctAnswerId: B,
    },
  },
  {
    amount: 125000,
    tier: Normal,
    question: {
      text: {j|W jakim mieście odbyła się konferencja Reason-Conf 2019?|j},
      answers: [
        {id: A, text: {j|Berlin|j}},
        {id: B, text: {j|Nowy Jork|j}},
        {id: C, text: {j|Wiedeń|j}},
        {id: D, text: {j|Warszawa|j}},
      ],
      correctAnswerId: C,
    },
  },
  {
    amount: 250000,
    tier: Normal,
    question: {
      text: {j|Kto stworzył rachunek lambda?|j},
      answers: [
        {id: A, text: {j|Haskell Curry|j}},
        {id: B, text: {j|Ada Lovelace|j}},
        {id: C, text: {j|Alonzo Church|j}},
        {id: D, text: {j|Albert Einstein|j}},
      ],
      correctAnswerId: C,
    },
  },
  {
    amount: 500000,
    tier: Normal,
    question: {
      text: {j|Która z poniższych funkcji nie występuje w ReasonML?|j},
      answers: [
        {id: A, text: {j|Dependent types|j}},
        {id: B, text: {j|Polymorphic variants|j}},
        {id: C, text: {j|Pattern matching|j}},
        {id: D, text: {j|Type inference|j}},
      ],
      correctAnswerId: A,
    },
  },
  {
    amount: 1000000,
    tier: Grand,
    question: {
      text: {j|Czym jest monada?|j},
      answers: [
        {id: A, text: {j|Burrito|j}},
        {id: B, text: {j|Rodzajem funkcji|j}},
        {id: C, text: {j|Gatunkiem wielbłąda|j}},
        {id: D, text: {j|Monoidem w kategorii endofunktorów|j}},
      ],
      correctAnswerId: D,
    },
  },
];
