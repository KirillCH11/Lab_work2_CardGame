/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Inventory.h"
#include <iostream>

void Inventory::addWeapon(std::shared_ptr<Weapon> w) { weapons.push_back(w); }
void Inventory::addArmor(std::shared_ptr<Armor> a) { armors.push_back(a); }
void Inventory::addHelmet(std::shared_ptr<Helmet> h) { helmets.push_back(h); }

void Inventory::listAll() {
    std::cout << "Weapons:\n";
    for (const auto &w : weapons) {
        std::cout << "  " << w->toString() << "\n";
    }
    std::cout << "Armors:\n";
    for (const auto &a : armors) {
        std::cout << "  " << a->toString() << "\n";
    }
    std::cout << "Helmets:\n";
    for (const auto &h : helmets) {
        std::cout << "  " << h->toString() << "\n";
    }
}
