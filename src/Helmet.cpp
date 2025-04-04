/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Helmet.h"

Helmet::Helmet(const std::string &t, Rarity r, int bonus)
    : type(t), rarity(r), defenseBonus(bonus) {}

void Helmet::upgrade() {
    rarity = upgradeRarity(rarity);
    defenseBonus++;
}

void Helmet::degrade() {
    rarity = downgradeRarity(rarity);
    if (defenseBonus > 0) defenseBonus--;
}

std::string Helmet::getType() const { return type; }
Rarity Helmet::getRarity() const { return rarity; }
int Helmet::getBonus() const { return defenseBonus; }

std::string Helmet::toString() const {
    return type + " (" + std::to_string(defenseBonus) + " bonus, " + std::to_string(static_cast<int>(rarity)) + ")";
}
