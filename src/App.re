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
    <Header seconds={state.seconds} currentPhase={state.currentPhase} />
    <Timer seconds={state.seconds} />
    <div>
      <button label="RESET" onClick={_ => dispatch(Reset)}>
        <span className="fas fa-stop" />
      </button>
      {state.isTicking
         ? <button onClick={_ => dispatch(Stop)}>
             <span className="fas fa-pause" />
           </button>
         : <button label="START" onClick={_ => dispatch(Start)}>
             <span className="fas fa-play" />
           </button>}
    </div>
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