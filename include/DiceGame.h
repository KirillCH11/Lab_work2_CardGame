/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include "MainHero.h"

class Wizard; 

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
    bool isGameActive() const { return isActive; }
    int getHeroWins() const { return heroWins; }
    int getWizardWins() const { return wizardWins; }
    int getRounds() const { return rounds; }
};
