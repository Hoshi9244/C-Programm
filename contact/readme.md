# Contact Manager in C

A small command-line program for managing an address book, written in C. It lets you add contacts, search for one by last name and first name, and display the full list.

## Features

- **Add contacts**: enter the last name, first name and phone number for as many contacts as you choose
- **Search for a contact**: search by last name and first name, case-insensitive
- **Display all contacts**: full list with phone numbers shown in international format (`+33...`)
- **Phone number validation**: a number must have 10 digits and start with `0`
- **Cross-platform**: works on Windows, Linux and macOS

## Requirements

A C compiler, for example [GCC](https://gcc.gnu.org/):

- **Windows**: MinGW-w64 or MSYS2
- **Linux**: `sudo apt install gcc`
- **macOS**: `xcode-select --install`

## Build and run

```bash
gcc contacts.c -o contacts
./contacts
```

On Windows, run `contacts.exe` instead of `./contacts`.

## Usage

When the program starts, the following menu is displayed:

```
 --- Menu ---
 1 - Ajouter des contacts
 2 - Rechercher un contact
 3 - Afficher tous les contacts
 4 - Quitter
```

| Choice | Action |
|--------|--------|
| 1 | Asks how many contacts to add, then prompts for each one |
| 2 | Asks for a last name and first name, then shows the matching contact |
| 3 | Displays all stored contacts |
| 4 | Exits the program |

> Note: the program's prompts and messages are in French.

### Example

```
Nom du contact : Dupont
Prenom du contact : Jean
Numero du contact : 0612345678
```

Will be displayed as:

```
Nom : Dupont
Prenom : Jean
Numero : +33612345678
```

## Code structure

| Element | Role |
|---------|------|
| `struct Contact` | Groups a contact's last name, first name and phone number |
| `vider_buffer()` | Clears the input buffer after a `scanf` |
| `afficher_contact()` | Displays a single contact |
| `ajoute_contact()` | Reads the contacts and returns the array allocated with `malloc` |
| `numero_valide()` | Checks that a phone number is valid |
| `main()` | Displays the menu and handles the user's choices |

## Known limitations

- Contacts are not saved: they are lost when the program exits
- Each "add" **replaces** the previous contacts (using `realloc` would allow them to accumulate)
- Names cannot contain spaces (limitation of `scanf("%s")`)
- Only 10-digit French phone numbers are accepted

## Possible improvements

- Accumulate contacts using `realloc`
- Save and load contacts from a file
- Delete and edit contacts
- Allow compound names using `fgets`