[@react.component]
let make = (~message: string, ~children: option(React.element)=?) => {
  let children =
    switch (children) {
    | Some(children) => children
    | None => React.null
    };
  <div className="todo">
    {ReasonReact.string("TODO: " ++ message)}
    children
  </div>;
};
