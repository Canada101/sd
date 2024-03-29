# Project Group 5 Video Game Read-Me

# How to Compile
This game can be compiled with the following compilers:
* clang
* g++

# Compatable OSes
This game is compatible with both Windows and MacOS

# System Requirements
This game is able to be run on any system capable of running C++

# Library Requirements
This game currently uses the Standard C++ Library

# Logical View

```mermaid
  classDiagram
    class NarrativeSuper {

    }

    class StoryNarrative{

    }

    class Main { 
     
    }

    class CharacterSuper{
      -Health: Integer
      -Armor: Integer
      -Strength: Integer
      -Speed: Integer
      -Inventory: vector<String>
      -SpecialAbilities: vector<String>
      +GetHealth()
      +GetArmor()
      +GetStregth()
      +GetSpeed()
      +getSpecialAbilities()
      +addSpecialAbilities()
      +getInventory()
      +addToInventory()
      +loseHealth()
      +gainHealth()
    }

    class Guardian{

    }

    class Swordsman{

    }

    class Ranger{

    }

    class Wizard{

    }


    Main --> NarrativeSuper : Has
    NarrativeSuper --> StoryNarrative : Has
    StoryNarrative --> CharacterSuper : Has
    CharacterSuper <|-- Guardian 
    CharacterSuper <|-- Ranger
    CharacterSuper <|-- Swordsman
    CharacterSuper <|-- Wizard
```

# Process View

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
# Use Case 
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
