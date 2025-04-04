/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "GameEngine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameEngine::GameEngine() : diceGame(wizard, hero) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void GameEngine::run() {
    UserInterface::showTitle();
    Storyline::showIntro();
    hero.selectPath();
    switch(hero.getChosenPath()) {
        case 1: chosenPath = std::make_unique<PathOfEvil>(); break;
        case 2: chosenPath = std::make_unique<PathOfVirtue>(); break;
        case 3: chosenPath = std::make_unique<PathOfPower>(); break;
        default: chosenPath = std::make_unique<PathOfEvil>(); break;
    }
    bool success = chosenPath->take_challenge(hero);
    if(!success) {
        std::cout << "The hero died during the trials...\nGame Over.\n";
        return;
    }

    Storyline::showAfterPath();
    std::cout << "Wizard: 'Do you want to play dice or just ignore me?' (1 - play / 2 - ignore)\n";
    int choice=0;
    std::cin >> choice;
    if (choice == 1) {
        diceGame.start();
        for(int i = 0; i < 3; i++) {
            diceGame.processRound();
        }
        diceGame.end();
    } else {
        std::cout << "You ignored the wizard...\n";
    }

    std::cout << "\n--- Would you like to check your inventory? (1 - yes, 0 - no): ";
    int invChoice = 0;
    std::cin >> invChoice;
    if (invChoice == 1) {
        hero.showInventory();
    }

    Storyline::showBeforeFinal();
    UserInterface::showPause();
    FinalBattle::startFinal(hero);
}
