type tier =
  | Normal
  | Guaranteed
  | Grand;

type state =
  | Past
  | Current
  | Future;

[@react.component]
let make = () => <div> <TODO message="Prize" /> </div>;
