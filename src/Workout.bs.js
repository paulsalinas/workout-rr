// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var Belt_List = require("bs-platform/lib/js/belt_List.js");

var LiftingSet = /* module */[];

function liftingSetCount(groupings) {
  return Belt_List.reduce(groupings, 0, (function (sum, g) {
                if (g.tag) {
                  return sum;
                } else {
                  return sum + 1 | 0;
                }
              }));
}

var SetGrouping = /* module */[/* liftingSetCount */liftingSetCount];

exports.LiftingSet = LiftingSet;
exports.SetGrouping = SetGrouping;
/* No side effect */