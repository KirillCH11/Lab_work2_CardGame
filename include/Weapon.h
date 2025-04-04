/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <string>
#include "Rarity.h"

class Weapon {
private:
    std::string type;
    Rarity rarity;
    int damage;

public:
    Weapon(const std::string &t, Rarity r, int dmg);
    void upgrade();
    void degrade();
    std::string getType() const;
    Rarity getRarity() const;
    int getDamage() const;
    std::string toString() const;
};
