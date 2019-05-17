# Milion w Rozumie

## Spis treści

* [Opis projektu](#opis-projektu)
* [Etap 0: instalacja projektu](#etap-0-instalacja-projektu)
* [Etap 1: reason-react](#etap-1-reason-react)
* [Etap 2: współpraca JS & Reason](#etap-2-współpraca-js--reason)
* [Etap 3: używanie JSON API](#etap-3-używanie-json-api)
* [Zadania dodatkowe](#zadania-dodatkowe)
* [Przydatne linki](#przydatne-linki)

## Opis projektu

Będziemy implementować aplikację - quiz "a-la Milionerzy" - Milion w Rozumie (ReasonML 😉).

Podczas gry użytkownik odpowiada na pytania o rosnącym poziomie trudności oraz wartości pieniężnej.
Każde pytanie ma 4 możliwe odpowiedzi, ale tylko jedna jest poprawna.
Interakcja z aplikacją polega na klikaniu w odpowiedzi - pierwsze kliknięcie zaznacza odpowiedż, drugie zatwierdza, trzecie przechodzi do następnego pytania.

Gra trwa do momentu kiedy użytkownik zdobędzie główną nagrodę, lub pomyli się w odpowiedzi.
W przypadku przegranej, nagroda wynosi wartość progu "gwarantowanego" który przekroczono.

Live demo: http://workshops.htdevelopers.com/e_reason_workshops

## Etap 0: instalacja projektu

Musisz mieć zainstalowane `npm` (co najmniej w wersji 8 LTS).

Polecamy też skonfigurować edytor [Visual Studio Code](https://code.visualstudio.com/Download) z rozszerzeniem [reason-vscode](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode).

Najpierw instalacja zależności z npm:

```sh
npm install
```

W dwóch osobnych terminalach uruchom: kompilator Reason -> JavaScript

```
npm run start:bs
```

Oraz server developerski:

```
npm run start:js
```

Otwórz aplikację w przeglądarce pod adresem http://localhost:8000

## Etap 1: reason-react

Zaczęliśmy prezentacją przedstawiającą podstawy pisania aplikacji Reactowych w Reason.

Po prezentacji i zainstalowaniu projektu wykonaj po kolei poniższe zadania (warto zrobić git commit po wykonaniu każdego zadania).

Jeśli skończysz wszystkie zadania wcześniej, możesz spróbować zadań z następnego etapu, lub [Zadań dodatkowych](#zadania-dodatkowe).

<details>
<summary><strong>Zadanie 1: komponent Logo</strong></summary>

* Otwórz plik `src/Logo.re`. Ten mały komponent nie przyjmuje żadnych propsów i jest odpowiedzialny za logo widoczne na głównym ekranie aplikacji.

* Zastąp istniejącą funkcję `make` tak aby rezultatem był HTML zawarty w komentarzu nad funkcją. Sprawdź rezultat w przeglądarce.

**Wskazówka:** Zwracaj uwagę na błędy kompilacji. Pamiętaj że w React atrybut HTML `class` osiąga się za pomocą propa `className`.
</details>

<details>
<summary><strong>Zadanie 2: komponent QuestionText</strong></summary>

* Dodaj prop `text` typu `string` do komponentu `QuestionText`.

* Zwróć uwagę na błąd kompilacji w `src/Question.re`. Napraw go dodając jakąś wartość propu `text` do `<QuestionText />` (może być `Lorem ipsum dolor sit amet, consectetur adipiscing elit?` ;).

* Wróć do komponentu `QuestionText` i uzupełnij funkcję `make` aby renderowała podany markup wraz z wartością propa `text`.

**Wskazówka:** Jeśli nie pamiętasz, sprawdź w prezentacji jak wyrenderować wartość typu `string` w Reason-React.
</details>

<details>
<summary><strong>Zadanie 3: komponent Answer</strong></summary>

* Zapoznaj się z typem `answerId` w pliku `Core.re`. Jest to variant z czterema możliwościami: A, B, C, D.

* Dodaj prop `text` typu `string` oraz prop `id` typu `Core.answerId` w `src/Answer.re`. Napraw błędy kompilacji wpisując dowolne wartości cztery razy w `Question.re`.

* Wróć do komponentu `Answer` i uzupełnij funkcję `make`. Na razie użyj HTML pod komentarzem `Initial:`

**Wskazówka:** Użyj pattern-matchingu aby wyrenderować ID odpowiedzi (A, B, C, D).
</details>

<details>
<summary><strong>Zadanie 4: komponent Question</strong></summary>

* Uzupełnij funkcję `make` w komponencie `Question` aby renderowała poprawny HTML.

* Następnie dodaj prop `question` (typu `Core.question`) do komponentu `Question`. Napraw błąd kompilacji przekazując wartość `firstQuestion` do `<Question />` w `Game`.

* Użyj nowego propu aby przekazać wartości `text` do `QuestionText` i propy `id`, `text` do `Answer`. Zweryfikuj czy pytanie zmieniło się w przeglądarce.

**Wskazówka:** Sprawdź w prezentacji jak wyrenderować wartość typu `list` - przyda się do renderowania `Answer`.
</details>

<details>
<summary><strong>Zadanie 5: klikanie na odpowiedź</strong></summary>

* Dodaj prop `onClick` do komponentu `Answer`. Niech będzie to funkcja przyjmująca `Core.answerId` i nie zwracająca nic: `Core.answerId => unit`.

* Dodaj prop `onAnswerClick`, tego samego typu do komponentu `Question`.

* Napraw błędy kompilacji przekazując callback do `<Question />` w `Game` i przekazując ten sam callback do `<Answer onClick={} />` w `Question`. W callbacku możesz wypisać po prostu zwracaną wartość `answerId` do konsoli.

**Wskazówka**: Możesz użyć funkcji `Js.log`, `Js.log2` etc. do wypisywania do konsoli.
</details>

<details>
<summary><strong>Zadanie 6: kolorowanie odpowiedzi</strong></summary>

* Do komponentu `Answer` dodaj prop `state` typu `state` (zdefiniowanego na górze pliku). Ten prop będzie oznaczał czy odpowiedż jest aktualnie zaznaczona, poprawna albo niepoprawna.

* Napraw błędy kompilacji przekazując różne wartości `state` do `<Answer state={} />` w `Question`.

* Zmodyfikuj renderowanie `Answer` tak aby zmienić `className` w zależności od `state`. W komentarzu nad komponentem jest docelowy markup HTML.

* Zweryfikuj renderowanie różnych stanów odpowiedzi w przeglądarce.
</details>

<details>
<summary><strong>Zadanie 7: dynamiczny stan odpowiedzi</strong></summary>

* Zapoznaj się z typem `Core.answeringState`. Typ ten modeluje w jakim stanie obecnie znajduje się pytanie: nie odpowiedziane, zaznaczona odpowiedź, odpowiedź poprawna, odpowiedź niepoprawna.

* Dodaj prop `answeringState` do `Question`. Napraw błąd kompilacji przekazując prop `answeringState` w `Game`.

* W `Question`, na podstawie wartości nowego propu `answeringState` przekaż tym razem poprawne wartości `state` do `Answer`. Pomyśl jaki jest stan pojedyńczej odpowiedzi w zależności od aktualnego `answeringState`.

**Wskazówka:** Użyj pattern-matchingu na `answeringState` aby stworzyć poprawny stan dla odpowiedzi.
</details>

<details>
<summary><strong>Zadanie 8: implementacja reducera</strong></summary>

* Zapoznaj się z typami `state`, `action` oraz funkcją `reducer` w `Game`. Te elementy kontrolują jak stan gry będzie zmieniał się w zależności od akcji podejmowanych przez użytkownika.

* Zmodyfikuj swój callback `onAnswerClick` w `Game` tak aby wysyłał poprawną akcję (funkcja `send` z `React.useReducer`).

* Uzupełnij funkcję `reducer` aby zwracała stan z nowym `answeringState` w reakcji na akcję `SelectAnswer`.

* Zweryfikuj zachowanie gry w przeglądarce.

**Wskazówka:** nowy stan zależy od poprzedniego `answeringState`:
* Brak zaznaczenia -> odpowiedź zaznaczona
* Kliknięto zaznaczoną poprawną odpowiedź -> odpowiedź poprawna
* etc... pomyśl o wszystkich przypadkach, zwróć uwagę na ostrzerzenia kompilatora

**Wskazówka:** Użyj "spread operator" aby wygodnie zaktualizować jedno pole w stanie: `{ ...state, answeringState: _ }`

**Wskazówka:** Funkcja `Belt.List.getExn(list, index)` może się przydać w tym zadaniu.
</details>

<details>
<summary><strong>Zadanie 9: przechodzenie do następnego pytania</strong></summary>

* Przekaż aktualne pytanie do komponentu `<Question />` w `Game`. Wydobądź aktualnie pytanie ze stanu na podstawie wartości `state.currentPrizeIndex` i `state.prizes`. `Prizes` są reprezentowane jako lista od najprostszych do najtrudniejszych.

* W odpowiednim miejscu w reducerze, uaktualnij stan tak aby przejść do następnego pytania.

* Zweryfikuj działanie gry w przeglądarce. W tym momencie powinno się już dać odpowiedzieć na wszystkie pytania aż do ostatniego. Umiesz to zrobić bez patrzenia na poprawne odpowiedzi? ;)
</details>

<details>
<summary><strong>Zadanie 10: komponent PrizeTrack</strong></summary>

* Dodaj propy `prizes` (typu `list(Core.prize)`) i `currentPrizeIndex` do komponentu `PrizeTrack`.

* Napraw błędy kompilacji w `Game` przekazując propy z aktualnego stanu gry.

* Dodaj prop `amount` typu `int` do komponentu `Prize` i wyrenderuj `amount`.

* Uaktualnij komponent `PrizeTrack` aby zwracał poprawny HTML oraz renderował `Prize` dla każdej nagrody przekazanej w propie `prizes`.

* Spróbuj odwrócić kolejność renderowania nagród tak żeby nagroda główna była na górze.

**Wskazówka:** Metody `string_of_int` oraz `Belt.List.reverse` mogą się przydać w tym zadaniu.
</details>

<details>
<summary><strong>Zadanie 11: komponent Prize</strong></summary>

* Dodaj prop `state` typu `state` do `Prize`. Ten prop decyduje czy dana nagroda jest aktualna, już wygrana czy dopiero przyszła. Napraw błąd kompilacji przekazując poprawne varianty do `Prize` w `PrizeTrack`.

* Zmodyfikuj renderowanie `Prize` tak aby dodawało odpowiednie `className` na podstawie `state`.

* Dodaj prop `tier` typu `Core.tier` do `Prize` i przekaż odpowiednie wartości w `PrizeTrack`.

* Znów zmodyfikuj renderowanie `Prize` tak aby dodawało odpowiednią klasę na podstawie `tier`.

* Zweryfikuj poprawne zachowanie całego prawego sidebara w przeglądarce.

**Wskazówka:** Konkatenacja stringów za pomocą operatora `++` może się przydać w tym zadaniu.
</details>

<details>
<summary><strong>Zadanie 12: komponent NewGameButton</strong></summary>

* Uzupełnij `NewGameButton.re` tak aby zwracał poprawny HTML.

* Dodaj akcję `NewGame` do variantu `Game.actions`.

* Dodaj prop `onClick` do komponentu i podłącz go do przycisku. Niech klikanie na przycisk wysyła akcję `NewGame`.

* Zmodyfikuj reducer tak aby zresetować stan gry po otrzymaniu akcji `NewGame`.
</details>

## Etap 2: współpraca JS & Reason

Najpierw zapoznaj się z prezentacją nt. kompatybilności JavaScript z Reason. Następnie wykonaj poniższe ćwiczenia w swoim projekcie:

<details>
<summary><strong>Zadanie 13: react-confetti</strong></summary>

* Zapoznaj się z dokumentacją biblioteki `react-confetti` (https://github.com/alampros/react-confetti)

* W pliku `Confetti.re` stwórz binding to komponentu `react-confetti`, przekazując narazie tylko jednego propa: `numberOfPieces`.

* Wyrenderuj komponent `Confetti` w `Game` kiedy użytkownik odpowie poprawnie na pytanie. Zweryfikuj działanie w przeglądarce.
</details>

<details>
<summary><strong>Zadanie 14: więcej confetti</strong></summary>

* Dodaj więcej propów według swojego uznania do dowiązania w `Confetti` (https://github.com/alampros/react-confetti)

* Pozmieniaj wartości propów aż efekt będzie zadowalający :)
</details>

<details>
<summary><strong>Zadanie 15: importowanie Reason</strong></summary>

W tym zadaniu zobaczymy jak proste jest importowanie komponentów Reasonowych w istniejącym projekcie

* Wejdź na adres http://localhost:8000/project.html . Ta strona ma symulować projekt napisany w JavaScript.

* Zapoznaj się z plikiem `src/project.js` w którym znajduje się renderowanie tego projektu.

* Zaimportuj Reasonowy komponent `Game` i wyrenderuj go w odpowiednim miejscu. Zweryfikuj działanie na stronie projektu.
</details>

## Etap 3: używanie JSON API

Najpierw zapoznaj się z prezentacją nt. używania JSON API w Reason.
Następnie wykonaj poniższe ćwiczenia w swoim projekcie:

<details>
<summary><strong>Zadanie 16: uruchomienie serwera</strong></summary>

* Uruchom dodatkowy serwer za pomocą komendy `npm run start:server`.

* Odwiedź adres http://localhost:8001/prizes.json w przeglądarce. Po kilku sekundach powinien się pojawić zwracany JSON. Zapoznaj się ze zwracaną strukturą danych.

</details>

<details>
<summary><strong>Zadanie 17: parsowanie odpowiedzi z API</strong></summary>

* W komponencie `Game` użyj hooka `useEffect` aby wywołać request do endpointu nowego API podczas montowania komponentu. Wypisz zwrócony JSON na konsolę aby przetestować działanie.

* Uzupełnij moduł `src/Api.re` o funkcje parsujące json z użyciem biblioteki `bs-json`.

* Wywołaj funkcję parsującą na JSONie zwróconym z API.

* Używając sparsowanych danych, wypisz na konsolę kolejno zwrócone pytania.
</details>

<details>
<summary><strong>Zadanie 18: stan ładowania</strong></summary>

* Do variantu `Game.action` dodaj akcje `Loaded(list(Core.prize))` i `ErrorLoading`

* Wyślij akcję `Loaded()` kiedy dane zostaną sparsowane z API, i akcję `Error` w przypadku błędu Promise.

* Zmień variant `Game.state` aby miał wartości `Loading`, `Error`, `Loaded(state)`. Zmień pierwotny stan na `Loading`.

* W reducerze, zmieniaj stan odpowiednio reagując na nowe akcje.

* Uaktualnij renderowanie `Game`, tak aby uwzględnić stany `Loading` i `ErrorLoading`
</details>

## Zadania dodatkowe

* Zaimplementuj ekran końca gry pokazujący ostateczny wynik gracza. Pamiętaj o obsłudze zarówno przegranej jak i wygranej.
* Zaimplementuj przycisk powodujący rezygnację z gry i wzięcie nagrody gwarantowanej.
* Zaimplementuj koła ratunkowe: 50/50, pytanie do publiczności lub telefon do przyjaciela.
* Zaimplementuj randomizację pytań / odpowiedzi z bazy dostępnych pytań. Możesz wymyślić własne pytania!

## Przydatne linki

* Operacje na listach (`Belt.List`): https://bucklescript.github.io/bucklescript/api/Belt.List.html
* Przykłady parsowania JSON (`bs-json`): https://github.com/glennsl/bs-json/blob/master/examples/complex.ml
* Źródła `reason-react`: https://github.com/reasonml/reason-react/blob/master/src/React.re
* Dokumentacja react hooks: https://reactjs.org/docs/hooks-reference.html
