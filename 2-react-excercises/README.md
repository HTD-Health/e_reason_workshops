# Milion w Rozumie

## Opis projektu

Będziemy implementować aplikację - quiz "a-la Milionerzy" - Milion w Rozumie (ReasonML 😉).

Podczas gry użytkownik odpowiada na pytania o rosnącym poziomie trudności oraz wartości pieniężnej.
Każde pytanie ma 4 możliwe odpowiedzi, ale tylko jedna jest poprawna.

Quiz trwa do momentu kiedy użytkownik zdobędzie główną nagrodę, lub pomyli się w odpowiedzi. W przypadku przegranej, nagroda wynosi wartość progu "gwarantowanego" który przekroczono.

## Spis treści

3. [Etap 0: instalacja projektu](#etap-0-instalacja-projektu)
3. [Etap 1: podstawy reason-react](TODO)
4. [Etap 2: zaawansowany reason-react](TODO)
5. [Etap 3: współpraca JS & Reason](TODO)
6. [Etap 4: używanie JSON API](TODO)

## Etap 0: instalacja projektu

Musisz mieć zainstalowane `npm` (co najmniej w wersji 8 LTS).

Polecamy też skonfigurować edytor [Visual Studio Code](https://code.visualstudio.com/Download) z rozszerzeniem [reason-vscode](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode).

Najpierw instalacja zależności z npm:

```sh
npm install
```

W dwóch osobnych terminalach uruchom: kompilator Reason -> JavaScript

```
npm start
```

Oraz server developerski:

```
npm run server
```

Otwórz aplikację w przeglądarce pod adresem http://localhost:8000

## Etap 1: podstawy reason-react

Zaczynamy prezentacją przedstawiającą podstawy pisania aplikacji Reactowych w Reason.

Po prezentacji wykonaj po kolei poniższe zadania (warto zrobić git commit po wykonaniu każdego zadania).

Jeśli skończysz wszystkie zadania wcześniej, możesz spróbować zadań z następnego etapu, lub [Zadań dodatkowych](#zadania-dodatkowe).

### Zadanie 1: komponent `Logo`

Otwórz plik `src/Logo.re`. Ten mały komponent nie przyjmuje żadnych propsów i jest odpowiedzialny za logo widoczne na głównym ekranie aplikacji.

Zastąp istniejącą funkcję `make` tak aby rezultatem był HTML zawarty w komentarzu nad funkcją. Sprawdź rezultat w przeglądarce.

**Wskazówka:** Zwracaj uwagę na błędy kompilacji. Pamiętaj że w React atrybut HTML `class` osiąga się za pomocą propa `className`.

### Zadanie 2: komponent `QuestionText`

Dodaj prop `text` typu `string` do komponentu `QuestionText`.

Zwróć uwagę na błąd kompilacji w `src/Question.re`. Napraw go dodając jakąś wartość propu `text` do `<QuestionText />` (może być `Lorem ipsum dolor sit amet, consectetur adipiscing elit?` ;).

Wróć do komponentu `QuestionText` i uzupełnij funkcję `make` aby zwracała podany markup wraz z wartością propa `text`.

**Wskazówka:** Jeśli nie pamiętasz, sprawdź w prezentacji jak wyrenderować wartość typu `string` w Reason-React.

### Zadanie 3: komponent `Answer`

Dodaj prop `text` typu `string` oraz prop `id` typu `Core.answerId` w `src/Answer.re`. Napraw błędy kompilacji wpisując dowolne wartości cztery razy w `Question.re`.

Wróć do komponentu `Answer` i uzupełnij funkcję `make`. Na razie użyj HTML pod komentarzem `Initial:`

**Wskazówka:** Użyj pattern-matchingu aby wyrenderować ID odpowiedzi (A, B, C, D).

### Zadanie 4: komponent `Question`

Uzupełnij funkcję `make` w komponencie `Question` aby zwracała poprawny HTML.

Następnie dodaj prop `question` (typu `Core.question`) do komponentu `Question`. Napraw błąd kompilacji przekazując wartość `firstQuestion` do `<Question />` w `Game`.

Użyj nowego propu aby przekazać wartości `text` do `QuestionText` i propy `id`, `text` do `Answer`. Zweryfikuj czy pytanie zmieniło się w przeglądarce.

**Wskazówka:** Sprawdź w prezentacji jak wyrenderować wartość typu `list` - przyda się do renderowania `Answer`.

### Zadanie 5: klikanie na `Answer`

TODO

### Zadanie 6: kolorowanie `Answer`

TODO

## Etap 2: zaawansowany reason-react

### Zadanie 7: reducer!

TODO

### Zadanie 8: przechodzenie do następnego pytania

TODO

### Zadanie 9: komponenty `Prize` i `PrizeTrack`

TODO

### Zadanie 10: komponent `NewGameButton`

TODO

## Etap 3: współpraca JS & Reason

1. Renderowanie komponentu react-confetti przy poprawnej odpowiedzi
2. Umieszczenie komponentu Game w większej aplikacji

## Etap 4: używanie JSON API

2. Pobieranie listy pytań z API (atdgen?)

## Zadania dodatkowe

1. Zaimplementuj ekran końca gry pokazujący ostateczny wynik gracza. Pamiętaj o obsłudze zarówno przegranej jak i wygranej.
2. Zaimplementuj funkcję rezygnacji z gry i wzięcia nagrody gwarantowanej.
3. Zaimplementuj koła ratunkowe: 50/50, pytanie do publiczności lub telefon do przyjaciela.
