/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Weapon.h"

Weapon::Weapon(const std::string &t, Rarity r, int dmg)
    : type(t), rarity(r), damage(dmg) {}

void Weapon::upgrade() {
    rarity = upgradeRarity(rarity);
    damage++;
}

void Weapon::degrade() {
    rarity = downgradeRarity(rarity);
    if (damage > 0) damage--;
}

std::string Weapon::getType() const { return type; }
Rarity Weapon::getRarity() const { return rarity; }
int Weapon::getDamage() const { return damage; }

std::string Weapon::toString() const {
    return type + " (" + std::to_string(damage) + " damage, " + std::to_string(static_cast<int>(rarity)) + ")";
}
