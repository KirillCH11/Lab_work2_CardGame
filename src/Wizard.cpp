/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Wizard.h"
#include "DiceGame.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Wizard::Wizard() : BaseCharacter(80, 12, 4) {}

int Wizard::attack() {
    std::cout << "Wizard attacks with magic spell.\n";
    return strength;
}

void Wizard::defend(int incomingDamage) {
    int damageAfterDefense = incomingDamage - defense;
    if (damageAfterDefense < 0) damageAfterDefense = 0;
    health -= damageAfterDefense;
    std::cout << "Wizard defends and takes " << damageAfterDefense << " damage.\n";
}

void Wizard::start_game() {
    std::cout << "Wizard starts the dice game.\n";
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int Wizard::roll_dice() {
    return 1 + std::rand() % 6;
}

void Wizard::offerDiceGame(MainHero& hero) {
    std::cout << "\nWizard: \"Welcome, ";
    switch(hero.getChosenPath()) {
        case 1: std::cout << "Follower of darkness"; break;
        case 2: std::cout << "The light carrier"; break;
        case 3: std::cout << "The power Seeker"; break;
    }
    
    std::cout << "! I can feel the potential in you....\n"
              << "Will we play dice? Victory will strengthen your spirit, defeat... Well, you got it.\n"
              << "1. Agree (take a chance)\n"
              << "2. Give up (lose 2 powers)\n"
              << "Choice: ";
    
    int choice;
    std::cin >> choice;
    
    if(choice == 1) {
        std::cout << "\nWizard: \"Perfect! Roll the dice!\"\n";
        DiceGame game(*this, hero);
        game.start();
        for(int i = 0; i < 3; i++) {
            game.processRound();
        }
        game.end();
        hero.getAchievements().unlock("The dice player");
    } else {
        std::cout << "\nWizard: \"What a pity... You're missing your chance.\"\n";
        hero.setStrength(hero.getStrength() - 2);
    }
}
