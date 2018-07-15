open Workout;

let component = ReasonReact.statelessComponent("BuildWorkout");

type state = {workouts: list(workout)};

let make = _children => {
  ...component,
  render: _ => <div> (ReasonReact.string("hello routing!")) </div>,
};