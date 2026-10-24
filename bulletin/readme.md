# Report Card Calculator in C

A small command-line program that builds a report card. You enter your subjects and the grade you got in each one, and the program displays a summary, your overall average and an appreciation message.

## Features

- **Enter any number of subjects** (up to 20), each with a name and a grade
- **Report card display**: each subject with its grade out of 20
- **Overall average** computed from all the grades
- **Appreciation message** based on the average

## Appreciation scale

| Average | Message |
|---------|---------|
| 18 and above | Tres bien |
| 14 to under 18 | Bien |
| 12 to under 14 | Félicitation |
| 10 to under 12 | continuer vos efforts |
| Under 10 | Pas d'effort |

> Note: the program's prompts and messages are in French.

## Requirements

A C compiler, for example [GCC](https://gcc.gnu.org/):

- **Windows**: MinGW-w64 or MSYS2
- **Linux**: `sudo apt install gcc`
- **macOS**: `xcode-select --install`

## Build and run

```bash
gcc bulletin.c -o bulletin
./bulletin
```

On Windows, run `bulletin.exe` instead of `./bulletin`.

## Usage

The program first asks how many subjects you have, then prompts for the name and grade of each one. The screen is cleared between each subject.

### Example

```
combien de matiere avez-vous : 3
qu'elle est la matiere : Maths
qu'elle est ta note : 15
qu'elle est la matiere : Anglais
qu'elle est ta note : 12.5
qu'elle est la matiere : Informatique
qu'elle est ta note : 17
```

Output:

```
Votre bulletin
- Maths : 15.00/20
- Anglais : 12.50/20
- Informatique : 17.00/20

note general : 14.83
Bien
```

## How it works

| Element | Role |
|---------|------|
| `matieres[][]` | Array of subject names (20 characters max each) |
| `notes[]` | Array of grades, one per subject |
| `moy` | Overall average, computed as the sum of `note / m` |
| `if / else if` chain | Picks the appreciation message from the average |

## Known limitations

- Subject names cannot contain spaces (limitation of `scanf("%s")`)
- The number of subjects is not checked: it must be between 1 and 20
- Grades are not validated: values outside 0 to 20 are accepted
- `system("cls")` only works on Windows (use `clear` on Linux/macOS)
- Nothing is saved: the report card disappears when the program exits

## Possible improvements

- Validate the number of subjects and the grades
- Add coefficients (weighted average)
- Allow subject names with spaces using `fgets`
- Save the report card to a file
- Make the screen clearing work on every operating system