[@react.component]
let make = (~message: string, ~children: option(React.element)=?) => {
  let children =
    switch (children) {
    | Some(children) => children
    | None => React.null
    };
  <div
    style={ReactDOMRe.Style.make(
      ~border="1px dashed gray",
      ~padding="10px",
      ~margin="5px 0",
      ~borderRadius="5px",
      (),
    )}>
    {ReasonReact.string("TODO: " ++ message)}
    children
  </div>;
};
