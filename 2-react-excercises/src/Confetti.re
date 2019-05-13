[@bs.module "react-confetti"] [@react.component]
external make:
  (~recycle: bool, ~numberOfPieces: int, ~gravity: float) => React.element =
  "default";
