/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Duke.h"
#include <iostream>

Duke::Duke() : BaseCharacter(150, 15, 10) {}

int Duke::attack() {
    std::cout << "Duke attacks with powerful force.\n";
    return strength;
}

void Duke::defend(int incomingDamage) {
    int damageAfterDefense = incomingDamage - defense;
    if (damageAfterDefense < 0) damageAfterDefense = 0;
    health -= damageAfterDefense;
    std::cout << "Duke defends and takes " << damageAfterDefense << " damage.\n";
}

void Duke::absorption() {
    std::cout << "Duke uses absorption ability.\n";
}

void Duke::angry() {
    std::cout << "Duke becomes angry and increases attack strength.\n";
}

void Duke::preBattleDialogue(MainHero& hero) {
    std::cout << "\nDuke: \"So you're the one who dared to challenge me?\"\n";
    
    std::cout << "1. \"I've come to stop your madness!\"\n"
              << "2. \"I want to join you!\"\n"
              << "3. Keep quiet and attack\nChoice: ";
    
    int choice;
    std::cin >> choice;
    
    switch(choice) {
        case 1:
            hero.setStrength(hero.getStrength() + 3);
            this->setDefense(this->getDefense() - 2);
            break;
        case 2:
            this->setHealth(this->getHealth() - 15);
            break;
        default:
            break;
    }
}
