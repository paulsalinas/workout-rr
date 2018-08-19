open Exercise;
open Workout;

type page =
  | CreateExercise
  | CreateWorkout;

type action =
  | AddExercise(string, int)
  | RemoveExercise(int)
  | UpdatePage(page)
  | AddWorkout(workout);

type state = {
  page,
  exercises: list(exercise),
  currentId: int,
  muscles: list(muscle),
  workouts: list(workout),
};

let routerPush = (path, event) => {
  ReactEventRe.Mouse.preventDefault(event);
  ReasonReact.Router.push("#" ++ path);
};

let component = ReasonReact.reducerComponent("Example");

let make = _children => {
  ...component,
  initialState: () => {
    page: CreateExercise,
    exercises: [{
                  id: 0,
                  muscle: {
                    id: 1,
                    name: "Chest",
                  },
                  name: "test",
                }],
    currentId: 1,
    muscles: [
      {id: 1, name: "Chest"},
      {id: 2, name: "Backup"},
      {id: 3, name: "Quadraceps"},
      {id: 4, name: "Hamstrings"},
      {id: 5, name: "Biceps"},
      {id: 6, name: "Triceps"},
    ],
    workouts: [],
  },
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          switch (url.hash) {
          | "createworkout" => self.send(UpdatePage(CreateWorkout))
          | _ => self.send(UpdatePage(CreateExercise))
          }
        ),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
  reducer: (action, state) =>
    switch (action) {
    | AddWorkout(workout) =>
      ReasonReact.Update({...state, workouts: [workout, ...state.workouts]})
    | UpdatePage(page) => ReasonReact.Update({...state, page})
    | AddExercise(name, selectedMuscleId) =>
      let selectedMuscle =
        Belt.List.getBy(state.muscles, m => m.id == selectedMuscleId);
      switch (selectedMuscle) {
      | None => ReasonReact.NoUpdate
      | Some(m) =>
        ReasonReact.Update({
          ...state,
          exercises: [
            {id: state.currentId, muscle: m, name},
            ...state.exercises,
          ],
          currentId: state.currentId + 1,
        })
      };
    | RemoveExercise(id) =>
      ReasonReact.Update({
        ...state,
        exercises: [],
        /* exercises: List.filter(e => e.id != id, state.exercises), */
      })
    },
  render: ({state, send}) =>
    <div>
      <nav className="navbar navbar-expand-lg navbar-light bg-light">
        <a className="navbar-brand" href="#">
          (ReasonReact.string("Workout"))
        </a>
        (
          ReasonReact.cloneElement(
            <button className="navbar-toggler" />,
            ~props={
              "type": "button",
              "aria-controls": "navbarNew",
              "aria-expanded": "false",
              "aria-label": "Toggle navigation",
              "data-toggle": "collapse",
              "data-target": "#navbarNav",
            },
            [|<span className="navbar-toggler-icon" />|],
          )
        )
        <div className="collapse navbar-collapse" id="navbarNav">
          <ul className="navbar-nav">
            <li className="nav-item active">
              <a className="nav-link" href="#">
                (ReasonReact.string("Home"))
                <span className="sr-only">
                  (ReasonReact.string("(current)"))
                </span>
              </a>
            </li>
            <li className="nav-item">
              <a
                className="nav-link"
                onClick=(routerPush("createworkout"))
                href="#">
                (ReasonReact.string("Build Workout"))
              </a>
            </li>
          </ul>
        </div>
      </nav>
      (
        switch (state.page) {
        | CreateExercise =>
          <CreateExercises
            exercises=state.exercises
            muscles=state.muscles
            addExercise=(
              (name, muscleId) => send(AddExercise(name, muscleId))
            )
            removeExercise=(id => send(RemoveExercise(id)))
          />
        | CreateWorkout => <BuildWorkout exercises=state.exercises />
        }
      )
    </div>,
};