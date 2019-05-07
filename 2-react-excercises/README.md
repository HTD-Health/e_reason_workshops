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

### Zadanie 2: komponent `NewGameButton`

1. Proste komponenty: Logo, NewGameButton, Award, Answer, QuestionText
2. Większe komponenty: AwardTrack, Question

## Etap 2: zaawansowany reason-react

3. Główny component: Game (useReducer), modelowanie stanu i akcji

## Etap 3: współpraca JS & Reason

1. Renderowanie komponentu react-confetti przy poprawnej odpowiedzi
2. Umieszczenie komponentu Game w większej aplikacji

## Etap 4: używanie JSON API

2. Pobieranie listy pytań z API (atdgen?)

## Zadania dodatkowe

1. Ekran końca gry z końcowym wynikiem
2. Guzik rezygnacji z gry
2. Implementacja kół ratunkowych: 50/50, pytanie do publiczności, telefon do przyjaciela
