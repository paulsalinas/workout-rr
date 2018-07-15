open Exercise;

type rest = int;

module LiftingSet = {
  type reps = int;
  type tempo = {
    concentric: int,
    eccentric: int,
    peak: int,
    bottom: int,
  };
  type set = {
    reps,
    exercise,
    tempo,
    resistance: float,
  };
  type workoutSet =
    | Simple(set)
    | Super(list(set));
};

module SetGrouping = {
  type setActivity =
    | Lift(LiftingSet.workoutSet)
    | Rest(rest);
  type groupings = list(setActivity);
  let liftingSetCount = (groupings: groupings) =>
    Belt.List.reduce(groupings, 0, (sum, g) =>
      switch (g) {
      | Lift(_) => sum + 1
      | _ => sum
      }
    );
};

type workoutActivity =
  | Grouping(SetGrouping.groupings)
  | Rest(rest);

type workout = {
  id: int,
  workoutActivities: list(workoutActivity),
  name: string,
};