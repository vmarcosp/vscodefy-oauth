let (>=) = (maybe, func) => maybe->Option.map(func);
let (>?) = (maybe, defaultValue) =>
  maybe->Option.getWithDefault(defaultValue);
