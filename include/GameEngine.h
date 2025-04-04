/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <memory>
#include "MainHero.h"
#include "Path.h"
#include "Wizard.h"
#include "DiceGame.h"
#include "UserInterface.h"
#include "Storyline.h"
#include "FinalBattle.h"

class GameEngine {
private:
    MainHero hero;
    std::unique_ptr<Path> chosenPath;
    Wizard wizard;
    DiceGame diceGame;

public:
    GameEngine();
    void run();
};
