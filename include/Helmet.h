/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <string>
#include "Rarity.h"

class Helmet {
private:
    std::string type;
    Rarity rarity;
    int defenseBonus;

public:
    Helmet(const std::string &t, Rarity r, int bonus);
    void upgrade();
    void degrade();
    std::string getType() const;
    Rarity getRarity() const;
    int getBonus() const;
    std::string toString() const;
};

