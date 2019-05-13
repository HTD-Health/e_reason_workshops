/*
 Normal:
 <div class="prize">500 PLN</div>

 Past:
 <div class="prize prize-past">500 PLN</div>

 Current:
 <div class="prize prize-current">2000 PLN</div>

 Guaranteed:
 <div class="prize prize-guaranteed">1000 PLN</div>

 Grand:
 <div class="prize prize-grand">1000000 PLN</div>
 */

type state =
  | Past
  | Current
  | Future;

[@react.component]
let make = (~amount: int, ~state: state, ~tier: Core.tier) => {
  let stateClassName =
    switch (state) {
    | Past => "prize-past"
    | Current => "prize-current"
    | Future => ""
    };
  let tierClassName =
    switch (tier) {
    | Normal => ""
    | Guaranteed => "prize-guaranteed"
    | Grand => "prize-grand"
    };
  let className = "prize " ++ stateClassName ++ " " ++ tierClassName;
  <div className> {React.string(string_of_int(amount) ++ " PLN")} </div>;
};
