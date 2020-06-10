let int = value => value->string_of_int->React.string;

let map = (items, fn) => items->Belt.Array.map(fn)->React.array;
