/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "MainHero.h"
#include <iostream>

MainHero::MainHero() : BaseCharacter(100, 10, 5), chosenPath(0) {}

int MainHero::attack() {
    int totalDamage = strength + (equippedWeapon ? equippedWeapon->getDamage() : 0);
    std::cout << "Hero attacks with " << totalDamage << " damage.\n";
    return totalDamage;
}

void MainHero::defend(int incomingDamage) {
    int damageReduction = defense + (equippedArmor ? equippedArmor->getDefenseValue() : 0) + (equippedHelmet ? equippedHelmet->getBonus() : 0);
    int finalDamage = incomingDamage - damageReduction;
    if (finalDamage < 0) finalDamage = 0;
    health -= finalDamage;
    std::cout << "Hero defends and takes " << finalDamage << " damage.\n";
}

void MainHero::selectPath() {
    std::cout << "Select Path (1 - Evil, 2 - Virtue, 3 - Power): ";
    std::cin >> chosenPath;
    if (chosenPath < 1 || chosenPath > 3) {
        chosenPath = 1;
    }
}

int MainHero::getChosenPath() const { return chosenPath; }

void MainHero::equipWeapon(std::shared_ptr<Weapon> w) { equippedWeapon = w; }
void MainHero::equipArmor(std::shared_ptr<Armor> a) { equippedArmor = a; }
void MainHero::equipHelmet(std::shared_ptr<Helmet> h) { equippedHelmet = h; }

void MainHero::addToInventory(std::shared_ptr<Weapon> w) { inventory.addWeapon(w); }
void MainHero::addToInventory(std::shared_ptr<Armor> a) { inventory.addArmor(a); }
void MainHero::addToInventory(std::shared_ptr<Helmet> h) { inventory.addHelmet(h); }

void MainHero::showInventory() { inventory.listAll(); }

void MainHero::upgradeAllEquipment() {
    if (equippedWeapon) equippedWeapon->upgrade();
    if (equippedArmor) equippedArmor->upgrade();
    if (equippedHelmet) equippedHelmet->upgrade();
}

void MainHero::degradeAllEquipment() {
    if (equippedWeapon) equippedWeapon->degrade();
    if (equippedArmor) equippedArmor->degrade();
    if (equippedHelmet) equippedHelmet->degrade();
}
