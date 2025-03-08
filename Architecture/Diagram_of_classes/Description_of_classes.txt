1) BaseCharacter (Abstract Class)
Attributes: health, strength, defense, currentEquipment.
Methods: attack(), defend().
2) MainHero
Inherits from BaseCharacter.
Additional Methods: choosePath().
3) Duke
Inherits from BaseCharacter.
Additional Methods: absorb(), rage().
4) Wizard
Inherits from BaseCharacter.
Methods: startGame(), rollDice().
5) Path (Abstract Class)
Methods: takeChallenge().
6) PathOfEvil
Inherits from Path.
Contains classes for individual challenges.
7) PathOfVirtue
Inherits from Path.
Contains classes for individual challenges.
8) PathOfPower
Inherits from Path.
Contains classes for individual challenges.
9) Challenge
Attributes: description, difficulty, reward.
Methods: start(), complete().
10) Weapon
Attributes: type, rarity, damage.
Methods: upgrade(), downgrade().
11) Armor
Attributes: type, rarity, protection.
Methods: upgrade(), downgrade().
12) Helmet
Attributes: type, rarity, protectionBonus.
Methods: upgrade(), downgrade().
13) Inventory
Manages the contents: sets of items.
14) DiceGame
Methods: initiate, conclude, rollDice.
15) GameEngine
Manages game state and interactions.
16) UserInterface
Input handling, text and graphics output.
17) Storyline
Manages story transitions and progression.
18) FinalBattle
Logic for the ultimate battle and related events.
19) BadEnding
Handles conditions for a bad ending.
20) GoodEnding
Handles conditions for a good ending.
21) NeutralEnding
Handles conditions for a neutral ending.
22) BattleMechanics
Manages the participants and actions within a battle

