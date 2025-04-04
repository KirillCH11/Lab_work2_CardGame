/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include "Wizard.h"
#include "MainHero.h"

class DiceGame {
private:
    Wizard &wizard;
    MainHero &hero;
    bool isActive;
    int heroWins;
    int wizardWins;
    int rounds;

public:
    DiceGame(Wizard &w, MainHero &h);
    void start();
    void processRound();
    void end();
    int heroRollDice();
};
