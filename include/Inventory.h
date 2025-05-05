/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <vector>
#include <memory>
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"

class Inventory {
private:
    std::vector<std::shared_ptr<Weapon>> weapons;
    std::vector<std::shared_ptr<Armor>> armors;
    std::vector<std::shared_ptr<Helmet>> helmets;

public:
    Inventory() {}
    void addWeapon(std::shared_ptr<Weapon> w);
    void addArmor(std::shared_ptr<Armor> a);
    void addHelmet(std::shared_ptr<Helmet> h);
    void listAll();
};
