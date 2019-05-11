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

* Otwórz plik `src/Logo.re`. Ten mały komponent nie przyjmuje żadnych propsów i jest odpowiedzialny za logo widoczne na głównym ekranie aplikacji.

* Zastąp istniejącą funkcję `make` tak aby rezultatem był HTML zawarty w komentarzu nad funkcją. Sprawdź rezultat w przeglądarce.

**Wskazówka:** Zwracaj uwagę na błędy kompilacji. Pamiętaj że w React atrybut HTML `class` osiąga się za pomocą propa `className`.

### Zadanie 2: komponent `QuestionText`

* Dodaj prop `text` typu `string` do komponentu `QuestionText`.

* Zwróć uwagę na błąd kompilacji w `src/Question.re`. Napraw go dodając jakąś wartość propu `text` do `<QuestionText />` (może być `Lorem ipsum dolor sit amet, consectetur adipiscing elit?` ;).

* Wróć do komponentu `QuestionText` i uzupełnij funkcję `make` aby renderowała podany markup wraz z wartością propa `text`.

**Wskazówka:** Jeśli nie pamiętasz, sprawdź w prezentacji jak wyrenderować wartość typu `string` w Reason-React.

### Zadanie 3: komponent `Answer`

* Zapoznaj się z typem `answerId` w pliku `Core.re`. Jest to variant z czterema możliwościami: A, B, C, D.

* Dodaj prop `text` typu `string` oraz prop `id` typu `Core.answerId` w `src/Answer.re`. Napraw błędy kompilacji wpisując dowolne wartości cztery razy w `Question.re`.

* Wróć do komponentu `Answer` i uzupełnij funkcję `make`. Na razie użyj HTML pod komentarzem `Initial:`

**Wskazówka:** Użyj pattern-matchingu aby wyrenderować ID odpowiedzi (A, B, C, D).

### Zadanie 4: komponent `Question`

* Uzupełnij funkcję `make` w komponencie `Question` aby renderowała poprawny HTML.

* Następnie dodaj prop `question` (typu `Core.question`) do komponentu `Question`. Napraw błąd kompilacji przekazując wartość `firstQuestion` do `<Question />` w `Game`.

* Użyj nowego propu aby przekazać wartości `text` do `QuestionText` i propy `id`, `text` do `Answer`. Zweryfikuj czy pytanie zmieniło się w przeglądarce.

**Wskazówka:** Sprawdź w prezentacji jak wyrenderować wartość typu `list` - przyda się do renderowania `Answer`.

### Zadanie 5: klikanie na `Answer`

* Dodaj prop `onClick` do komponentu `Answer`. Niech będzie to funkcja przyjmująca `Core.answerId` i nie zwracająca nic: `Core.answerId => unit`.

* Dodaj prop `onAnswerClick`, tego samego typu do komponentu `Question`.

* Napraw błędy kompilacji przekazując callback do `<Question />` w `Game` i przekazując ten sam callback do `<Answer onClick={} />` w `Question`. W callbacku możesz wypisać po prostu zwracaną wartość `answerId` do konsoli.

**Wskazówka**: Użyj funkcji `Js.log`, `Js.log2` etc. do wypisywania do konsoli.

### Zadanie 6: kolorowanie `Answer`

* Do komponentu `Answer` dodaj prop `state` typu `state` (zdefiniowanego na górze pliku). Ten prop będzie oznaczał czy odpowiedż jest aktualnie zaznaczona, poprawna albo niepoprawna.

* Napraw błędy kompilacji przekazując różne wartości `state` do `<Answer state={} />` w `Question`.

* Zmodyfikuj renderowanie `Answer` tak aby zmienić `className` w zależności od `state`. W komentarzu nad komponentem jest docelowy markup HTML.

* Zweryfikuj renderowanie różnych stanów odpowiedzi w przeglądarce.

## Etap 2: zaawansowany reason-react

### Zadanie 7: aktualny stan odpowiedzi

