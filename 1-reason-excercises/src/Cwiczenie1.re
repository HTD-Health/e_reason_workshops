type person = {
  age: int,
  height: int,
  name: string,
};

let people = [
  {age: 30, height: 180, name: "Pierre"},
  {age: 32, height: 164, name: "Kathleen"},
  {age: 22, height: 178, name: {j|José|j}},
  {age: 19, height: 159, name: {j|Małgorzata|j}},
];

let getPersonData = ({age, height, name}) => {j|Name: $name, Age: $age, Height: $height|j};

// pierwszy sposób
let displayPerson = person => print_endline(getPersonData(person));

List.iter(displayPerson, people);

print_endline("");

// drugi sposób (z użyciem operatora |>)
let displayPerson = person => person |> getPersonData |> print_endline;

people |> List.iter(displayPerson);

print_endline("");

// sortowanie wg imienia
let sortedPeople =
  people
  |> List.sort(({name: nameA}, {name: nameB}) =>
       String.compare(nameA, nameB)
     );

sortedPeople |> List.iter(displayPerson);