This diagram describes the main parts of the game, including the modules and their interactions.

Game Engine:
	1) The main module that controls the flow of the game and its states. Coordinates the interaction of all components.
	2) Interacts with the module User Interface, Storyline, Combat System.
User Interface:
	1) Is a module that processes input/output and interaction with the player.
	2) Interacts with the Game Engine to update the display and control status.
Storyline:
	1) Controls the display of the plot, the choice of paths and endings.
	2) It is coordinated through the Game Engine and interacts with Character.
Combat System:
	1) Handles the logic of battles, including trials and the final battle.
	2) Integrated with Character and Equipment.
Character:
	1) Manages character data (hero, duke, wizard).
	2) Processing characteristics and interactions through the Game Engine.
Equipment:
	1) Manages inventory and item improvement/deterioration.
	2) Integrates into the system
