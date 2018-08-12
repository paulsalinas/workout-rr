open Exercise;

type rest = int;
type reps = int;
type tempo = {
  concentric: int,
  eccentric: int,
  peak: int,
  bottom: int,
};

module WorkoutSets = {
  type simpleSet = {
    reps,
    exercise,
    tempo,
    resistance: float,
    setCount: int,
  };
};

type setActivity =
  | SimpleSet(WorkoutSets.simpleSet);

type workoutActivity =
  | Grouping(list(setActivity))
  | Rest(rest);

type workout = {
  id: int,
  workoutActivities: list(workoutActivity),
  name: string,
};