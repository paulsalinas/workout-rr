// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var BuildWorkout$ReactTemplate = require("./BuildWorkouts/BuildWorkout.bs.js");
var CreateExercises$ReactTemplate = require("./CreateExercises.bs.js");

function routerPush(path, $$event) {
  $$event.preventDefault();
  return ReasonReact.Router[/* push */0]("#" + path);
}

var component = ReasonReact.reducerComponent("Example");

function make() {
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
              var match = state[/* page */0];
              return React.createElement("div", undefined, React.createElement("nav", {
                              className: "navbar navbar-expand-lg navbar-light bg-light"
                            }, React.createElement("a", {
                                  className: "navbar-brand",
                                  href: "#"
                                }, "Workout"), React.cloneElement(React.createElement("button", {
                                      className: "navbar-toggler"
                                    }), {
                                  type: "button",
                                  "aria-controls": "navbarNew",
                                  "aria-expanded": "false",
                                  "aria-label": "Toggle navigation",
                                  "data-toggle": "collapse",
                                  "data-target": "#navbarNav"
                                }, React.createElement("span", {
                                      className: "navbar-toggler-icon"
                                    })), React.createElement("div", {
                                  className: "collapse navbar-collapse",
                                  id: "navbarNav"
                                }, React.createElement("ul", {
                                      className: "navbar-nav"
                                    }, React.createElement("li", {
                                          className: "nav-item active"
                                        }, React.createElement("a", {
                                              className: "nav-link",
                                              href: "#"
                                            }, "Home", React.createElement("span", {
                                                  className: "sr-only"
                                                }, "(current)"))), React.createElement("li", {
                                          className: "nav-item"
                                        }, React.createElement("a", {
                                              className: "nav-link",
                                              href: "#",
                                              onClick: (function (param) {
                                                  return routerPush("createworkout", param);
                                                })
                                            }, "Build Workout"))))), match ? ReasonReact.element(undefined, undefined, BuildWorkout$ReactTemplate.make(state[/* exercises */1], /* array */[])) : ReasonReact.element(undefined, undefined, CreateExercises$ReactTemplate.make(state[/* exercises */1], state[/* muscles */3], (function (name, muscleId) {
                                      return Curry._1(send, /* AddExercise */Block.__(0, [
                                                    name,
                                                    muscleId
                                                  ]));
                                    }), (function (id) {
                                      return Curry._1(send, /* RemoveExercise */Block.__(1, [id]));
                                    }), /* array */[])));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* page : CreateExercise */0,
                      /* exercises : :: */[
                        /* record */[
                          /* id */0,
                          /* name */"test",
                          /* muscle : record */[
                            /* id */1,
                            /* name */"Chest"
                          ]
                        ],
                        /* [] */0
                      ],
                      /* currentId */1,
                      /* muscles : :: */[
                        /* record */[
                          /* id */1,
                          /* name */"Chest"
                        ],
                        /* :: */[
                          /* record */[
                            /* id */2,
                            /* name */"Backup"
                          ],
                          /* :: */[
                            /* record */[
                              /* id */3,
                              /* name */"Quadraceps"
                            ],
                            /* :: */[
                              /* record */[
                                /* id */4,
                                /* name */"Hamstrings"
                              ],
                              /* :: */[
                                /* record */[
                                  /* id */5,
                                  /* name */"Biceps"
                                ],
                                /* :: */[
                                  /* record */[
                                    /* id */6,
                                    /* name */"Triceps"
                                  ],
                                  /* [] */0
                                ]
                              ]
                            ]
                          ]
                        ]
                      ],
                      /* workouts : [] */0
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              switch (action.tag | 0) {
                case 0 : 
                    var selectedMuscleId = action[1];
                    var selectedMuscle = Belt_List.getBy(state[/* muscles */3], (function (m) {
                            return m[/* id */0] === selectedMuscleId;
                          }));
                    if (selectedMuscle !== undefined) {
                      return /* Update */Block.__(0, [/* record */[
                                  /* page */state[/* page */0],
                                  /* exercises : :: */[
                                    /* record */[
                                      /* id */state[/* currentId */2],
                                      /* name */action[0],
                                      /* muscle */selectedMuscle
                                    ],
                                    state[/* exercises */1]
                                  ],
                                  /* currentId */state[/* currentId */2] + 1 | 0,
                                  /* muscles */state[/* muscles */3],
                                  /* workouts */state[/* workouts */4]
                                ]]);
                    } else {
                      return /* NoUpdate */0;
                    }
                case 1 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* page */state[/* page */0],
                                /* exercises : [] */0,
                                /* currentId */state[/* currentId */2],
                                /* muscles */state[/* muscles */3],
                                /* workouts */state[/* workouts */4]
                              ]]);
                case 2 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* page */action[0],
                                /* exercises */state[/* exercises */1],
                                /* currentId */state[/* currentId */2],
                                /* muscles */state[/* muscles */3],
                                /* workouts */state[/* workouts */4]
                              ]]);
                case 3 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* page */state[/* page */0],
                                /* exercises */state[/* exercises */1],
                                /* currentId */state[/* currentId */2],
                                /* muscles */state[/* muscles */3],
                                /* workouts : :: */[
                                  action[0],
                                  state[/* workouts */4]
                                ]
                              ]]);
                
              }
            }),
          /* subscriptions */(function (self) {
              return /* :: */[
                      /* Sub */[
                        (function () {
                            return ReasonReact.Router[/* watchUrl */1]((function (url) {
                                          var match = url[/* hash */1];
                                          if (match === "createworkout") {
                                            return Curry._1(self[/* send */3], /* UpdatePage */Block.__(2, [/* CreateWorkout */1]));
                                          } else {
                                            return Curry._1(self[/* send */3], /* UpdatePage */Block.__(2, [/* CreateExercise */0]));
                                          }
                                        }));
                          }),
                        ReasonReact.Router[/* unwatchUrl */2]
                      ],
                      /* [] */0
                    ];
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.routerPush = routerPush;
exports.component = component;
exports.make = make;
/* component Not a pure module */
