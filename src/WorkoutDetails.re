open Exercise;

open Workout;

type state = {
  id: option(int),
  name: string,
  workoutActivities: list(workoutActivity),
  reps: LiftingSet.reps,
  setRest: rest,
  selectedExercise: option(exercise),
  resistance: float,
};

type action =
  | NoAction;

let renderExerciseSelectList = (exercises: list(Exercise.exercise)) =>
  <select className="form-control mb-2 mr-sm-2">
    (
      List.map(
        (e: exercise) =>
          <option key=(string_of_int(e.id)) value=(string_of_int(e.id))>
            (ReasonReact.string(e.name))
          </option>,
        exercises,
      )
      |> Belt.List.toArray
      |> ReasonReact.array
    )
  </select>;

let renderWorkoutActivities = (workoutActivities: list(workoutActivity)) =>
  List.map(
    (w: workoutActivity) =>
      <li className="list-group-item">
        <div className="container">
          <div className="row">
            (
              switch (w) {
              | Rest(duration) =>
                <div className="col-4">
                  (
                    ReasonReact.string(
                      "Muscle:" ++ " " ++ string_of_int(duration),
                    )
                  )
                </div>
              | Grouping(g) =>
                <div>
                  (
                    ReasonReact.string(
                      "Reps" ++ string_of_int(SetGrouping.liftingSetCount(g)),
                    )
                  )
                </div>
              }
            )
          </div>
        </div>
      </li>,
    workoutActivities,
  )
  |> Belt.List.toArray
  |> ReasonReact.array;

let component = ReasonReact.reducerComponent("WorkoutDetails");

let make = (~exercises, ~name, ~workoutActivities, ~exercises, _children) => {
  ...component,
  reducer: (action: action, state: state) =>
    switch (action) {
    | _ => ReasonReact.NoUpdate
    },
  initialState: () => {
    id: None,
    name: "",
    workoutActivities: [],
    reps: 10,
    setRest: 40,
    selectedExercise: None,
    resistance: 0.0,
  },
  render: _ =>
    <div className="container">
      <div className="row">
        <div className="col-md">
          <ul className="list-group mb-2 mr-sm-2 ml-sm-2">
            <li className="list-group-item" />
          </ul>
        </div>
        <div className="col-sm" />
        <div className="col-sm" />
      </div>
    </div>,
};