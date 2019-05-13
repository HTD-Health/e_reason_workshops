import React from "react";
import ReactDOM from "react-dom";

function MyProject() {
  return (
    <div className="external-project">
      <h1>Mój Projekt</h1>
      <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>

      <div className="todo">
        <em>Tutaj wyrenderuj komponent Game</em>
      </div>

      <footer>Copyright &copy; 2019</footer>
    </div>
  );
}

ReactDOM.render(<MyProject />, document.getElementById("root"));
