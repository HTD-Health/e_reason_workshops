var express = require("express");
var app = express();

var prizes = [{
  amount: 500,
  tier: "normal",
  question: {
    text: "[API QUESTION] Hello world",
    correctAnswerId: "A",
    answers: [
      { id: "A", text: "Answer A" },
      { id: "B", text: "Answer B" },
      { id: "C", text: "Answer C" },
      { id: "D", text: "Answer D" }
    ]
  }
}];

app.listen(8001, () => {
  console.log("Server running on http://localhost:8001");

  app.get("/prizes.json", (req, res) => {
    res.header("Access-Control-Allow-Origin", "*");
    setTimeout((function() {res.send(prizes)}), 3000);
  });
});
