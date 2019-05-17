open Jest;

describe("QuestionText", () => {
  open Expect;

  test("renders correct html", () => {
    let wrapper = Enzyme.mount(<QuestionText text="Test text" />);
    expect(Enzyme.Mount.html(wrapper)) |> toEqual("<div class=\"question-text\">Test text</div>");
  });
});

describe("Answer", () => {
  open Expect;

  let mount = (~state) => Enzyme.mount(<Answer id=A text="Text" onClick={_ => ()} state />);

  test("renders correct html for initial answer", () => {
    let wrapper = mount(~state=Initial)
    expect(Enzyme.Mount.html(wrapper)) |> toEqual("<div class=\"answer\">A. Text</div>");
  });

  test("renders correct html for highlighted answer", () => {
    let wrapper = mount(~state=Highlighted)
    expect(Enzyme.Mount.html(wrapper)) |> toEqual("<div class=\"answer highlighted\">A. Text</div>");
  });

  test("renders correct html for correct answer", () => {
    let wrapper = mount(~state=Correct)
    expect(Enzyme.Mount.html(wrapper)) |> toEqual("<div class=\"answer correct\">A. Text</div>");
  });

  test("renders correct html for wrong answer", () => {
    let wrapper = mount(~state=Wrong)
    expect(Enzyme.Mount.html(wrapper)) |> toEqual("<div class=\"answer wrong\">A. Text</div>");
  });
});
