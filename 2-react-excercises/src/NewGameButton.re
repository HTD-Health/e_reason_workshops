/*
   <button type="button">Nowa gra</button>
 */

[@react.component]
let make = (~onClick) => {
  <button type_="button" onClick>{React.string("Nowa gra")}</button>
};
