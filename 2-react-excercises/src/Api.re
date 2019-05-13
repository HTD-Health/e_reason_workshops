let decodeTier = (json): Core.tier => {
  let value = Json.Decode.string(json);
  switch (value) {
  | "normal" => Normal
  | "guaranteed" => Guaranteed
  | "grand" => Grand
  | _ => failwith("Invalid tier value: " ++ value)
  };
};

let decodeAnswerId = (json): Core.answerId => {
  let value = Json.Decode.string(json);
  switch (value) {
  | "A" => A
  | "B" => B
  | "C" => C
  | "D" => D
  | _ => failwith("Invalid answerId value: " ++ value)
  };
};

let decodeAnswer = (json): Core.answer => {
  {
    id: Json.Decode.field("id", decodeAnswerId, json),
    text: Json.Decode.field("text", Json.Decode.string, json),
  };
};

let decodeQuestion = (json): Core.question => {
  {
    text: Json.Decode.field("text", Json.Decode.string, json),
    answers:
      Json.Decode.field("answers", Json.Decode.list(decodeAnswer), json),
    correctAnswerId:
      Json.Decode.field("correctAnswerId", decodeAnswerId, json),
  };
};

let decodePrize = (json): Core.prize => {
  {
    amount: Json.Decode.field("amount", Json.Decode.int, json),
    tier: Json.Decode.field("tier", decodeTier, json),
    question: Json.Decode.field("question", decodeQuestion, json),
  };
};

let parse = (json: Js.Json.t): list(Core.prize) => {
  Json.Decode.list(decodePrize, json);
};

let encodeTier = (tier: Core.tier) => {
  let value =
    switch (tier) {
    | Normal => "normal"
    | Guaranteed => "guaranteed"
    | Grand => "grand"
    };
  Json.Encode.string(value);
};

let encodeAnswerId = (id: Core.answerId) => {
  let value =
    switch (id) {
    | A => "A"
    | B => "B"
    | C => "C"
    | D => "D"
    };
  Json.Encode.string(value);
};

let encodeAnswer = (answer: Core.answer) => {
  Json.Encode.object_([
    ("id", encodeAnswerId(answer.id)),
    ("text", Json.Encode.string(answer.text)),
  ]);
};

let encodeQuestion = (question: Core.question) => {
  Json.Encode.object_([
    ("text", Json.Encode.string(question.text)),
    ("correctAnswerId", encodeAnswerId(question.correctAnswerId)),
    ("answers", Json.Encode.list(encodeAnswer, question.answers)),
  ]);
};

let encodePrize = (prize: Core.prize) => {
  Json.Encode.object_([
    ("amount", Json.Encode.int(prize.amount)),
    ("tier", encodeTier(prize.tier)),
    ("question", encodeQuestion(prize.question)),
  ]);
};

let encode = (prizes: list(Core.prize)) => {
  Json.Encode.list(encodePrize, prizes);
};
