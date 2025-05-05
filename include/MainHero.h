/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <memory>
#include "BaseCharacter.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Achievements.h"

class MainHero : public BaseCharacter {
private:
    Inventory inventory;
    Achievements achievements;
    std::shared_ptr<Weapon> equippedWeapon;
    std::shared_ptr<Armor> equippedArmor;
    std::shared_ptr<Helmet> equippedHelmet;
    int chosenPath;

public:
    MainHero();
    virtual ~MainHero(){}
    int attack() override;
    void defend(int incomingDamage) override;
    void selectPath();
    int getChosenPath() const;
    void equipWeapon(std::shared_ptr<Weapon> w);
    void equipArmor(std::shared_ptr<Armor> a);
    void equipHelmet(std::shared_ptr<Helmet> h);
    void addToInventory(std::shared_ptr<Weapon> w);
    void addToInventory(std::shared_ptr<Armor> a);
    void addToInventory(std::shared_ptr<Helmet> h);
    void showInventory();
    void upgradeAllEquipment();
    void degradeAllEquipment();
    Achievements& getAchievements() { return achievements; }
    const Achievements& getAchievements() const { return achievements; }
};
