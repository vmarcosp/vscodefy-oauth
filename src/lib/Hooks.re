let always = (a, _) => a;

let useEffectOnce = React.useEffect0;

let useState = value => React.useState(always(value));
