open Utils;
open State;

[@react.component]
let make = (~seconds, ~currentPhase) => {
  let label =
    seconds > 0
      ? switch (currentPhase) {
        | Work => "Time to work"
        | Play => "Break time"
        }
      : (
        switch (currentPhase) {
        | Work => "Ready for a break?"
        | Play => "Ready to start working?"
        }
      );
  <h1 onClick={seconds == 0 ? _ => Js.log("dispatch") : (_ => ())}>
    {s(label)}
  </h1>;
};