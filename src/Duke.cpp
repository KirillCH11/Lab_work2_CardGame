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
