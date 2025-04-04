/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Armor.h"

Armor::Armor(const std::string &t, Rarity r, int def)
    : type(t), rarity(r), defense(def) {}

void Armor::upgrade() {
    rarity = upgradeRarity(rarity);
    defense++;
}

void Armor::degrade() {
    rarity = downgradeRarity(rarity);
    if (defense > 0) defense--;
}

std::string Armor::getType() const { return type; }
Rarity Armor::getRarity() const { return rarity; }
int Armor::getDefenseValue() const { return defense; }

std::string Armor::toString() const {
    return type + " (" + std::to_string(defense) + " defense, " + std::to_string(static_cast<int>(rarity)) + ")";
}
