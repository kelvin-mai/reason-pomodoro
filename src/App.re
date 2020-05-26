open Utils;
open State;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let timerId = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timerId));
  });

  <div>
    <Timer seconds={state.seconds} />
    {state.isTicking
       ? <button onClick={_event => dispatch(Stop)}> {s("STOP")} </button>
       : <>
           <button label="START" onClick={_event => dispatch(Start)}>
             {s("START")}
           </button>
           <button label="RESET" onClick={_event => dispatch(Reset)}>
             {s("RESET")}
           </button>
         </>}
  </div>;
};