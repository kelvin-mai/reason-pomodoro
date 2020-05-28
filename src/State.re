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
  | Tick
  | SetTime(phase, int);

let initialState = {
  isTicking: false,
  seconds: 30,
  workTime: 25,
  playTime: 5,
  currentPhase: Work,
};

let reducer = (state, action) =>
  switch (action) {
  | Start => {...state, isTicking: true}
  | Stop => {...state, isTicking: false}
  | Tick =>
    state.isTicking && state.seconds > 0
      ? {...state, seconds: state.seconds - 1} : state
  | Reset =>
    switch (state.currentPhase) {
    | Work => {...state, seconds: state.workTime * 60}
    | Play => {...state, seconds: state.playTime * 60}
    }
  | SetTime(p, i) =>
    switch (p) {
    | Work => {...state, workTime: i}
    | Play => {...state, playTime: i}
    }
  };