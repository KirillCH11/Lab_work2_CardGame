/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <string>
#include "Rarity.h"

class Armor {
private:
    std::string type;
    Rarity rarity;
    int defense;

public:
    Armor(const std::string &t, Rarity r, int def);
    void upgrade();
    void degrade();
    std::string getType() const;
    Rarity getRarity() const;
    int getDefenseValue() const;
    std::string toString() const;
};
