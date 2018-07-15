open Exercise;
open Workout;

/* Build Simple Set Grouping as in one exercise, same tempo, same rest, and same resistance
   for each  set */

type state = {
  reps: LiftingSet.reps,
  setRest: rest,
  setsCount: int,
  selectedExercise: option(int),
  resistance: float,
};

type action =
  | UpdateExercise(int)
  | UpdateReps(string)
  | UpdateResistance(string);

let component = ReasonReact.reducerComponent("BuildSimpleSetGrouping");

let make =
    (
      ~exercises,
      ~addSetGrouping: list(SetGrouping.groupings) => unit,
      _children,
    ) => {
  ...component,
  reducer: (action: action, state: state) =>
    switch (action) {
    | UpdateExercise(id) =>
      ReasonReact.Update({...state, selectedExercise: Some(id)})
    | UpdateReps(text) =>
      ReasonReact.Update({...state, reps: int_of_string(text)})
    | UpdateResistance(text) =>
      ReasonReact.Update({...state, resistance: float_of_string(text)})
    },
  initialState: () => {
    reps: 10,
    setRest: 40,
    setsCount: 4,
    selectedExercise: None,
    resistance: 0.0,
  },
  render: ({state, send}) =>
    <form>
      <div className="form-group">
        <select
          className="form-control mb-2 mr-sm-2"
          onChange=(
            _event =>
              send(
                UpdateExercise(
                  ReactDOMRe.domElementToObj(
                    ReactEventRe.Form.target(_event),
                  )##value,
                ),
              )
          )>
          (
            List.map(
              (e: exercise) =>
                <option
                  key=(string_of_int(e.id)) value=(string_of_int(e.id))>
                  (ReasonReact.string(e.name))
                </option>,
              exercises,
            )
            |> Belt.List.toArray
            |> ReasonReact.array
          )
        </select>
      </div>
      <div className="form-group">
        <label> (ReasonReact.string("Resistance")) </label>
        <input
          className="form-control"
          id="resistanceInput"
          value=(string_of_float(state.resistance))
        />
      </div>
      <div className="form-group">
        <label> (ReasonReact.string("Reps")) </label>
        <input
          className="form-control"
          id="repsInput"
          value=(string_of_int(state.reps))
        />
      </div>
      <div className="form-group">
        <label> (ReasonReact.string("Sets")) </label>
        <input
          className="form-control"
          id="setsInput"
          value=(string_of_int(state.setsCount))
        />
      </div>
      <button _type="button" className="btn btn-primary">
        (ReasonReact.string("Complete Set!"))
      </button>
    </form>,
};