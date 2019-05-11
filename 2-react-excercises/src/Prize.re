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
let make = () => <div> <TODO message="Prize" /> </div>;