* Zapoznaj się z typem `Core.answeringState`. Typ ten modeluje w jakim stanie obecnie znajduje się pytanie: nie odpowiedziane, zaznaczona odpowiedź, odpowiedź poprawna, odpowiedź niepoprawna.

* Dodaj prop `answeringState` do `Question`. Napraw błąd kompilacji przekazując prop `answeringState` w `Game`.

* W `Question`, na podstawie wartości nowego propu `answeringState` przekaż tym razem poprawne wartości `state` do `Answer`. Pomyśl jaki jest stan pojedyńczej odpowiedzi w zależności od aktualnego `answeringState`.

**Wskazówka:** Użyj pattern-matchingu na `answeringState` aby stworzyć poprawny stan dla odpowiedzi.

### Zadanie 8: reducer

* Zapoznaj się z typami `state`, `action` oraz funkcją `reducer` w `Game`. Te elementy kontrolują jak stan gry będzie zmieniał się w zależności od akcji podejmowanych przez użytkownika.

* Zmodyfikuje swój callback `onAnswerClick` w `Game` tak aby wysyłał poprawną akcję (funkcja `send` z `React.useReducer`).

* Uzupełnij funkcję `reducer` aby zwracała stan z nowym `answeringState` w reakcji na akcję `SelectAnswer`.

* Zweryfikuj zachowanie gry w przeglądarce.

**Wskazówka:** nowy stan zależy od poprzedniego `answeringState`:
* Brak zaznaczenia -> odpowiedź zaznaczona
* Kliknięto zaznaczoną poprawną odpowiedź -> odpowiedź poprawna
* etc... pomyśl o wszystkich przypadkach, zwróć uwagę na ostrzerzenia kompilatora

**Wskazówka:** Użyj "spread operator" aby wygodnie zaktualizować jedno pole w stanie: `{ ...state, answeringState: _ }`

**Wskazówka:** Funkcja `Belt.List.getExn(list, index)` może się przydać w tym zadaniu.

### Zadanie 9: przechodzenie do następnego pytania

* Przekaż aktualne pytanie do komponentu `<Question />` w `Game`. Wydobądź aktualnie pytanie ze stanu na podstawie wartości `state.currentPrizeIndex` i `state.prizes`. `Prizes` są reprezentowane jako lista od najprostszych do najtrudniejszych.

* W odpowiednim miejscu w reducerze, uaktualnij stan tak aby przejść do następnego pytania.

* Zweryfikuj działanie gry w przeglądarce. W tym momencie powinno się już dać odpowiedzieć na wszystkie pytania aż do ostatniego. Umiesz to zrobić bez patrzenia na poprawne odpowiedzi? ;)

### Zadanie 10: komponenty `Prize` i `PrizeTrack`

TODO

### Zadanie 11: komponent `NewGameButton`

* Uzupełnij `NewGameButton.re` tak aby zwracał poprawny HTML.

* Dodaj akcję `NewGame` do variantu `Game.actions`.

* Dodaj prop `onClick` do komponentu i podłącz go do przycisku. Niech klikanie na przycisk wysyła akcję `NewGame`.

* Zmodyfikuj reducer tak aby zresetować stan gry po otrzymaniu akcji `NewGame`.

## Etap 3: współpraca JS & Reason

1. Renderowanie komponentu react-confetti przy poprawnej odpowiedzi
2. Umieszczenie komponentu Game w większej aplikacji

## Etap 4: używanie JSON API

2. Pobieranie listy pytań z API (atdgen?)

## Zadania dodatkowe

1. Zaimplementuj ekran końca gry pokazujący ostateczny wynik gracza. Pamiętaj o obsłudze zarówno przegranej jak i wygranej.
2. Zaimplementuj przycisk powodujący rezygnację z gry i wzięcie nagrody gwarantowanej.
3. Zaimplementuj koła ratunkowe: 50/50, pytanie do publiczności lub telefon do przyjaciela.
