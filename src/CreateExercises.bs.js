// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function renderExercise(exercises, onAdd) {
  return Belt_List.toArray(List.map((function (e) {
                    return React.createElement("li", {
                                key: String(e[/* id */0]),
                                className: "list-group-item"
                              }, React.createElement("div", {
                                    className: "container"
                                  }, React.createElement("div", {
                                        className: "row"
                                      }, React.createElement("div", {
                                            className: "col-4"
                                          }, e[/* name */1]), React.createElement("div", {
                                            className: "col-4"
                                          }, "Muscle: " + e[/* muscle */2][/* name */1]), React.createElement("div", {
                                            className: "col-4"
                                          }, React.createElement("button", {
                                                className: "btn btn-outline-danger btn-sm",
                                                onClick: (function () {
                                                    return Curry._1(onAdd, e[/* id */0]);
                                                  })
                                              }, "Remove")))));
                  }), exercises));
}

var component = ReasonReact.reducerComponent("CreateExercise");

function make(exercises, muscles, addExercise, removeExercise, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              return React.createElement("div", undefined, React.createElement("div", {
                              className: "card mb-2 mr-sm-2 ml-sm-2"
                            }, React.createElement("div", {
                                  className: "card-body"
                                }, React.createElement("form", {
                                      className: "form-inline"
                                    }, React.createElement("input", {
                                          className: "form-control mb-2 mr-sm-2",
                                          id: "exerciseName",
                                          placeholder: "Exercise Name",
                                          value: state[/* name */0],
                                          onChange: (function (_event) {
                                              return Curry._1(send, /* UpdateExerciseName */Block.__(1, [_event.target.value]));
                                            })
                                        }), React.createElement("select", {
                                          className: "form-control mb-2 mr-sm-2",
                                          onChange: (function (_event) {
                                              return Curry._1(send, /* UpdateMuscleName */Block.__(0, [_event.target.value]));
                                            })
                                        }, Belt_List.toArray(List.map((function (m) {
                                                    return React.createElement("option", {
                                                                key: String(m[/* id */0]),
                                                                value: String(m[/* id */0])
                                                              }, m[/* name */1]);
                                                  }), muscles))), React.createElement("button", {
                                          className: "btn btn-primary mb-2",
                                          type: "button",
                                          onClick: (function () {
                                              return Curry._2(addExercise, state[/* name */0], state[/* selectedMuscleId */1]);
                                            })
                                        }, "Add exercise")))), React.createElement("div", undefined, React.createElement("ul", {
                                  className: "list-group mb-2 mr-sm-2 ml-sm-2"
                                }, renderExercise(exercises, removeExercise))));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* name */"",
                      /* selectedMuscleId */1
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                return /* Update */Block.__(0, [/* record */[
                            /* name */action[0],
                            /* selectedMuscleId */state[/* selectedMuscleId */1]
                          ]]);
              } else {
                var tmp;
                try {
                  tmp = Caml_format.caml_int_of_string(action[0]);
                }
                catch (exn){
                  tmp = 0;
                }
                return /* Update */Block.__(0, [/* record */[
                            /* name */state[/* name */0],
                            /* selectedMuscleId */tmp
                          ]]);
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.renderExercise = renderExercise;
exports.component = component;
exports.make = make;
/* component Not a pure module */
