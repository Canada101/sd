# Project Group 5: Choose Your Adventure Game

## Project Overview
This project is a version of a Choose Your Own Adventure game. In this game, the king of the land has begun using his power for evil. He allows monsters to roam, pillaging and burning as they please. The main character of this story is embarking on a journey to confront the king in the hopes of changing the situation. This is an arduous journey that involves interactions with strangers, battles, and more on the way to the king.

The player of the game is given four options of character types to play as: the wizard, the ranger, the swordsman, or the guardian. The game provides the player with multiple options to choose from throughout the game, which change the course of the game. 

## Compiling and Running the Program

In order to run the program, ensure [SFML](https://www.sfml-dev.org/download.php) is downloaded.

### How to Compile:
In order to compile the game, ensure you have `g++` and `SFML` installed on your system.

To compile the program, run the following command:
`make`
If this command produces an error, use the following command:
 `g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system`

### How to Run:
After compiling the program, use the following command to execute the game:
`./main`

## Compatable OSes
This game has only been run and tested on MacOS systems.

## System Requirements
This game requires a system that is capable of running C++ and SFML.

## Library Requirements
* Standard C++ library
* [The Simple and Fast Multimedia Library (SFML)](https://www.sfml-dev.org/index.php)

## Logical View

```mermaid
  classDiagram
    class Narrative {
        Contains the main story and switches between the CombatNarrative
         and NPCNarrative as needed. This also uses separate Menu and
          Button classes to generate graphics.
        -placeInStory: Integer
        -character: CharacterSuper
        -characterChoice[MAX_CHARACTER]: Button
    }

    class CombatNarrative{
        Handles all combat situations in the game.
        -character: CharacterSuper
        +fightDragon()
        +fightLakeMonster()
        +fightKing()
    }

    class NPCNarrative{
        Handles all conversations with other characters in the game.
        +talkToWoodsCharacter()
        +talkToLakeCharacter()
        +talkToCastleCharacter()
    }

    class Main{
        Initiates the Narrative of the story.
        -backgroundImage: Texture
        -menu: Menu
    }
    class CharacterSuper{
      Parent class for all four character types in the game.
      -health: Integer
      -armor: Integer
      -strength: Integer
      -speed: Integer
      -inventory: Inventory
      +getHealth()
      +getArmor()
      +getStrength()
      +addSpecialAbility()
      +loseHealth()
      +gainHealth()
      +gainArmor()
    }

    class Inventory{
       Inventory for characters in the game. Includes one weapon of the
        Weapon child class for each character and special abilities or
         items from the specialAbilities child class.
        -weapon: Weapon
        -Specials: Vector
        -inventoryCount: Integer
        +add()
        +isFull()
        +addSpecial()
        +getWeapons()
        +getSpecials()
    }

    class Weapon{
        -stregnth: Integer
        -getStrength()
    }

    class specialAbilities{

    }

    class Guardian{

    }

    class Swordsman{

    }

    class Ranger{

    }

    class Wizard{

    }


    Main --> Narrative : Uses
    Narrative --> CombatNarrative : Uses
    Narrative --> NPCNarrative : Uses
    CombatNarrative --> CharacterSuper : Uses
    CharacterSuper --> Inventory : Uses
    CharacterSuper <|-- Guardian : Inherits from
    CharacterSuper <|-- Ranger : Inherits from
    CharacterSuper <|-- Swordsman : Inherits from
    CharacterSuper <|-- Wizard : Inherits from
    Inventory --> Weapon : Uses
    Inventory --> SpecialAbility : Uses

```

## Process View

```mermaid
graph TD
    A(<< process >>
    Main) --> B(<< process >>
    Narrative)
    B --> C{CombatNarrative}
    B --> D{NPCNarrative}
    
    C --> G(CharacterSuper)
    D --> G
    
    G --> H(Inventory)

I(<< Player Interface >>>)
J(Window Display)-->I
K(Buttons)-->I
I-->A
```
## Use Case 

```mermaid
graph TD
    A(Start) --> B(Character Selection)
    B --> C{Ranger}
    B --> D{Swordsman}
    B --> E{Wizard}
    B --> F{Guardian}
    
    C --> G(Village)
    D --> G
    E --> G
    F --> G
    
    G --> H(Forest: talk to the suspicious stranger and fight a dragon)
    H --> I(Lake: talk to a fisherman and fight a lake monster)
    I --> J(Castle: talk to a knight and fight the king)
    
    J --> K(End Game)
```
