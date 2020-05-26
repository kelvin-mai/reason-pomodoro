type phase =
  | Work
  | Play;

let togglePhase = phase =>
  switch (phase) {
  | Work => Play
  | Play => Work
  };

type state = {
  seconds: int,
  isTicking: bool,
  workTime: int,
  playTime: int,
  currentPhase: phase,
};

type action =
  | Start
  | Stop
  | Reset
  | Tick;

let initialState = {
  isTicking: false,
  seconds: 30,
  workTime: 25 * 60,
  playTime: 5 * 60,
  currentPhase: Work,
};

let reducer = (state, action) =>
  switch (action) {
  | Start => {...state, isTicking: true}
  | Stop => {...state, isTicking: false}
  | Reset => {...state, seconds: 30}
  | Tick =>
    state.isTicking && state.seconds > 0
      ? {...state, seconds: state.seconds - 1}
      : {...state, currentPhase: togglePhase(state.currentPhase)}
  };