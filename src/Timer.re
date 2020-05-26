open Utils;

[@react.component]
let make = (~seconds) => {
  <div className="base-timer">
    <svg className="base-timer__svg" viewBox="0 0 100 100">
      <g className="base-timer__circle">
        <circle className="base-timer__path-elapsed" cx="50" cy="50" r="45" />
      </g>
    </svg>
    <span className="base-timer__label"> {seconds |> formatTime |> s} </span>
  </div>;
};