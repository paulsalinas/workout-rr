open Exercise;
open Workout;

type state = {
  reps: int,
  setRest: rest,
  setsCount: int,
  selectedExercise: option(int),
  resistance: float,
  tempo,
};

type action =
  | UpdateExercise(int)
  | UpdateSetCount(string)
  | UpdateReps(string)
  | UpdateResistance(string)
  | UpdateTempo(tempo);

let component = ReasonReact.reducerComponent("BuildSimpleSetGrouping");

let make = (~exercises, _children) => {
  ...component,
  reducer: (action: action, state: state) =>
    switch (action) {
    | UpdateExercise(id) =>
      ReasonReact.Update({...state, selectedExercise: Some(id)})
    | UpdateReps(text) =>
      ReasonReact.Update({...state, reps: int_of_string(text)})
    | UpdateResistance(text) =>
      ReasonReact.Update({...state, resistance: float_of_string(text)})
    | UpdateSetCount(text) =>
      ReasonReact.Update({...state, setsCount: int_of_string(text)})
    | UpdateTempo(tempo) => ReasonReact.Update({...state, tempo})
    },
  initialState: () => {
    reps: 10,
    setRest: 40,
    setsCount: 4,
    selectedExercise: None,
    resistance: 0.0,
    tempo: {
      concentric: 0,
      eccentric: 0,
      peak: 0,
      bottom: 0,
    },
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
          onChange=(
            _event =>
              send(
                UpdateResistance(
                  ReactDOMRe.domElementToObj(
                    ReactEventRe.Form.target(_event),
                  )##value,
                ),
              )
          )
        />
      </div>
      <div className="form-group">
        <label> (ReasonReact.string("Reps")) </label>
        <input
          className="form-control"
          id="repsInput"
          value=(string_of_int(state.reps))
          onChange=(
            _event =>
              send(
                UpdateReps(
                  ReactDOMRe.domElementToObj(
                    ReactEventRe.Form.target(_event),
                  )##value,
                ),
              )
          )
        />
      </div>
      <div className="form-group">
        <label> (ReasonReact.string("Sets")) </label>
        <input
          className="form-control"
          id="setsInput"
          onChange=(
            _event =>
              send(
                UpdateSetCount(
                  ReactDOMRe.domElementToObj(
                    ReactEventRe.Form.target(_event),
                  )##value,
                ),
              )
          )
          value=(string_of_int(state.setsCount))
        />
      </div>
      <div className="form-group">
        <label> (ReasonReact.string("Tempo")) </label>
        <div className="row">
          <div>
            <input
              className="form-control"
              id="setsPeak"
              type_="number"
              value=(string_of_int(state.tempo.peak))
              onChange=(
                _event =>
                  send(
                    UpdateTempo({
                      ...state.tempo,
                      peak:
                        int_of_string(
                          ReactDOMRe.domElementToObj(
                            ReactEventRe.Form.target(_event),
                          )##value,
                        ),
                    }),
                  )
              )
            />
          </div>
          <div className="col-4">
            <input
              className="form-control"
              id="setsConcentric"
              type_="number"
              value=(string_of_int(state.tempo.concentric))
              onChange=(
                _event =>
                  send(
                    UpdateTempo({
                      ...state.tempo,
                      concentric:
                        int_of_string(
                          ReactDOMRe.domElementToObj(
                            ReactEventRe.Form.target(_event),
                          )##value,
                        ),
                    }),
                  )
              )
            />
          </div>
          <div className="col-4">
            <input
              className="form-control"
              id="setsEccentric"
              type_="number"
              value=(string_of_int(state.tempo.eccentric))
              onChange=(
                _event =>
                  send(
                    UpdateTempo({
                      ...state.tempo,
                      eccentric:
                        int_of_string(
                          ReactDOMRe.domElementToObj(
                            ReactEventRe.Form.target(_event),
                          )##value,
                        ),
                    }),
                  )
              )
            />
          </div>
          <div className="col-4">
            <input
              className="form-control"
              id="setsBottom"
              type_="number"
              value=(string_of_int(state.tempo.bottom))
              onChange=(
                _event =>
                  send(
                    UpdateTempo({
                      ...state.tempo,
                      bottom:
                        int_of_string(
                          ReactDOMRe.domElementToObj(
                            ReactEventRe.Form.target(_event),
                          )##value,
                        ),
                    }),
                  )
              )
            />
          </div>
        </div>
      </div>
      <button _type="button" className="btn btn-primary">
        (ReasonReact.string("Complete Set!"))
      </button>
    </form>,
};