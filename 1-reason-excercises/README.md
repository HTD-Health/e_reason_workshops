# Wstęp do ReasonML

W tym folderze znajdują się instrukcje i pliki wynikowe do zadań, które przeprowadzimy podczas części wstępnej do języka ReasonML.

## Spis treści

1. [Instalacja środowiska](#1-instalacja-środowiska)
2. [Konfiguracja pierwszego projektu](#2-konfiguracja-pierwszego-projektu)
3. [Ćwiczenia](#3-ćwiczenia)
4. [Materiały dodatkowe](#4-materiały-dodatkowe)

## 1. Instalacja środowiska

Zacznijmy od zainstalowania `node.js` w wersji 8 lub wyższej (preferowane wersje LTS).

Pliki do pobrania i instrukcje dostępne [tutaj](https://nodejs.org/en/download/).

Następnie musimy zainstalować platformę BuckleScript (kompilatora OCaml i Reason do Javascript, więcej info o nim [tutaj](https://bucklescript.github.io))

```
npm install -g bs-platform
```

## 2. Konfiguracja pierwszego projektu

Teraz możemy już zainicjalizować pierwszy podstawowy projekt dzięki poleceniu
```
bsb -init pierwszy-projekt -theme basic-reason
```

Przełącznik `-theme` pozwala nam na wybranie podstawowej konfiguracji (lista konfiguracji dostępna [tutaj](https://github.com/bucklescript/bucklescript/tree/master/jscomp/bsb/templates)). Skorzystamy z motywu `basic-reason` w naszym pierwszym projekcie.

Teraz w folderze projektu wystarczy uruchomić polecenia
```
npm install
npm start
```

Jako edytor do plików źródłowych ReasonML zalecamy [Visual Studio Code](https://code.visualstudio.com/) z dodatkiem [reason-vscode](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode). Jeśli korzystasz z innego edytora i nie chcesz się przestawiać na nowe środowisko, to skorzystaj z wtyczki do swojego edytora (dostępne [tutaj](https://reasonml.github.io/docs/en/editor-plugins)).

## 3. Ćwiczenia

<details>
<summary><b>Ćwiczenie 1.</b></summary>

1. Przygotuj funkcję, która przyjmuje typ `person` jako argument i zwraca string ze sformatowanymi danymi tej osoby (np. imię, wiek, wzrost).
2. Następnie przygotuj przykładową bazę danych, składających się z przynajmniej 3 osób i wyświetl ją, korzystając z przygotowanej wcześniej funkcji.

Dodatkowe zadania:
* użyj operatora potoku (`|>`) przy tworzeniu funkcji do wyświetlenia
* posortuj listę wg dowolnego parametru przed wyświetleniem

Przykładowy typ `person`:
* name: string
* age: integer
* height: integer

**Przydatne dodatkowe funkcje:**
`List.iter`, `List.sort`, `String.compare`, `Pervasives.compare`
</details>

<details>
<summary><b>Ćwiczenie 2.</b></summary>

1. Zamodeluj typ `answer` i typ `question` 
2. Przygotuj funkcję, sprawdzającą poprawność podanej odpowiedzi

Przykładowy typ `answer`:
* text: string
* id: answerId (gdzie answerId jest typu A, B, C lub D)

Przykładowy typ `question`:
* text: string
* answers: list(answer)
* correctAnswerId: answerId

Zadania dodatkowe:
* utwórz moduł dla typów `answer` i `question`
* użyj wartości w typach wariantów (np. `CorrectAnswer(prize) | WrongAnswer`)
</details>

## 4. Materiały dodatkowe
* [ściągawka ze składnią ReasonML](https://reasonml.github.io/docs/en/syntax-cheatsheet)
* [dokumentacja ReasonML](https://reasonml.github.io/docs/en/what-and-why)
