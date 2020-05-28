open Utils;
open State;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let timerId = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timerId));
  });

  Js.log(state);

  <div>
    <h1>
      {s("Time to ")}
      <span>
        {switch (state.currentPhase) {
         | Work => s("work")
         | Play => s("play")
         }}
      </span>
    </h1>
    <Timer seconds={state.seconds} />
    {state.isTicking
       ? <button onClick={_ => dispatch(Stop)}> {s("STOP")} </button>
       : <>
           <button label="START" onClick={_ => dispatch(Start)}>
             {s("START")}
           </button>
           <button label="RESET" onClick={_ => dispatch(Reset)}>
             {s("RESET")}
           </button>
         </>}
    <EditTime
      phase="Work"
      onChange={e => dispatch(SetTime(Work, e))}
      value={state.workTime}
    />
    <EditTime
      phase="Break"
      onChange={e => dispatch(SetTime(Play, e))}
      value={state.playTime}
    />
  </div>;
};