open Exercise;
open Workout;

type state = {
  id: option(int),
  name: string,
  workoutActivities: list(workoutActivity),
  reps,
  setRest: rest,
  setsCount: int,
  selectedExercise: option(exercise),
  resistance: float,
};

type action =
  | UpdateExercise(int)
  | UpdateReps(string)
  | UpdateResistance(string);

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
                <div
                  /* (
                       ReasonReact.string(
                         "Reps" ++ string_of_int(SetGrouping.Count(g)),
                       )
                     ) */
                />
              }
            )
          </div>
        </div>
      </li>,
    workoutActivities,
  )
  |> Belt.List.toArray
  |> ReasonReact.array;

let component = ReasonReact.reducerComponent("BuildWorkout");

let make = (~exercises, _children) => {
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
    setsCount: 4,
    selectedExercise: None,
    resistance: 0.0,
  },
  render: ({state, send}) =>
    <div className="container">
      <div className="row">
        <div className="col">
          <ul className="list-group mb-2 mr-sm-2 ml-sm-2" />
        </div>
        <div className="col"> <BuildSimpleSetGrouping exercises /> </div>
      </div>
    </div>,
};