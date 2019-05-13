/*
    <div class="list">
      <Prize />
      <Prize />
    </div>
 */

[@react.component]
let make = (~prizes: list(Core.prize), ~currentPrizeIndex) => {
  let elements =
    prizes
    ->Belt.List.mapWithIndex((idx, prize) => {
        let state: Prize.state =
          if (idx < currentPrizeIndex) {
            Past;
          } else if (idx == currentPrizeIndex) {
            Current;
          } else {
            Future;
          };
        <Prize
          key={string_of_int(idx)}
          amount={prize.amount}
          tier={prize.tier}
          state
        />;
      })
    ->Belt.List.reverse
    ->Belt.List.toArray
    ->React.array;
  <div className="list"> elements </div>;
};
