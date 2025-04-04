/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "DiceGame.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

DiceGame::DiceGame(Wizard &w, MainHero &h) : wizard(w), hero(h), isActive(false), heroWins(0), wizardWins(0), rounds(0) {}

void DiceGame::start() {
    isActive = true;
    heroWins = 0;
    wizardWins = 0;
    rounds = 0;
    wizard.start_game();
    std::cout << "(Press Enter when prompted to roll the dice)\n";
}

void DiceGame::processRound() {
    if (!isActive) return;
    if (rounds >= 3) {
        std::cout << "All 3 rounds have been played!\n";
        return;
    }
    rounds++;
    std::cout << "Press Enter to roll dice for round " << rounds << "...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int heroRollVal = heroRollDice();
    int wizardRollVal = wizard.roll_dice();
    std::cout << "[Round " << rounds << "]: Hero rolled " << heroRollVal << ", Wizard rolled " << wizardRollVal << "\n";
    if (heroRollVal > wizardRollVal) {
        heroWins++;
        std::cout << "(Hero wins this round)\n";
    } else if (wizardRollVal > heroRollVal) {
        wizardWins++;
        std::cout << "(Wizard wins this round)\n";
    } else {
        std::cout << "(Round is a draw)\n";
    }
}

void DiceGame::end() {
    isActive = false;
    std::cout << "Dice game results: Hero " << heroWins << " vs. " << wizardWins << " Wizard\n";
    if (heroWins >= 2) {
        std::cout << "Hero wins the dice game! Upgrading equipment.\n";
        hero.upgradeAllEquipment();
    } else {
        std::cout << "Hero did not achieve 2 round-wins... Downgrading equipment.\n";
        hero.degradeAllEquipment();
    }
}

int DiceGame::heroRollDice() {
    int d1 = 1 + std::rand() % 6;
    int d2 = 1 + std::rand() % 6;
    return d1 + d2;
}
