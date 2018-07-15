open Exercise;

type action =
  | UpdateMuscleName(string)
  | UpdateExerciseName(string);

type state = {
  name: string,
  selectedMuscleId: int,
};

let renderExercise = (exercises: list(exercise), onAdd: int => unit) =>
  List.map(
    (e: exercise) =>
      <li className="list-group-item" key=(string_of_int(e.id))>
        <div className="container">
          <div className="row">
            <div className="col-4"> (ReasonReact.string(e.name)) </div>
            <div className="col-4">
              (ReasonReact.string("Muscle:" ++ " " ++ e.muscle.name))
            </div>
            <div className="col-4">
              <button
                className="btn btn-outline-danger btn-sm"
                onClick=(_event => onAdd(e.id))>
                (ReasonReact.string("Remove"))
              </button>
            </div>
          </div>
        </div>
      </li>,
    exercises,
  )
  |> Belt.List.toArray
  |> ReasonReact.array;

let component = ReasonReact.reducerComponent("CreateExercise");

let make = (~exercises, ~muscles, ~addExercise, ~removeExercise, _children) => {
  ...component,
  reducer: (action, state) =>
    switch (action) {
    | UpdateExerciseName(text) => ReasonReact.Update({...state, name: text})
    | UpdateMuscleName(selectedMuscleId) =>
      ReasonReact.Update({
        ...state,
        selectedMuscleId:
          try (int_of_string(selectedMuscleId)) {
          | _ => 0
          },
      })
    },
  initialState: () => {name: "", selectedMuscleId: 1},
  render: ({state, send}) =>
    <div>
      <div className="card mb-2 mr-sm-2 ml-sm-2">
        <div className="card-body">
          <form className="form-inline">
            <input
              id="exerciseName"
              className="form-control mb-2 mr-sm-2"
              placeholder="Exercise Name"
              value=state.name
              onChange=(
                _event =>
                  send(
                    UpdateExerciseName(
                      ReactDOMRe.domElementToObj(
                        ReactEventRe.Form.target(_event),
                      )##value,
                    ),
                  )
              )
            />
            <select
              className="form-control mb-2 mr-sm-2"
              onChange=(
                _event =>
                  send(
                    UpdateMuscleName(
                      ReactDOMRe.domElementToObj(
                        ReactEventRe.Form.target(_event),
                      )##value,
                    ),
                  )
              )>
              (
                List.map(
                  (m: muscle) =>
                    <option
                      key=(string_of_int(m.id)) value=(string_of_int(m.id))>
                      (ReasonReact.string(m.name))
                    </option>,
                  muscles,
                )
                |> Belt.List.toArray
                |> ReasonReact.array
              )
            </select>
            <button
              _type="button"
              className="btn btn-primary mb-2"
              onClick=(
                _event => addExercise(state.name, state.selectedMuscleId)
              )>
              (ReasonReact.string("Add exercise"))
            </button>
          </form>
        </div>
      </div>
      <div>
        <ul className="list-group mb-2 mr-sm-2 ml-sm-2">
          (renderExercise(exercises, removeExercise))
        </ul>
      </div>
    </div>,
};