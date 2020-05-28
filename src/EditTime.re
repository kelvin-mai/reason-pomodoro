open Utils;

[@react.component]
let make = (~phase, ~value, ~onChange) => {
  <div>
    <span> {s(phase)} </span>
    <input
      type_="number"
      onChange={e => e->ReactEvent.Form.target##value |> onChange}
      value={string_of_int(value)}
    />
  </div>;
};