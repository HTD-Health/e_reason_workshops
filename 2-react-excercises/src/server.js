var express = require("express");
var app = express();

var prizes = [
  {
    amount: 500,
    tier: "normal",
    question: {
      text: "W jakim języku napisane jest API aplikacji Milion w Rozumie?",
      correctAnswerId: "B",
      answers: [
        { id: "A", text: "ReasonML" },
        { id: "B", text: "JavaScript" },
        { id: "C", text: "Elm" },
        { id: "D", text: "Dart" }
      ]
    }
  },
  {
    amount: 1000,
    tier: "guaranteed",
    question: {
      text: "Jaka firma stoi za frameworkiem React.js?",
      correctAnswerId: "B",
      answers: [
        { id: "A", text: "Google" },
        { id: "B", text: "Facebook" },
        { id: "C", text: "Microsoft" },
        { id: "D", text: "Amazon" }
      ]
    }
  },
  {
    amount: 2000,
    tier: "normal",
    question: {
      text: '"Camel" po angielsku to?',
      correctAnswerId: "C",
      answers: [
        { id: "A", text: "Osioł" },
        { id: "B", text: "Koń" },
        { id: "C", text: "Wielbłąd" },
        { id: "D", text: "Muł" }
      ]
    }
  },
  {
    amount: 5000,
    tier: "normal",
    question: {
      text: "ReasonML to...?",
      correctAnswerId: "D",
      answers: [
        { id: "A", text: "Zupełnie nowy język programowania" },
        { id: "B", text: "Przyszły standard ES2030" },
        { id: "C", text: "Framework JavaScriptowy" },
        { id: "D", text: "Alternatywny syntax dla OCaml" }
      ]
    }
  },
  {
    amount: 10000,
    tier: "normal",
    question: {
      text: "Jak nazywa się kompilator ReasonML do JavaScript?",
      correctAnswerId: "B",
      answers: [
        { id: "A", text: "Babel" },
        { id: "B", text: "BuckleScript" },
        { id: "C", text: "ghc" },
        { id: "D", text: "gcc" }
      ]
    }
  },
  {
    amount: 20000,
    tier: "normal",
    question: {
      text: "Jak nazywa się biblioteka standardowa ReasonML?",
      correctAnswerId: "A",
      answers: [
        { id: "A", text: "Belt" },
        { id: "B", text: "Loadsh" },
        { id: "C", text: "Ramda" },
        { id: "D", text: "Utils" }
      ]
    }
  },
  {
    amount: 40000,
    tier: "guaranteed",
    question: {
      text: "Kto jest pierwszym autorem frameworka React.js?",
      correctAnswerId: "B",
      answers: [
        { id: "A", text: "Dan Abramov" },
        { id: "B", text: "Jordan Walke" },
        { id: "C", text: "Sebastian Markbåge" },
        { id: "D", text: "Mark Zuckerberg" }
      ]
    }
  },
  {
    amount: 75000,
    tier: "normal",
    question: {
      text: "Ile edycji konferencji Reason-Conf odbyło się dotychczas?",
      correctAnswerId: "B",
      answers: [
        { id: "A", text: "1" },
        { id: "B", text: "2" },
        { id: "C", text: "3" },
        { id: "D", text: "4" }
      ]
    }
  },
  {
    amount: 125000,
    tier: "normal",
    question: {
      text: "W jakim mieście odbyła się konferencja Reason-Conf 2019?",
      correctAnswerId: "C",
      answers: [
        { id: "A", text: "Berlin" },
        { id: "B", text: "Nowy Jork" },
        { id: "C", text: "Wiedeń" },
        { id: "D", text: "Warszawa" }
      ]
    }
  },
  {
    amount: 250000,
    tier: "normal",
    question: {
      text: "Kto stworzył rachunek lambda?",
      correctAnswerId: "C",
      answers: [
        { id: "A", text: "Haskell Curry" },
        { id: "B", text: "Ada Lovelace" },
        { id: "C", text: "Alonzo Church" },
        { id: "D", text: "Albert Einstein" }
      ]
    }
  },
  {
    amount: 500000,
    tier: "normal",
    question: {
      text: "Która z poniższych funkcji nie występuje w ReasonML?",
      correctAnswerId: "A",
      answers: [
        { id: "A", text: "Dependent types" },
        { id: "B", text: "Polymorphic variants" },
        { id: "C", text: "Pattern matching" },
        { id: "D", text: "Type inference" }
      ]
    }
  },
  {
    amount: 1000000,
    tier: "grand",
    question: {
      text: "Czym jest monada?",
      correctAnswerId: "D",
      answers: [
        { id: "A", text: "Burrito" },
        { id: "B", text: "Rodzajem funkcji" },
        { id: "C", text: "Gatunkiem wielbłąda" },
        { id: "D", text: "Monoidem w kategorii endofunktorów" }
      ]
    }
  }
];

app.listen(8001, () => {
  console.log("Server running on http://localhost:8001");

  app.get("/prizes.json", (req, res) => {
    res.header("Access-Control-Allow-Origin", "*");
    setTimeout(function() {
      res.send(prizes);
    }, 3000);
  });
});
