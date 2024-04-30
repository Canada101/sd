# Project Group 5: Choose Your Adventure Game

## Project Overview
The goal of this project is to develop a version of a Choose Your Own Adventure game. The storyline takes you through various scenarios, such as: interacting with strangers, fighting monsters, and ending with the ultimate goal of confronting the king of the village.

The game provides the player with multiple options to choose from, providing the ability of negatively or positively impacting the gameplay and leading to various outcomes.

## Compiling and Running the Program
### How to Compile:
In order to compile the game, ensure you have `clang` or `g++` installed on your system.

To compile the program, run the following command:
`* make`

### How to Run:
After compiling the program, use the following command to execute the game:
`* ./main`

## Compatable OSes
As of currently, this game has only been run and tested on MacOS systems.

## System Requirements
This game is able to be run on any system capable of running C++.

## Library Requirements
This game uses the standard C++ library, along with:
* The Simple and Fast Multimedia Library (SFML)
* In order to run this game, you must ensure you have SFML downloaded on your system. To install SFML, use this link: https://www.sfml-dev.org/download.php

## Logical View

```mermaid
  classDiagram
    class Narrative {
        -placeInStory: Integer
        -character: CharacterSuper
        -characterChoice[MAX_CHARACTER]: Button
        Manages place in story, handling
        all user interactions such as character 
        selections and choices in the storyline.
    }

    class CombatNarrative{
        -character: CharacterSuper
        +fightDragon()
        +fightLakeMonster()
        +fightKing()
    }

    class NPCNarrative{
        +talkToWoodsCharacter()
        +talkToLakeCharacter()
        +talkToCastleCharacter()
    }

    class Main{
        -backgroundImage: Texture
        -menu: Menu
        Runs the display window,
        continues to loop through
        different screens including
        any background images,
        terminates when game is over. 
    }
    class CharacterSuper{
      -health: Integer
      -armor: Integer
      -strength: Integer
      -speed: Integer
      -inventory: Inventory
      +GetHealth()
      +MaxHealth()
      +GetArmor()
      +GetStrength()
      +GetSpeed()
      +getWeapons()
      +getSpecials()
      +addSpecialAbility()
      +displayInventory()
      +discardWeapon()
      +WeaponsEmpty()
      +WeaponsFull()
      +swapWeapons()
      +loseHealth()
      +gainHealth()
      +loseArmor()
      +gainArmor()
    }

    class Inventory{
        -Weapons: Vector
        -Specials: Vector
        -inventoryCount: Integer
        +add()
        +swapWeapons()
        +isFull()
        +displayWeapon()
        +discardWeapon()
        +displaySpecials()
        +addSpecial()
        +getWeapons()
        +getSpecials()
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
    CharacterSuper <|-- Guardian 
    CharacterSuper <|-- Ranger
    CharacterSuper <|-- Swordsman
    CharacterSuper <|-- Wizard

```

## Process View

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
    
    G --> H(Forest)
    H --> I(Lake)
    I --> J(Castle)
    
    J --> K(End Game)
```
## Use Case 

```mermaid
graph TD
  A(user) --> B(selects character)
  B --> C(story narrative)

    A->>B: Selects character
    B->>C: Story narrative
    activate C

    A->>F: Enters choice
    F->>C: Choice processed
    deactivate C

    G->>H: Switch narrative
    F->>D: NPC narrative (optional)
    F->>E: Combat narrative (optional)
    activate D
    activate E

    D->>H: NPC response
    E->>H: Combat outcome
    deactivate D
    deactivate E

```
