/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "GameEngine.h"
#include "RandomEvents.h"
#include <iostream>
#include <ctime>
#include "Wizard.h"

GameEngine::GameEngine() : diceGame(wizard, hero) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void GameEngine::run() {
    UserInterface::showTitle();
    Storyline::showIntro();
    UserInterface::showPause();
    
    hero.selectPath();
    
    if(auto event = createRandomEvent()) {
        event->trigger(hero);
        UserInterface::showPause();
    }
    
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
    UserInterface::showPause();
    
    wizard.offerDiceGame(hero);
    UserInterface::showPause();
    
    std::cout << "\n--- Would you like to check your inventory? (1 - yes, 0 - no): ";
    int invChoice = 0;
    std::cin >> invChoice;
    if(invChoice == 1) {
        hero.showInventory();
        UserInterface::showPause();
    }
    
    Storyline::showBeforeFinal();
    UserInterface::showPause();
    
    Duke duke;
    duke.preBattleDialogue(hero);
    FinalBattle::startFinal(hero);
    
    hero.getAchievements().show();
}
