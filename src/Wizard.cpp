/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Wizard.h"
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
    std::srand(static_cast<unsigned int>(std::time(0)));
}

int Wizard::roll_dice() {
    return 1 + std::rand() % 6;
}
