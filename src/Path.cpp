/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Path.h"
#include <iostream>
#include <cstdlib>

Rarity PathOfEvil::getRandomRarity() {
    int r = std::rand()%100;
    if (r < 60) return Rarity::U;
    if (r < 90) return Rarity::R;
    return Rarity::SR;
}

std::shared_ptr<Weapon> PathOfEvil::getRandomWeapon() {
    Rarity rar = getRandomRarity();
    int dmg = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Weapon>("Sword of Darkness", rar, dmg);
}

std::shared_ptr<Armor> PathOfEvil::getRandomArmor() {
    Rarity rar = getRandomRarity();
    int def = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Armor>("Dark Shield", rar, def);
}

std::shared_ptr<Helmet> PathOfEvil::getRandomHelmet() {
    Rarity rar = getRandomRarity();
    int bonus = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Helmet>("Helm of Shadows", rar, bonus);
}

bool PathOfEvil::take_challenge(MainHero &hero) {
    bats.start();
    bool success = bats.doChallenge(hero);
    bats.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a weapon (1/2/3): ";
    int chest = 0;
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto w = getRandomWeapon();
    std::cout << "You receive: " << w->toString() << "\n";
    hero.addToInventory(w);
    hero.equipWeapon(w);

    ogre.start();
    success = ogre.doChallenge(hero);
    ogre.finish();
    if (!success) return false;

    std::cout << "Choose a chest for armor (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto a = getRandomArmor();
    std::cout << "You receive: " << a->toString() << "\n";
    hero.addToInventory(a);
    hero.equipArmor(a);

    riddle.start();
    success = riddle.doChallenge(hero);
    riddle.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a helmet (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto h = getRandomHelmet();
    std::cout << "You receive: " << h->toString() << "\n";
    hero.addToInventory(h);
    hero.equipHelmet(h);

    return true;
}

Rarity PathOfVirtue::getRandomRarity() {
    int r = std::rand()%100;
    if (r < 50) return Rarity::U;
    if (r < 85) return Rarity::R;
    return Rarity::SR;
}

std::shared_ptr<Weapon> PathOfVirtue::getRandomWeapon() {
    Rarity rar = getRandomRarity();
    int dmg = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 3 : 5;
    return std::make_shared<Weapon>("Sword of Light", rar, dmg);
}

std::shared_ptr<Armor> PathOfVirtue::getRandomArmor() {
    Rarity rar = getRandomRarity();
    int def = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 4 : 6;
    return std::make_shared<Armor>("Armor of Virtue", rar, def);
}

std::shared_ptr<Helmet> PathOfVirtue::getRandomHelmet() {
    Rarity rar = getRandomRarity();
    int bonus = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 4;
    return std::make_shared<Helmet>("Helm of Wisdom", rar, bonus);
}

bool PathOfVirtue::take_challenge(MainHero &hero) {
    bats.start();
    bool success = bats.doChallenge(hero);
    bats.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a weapon (1/2/3): ";
    int chest = 0;
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto w = getRandomWeapon();
    std::cout << "You receive: " << w->toString() << "\n";
    hero.addToInventory(w);
    hero.equipWeapon(w);

    ogre.start();
    success = ogre.doChallenge(hero);
    ogre.finish();
    if (!success) return false;

    std::cout << "Choose a chest for armor (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto a = getRandomArmor();
    std::cout << "You receive: " << a->toString() << "\n";
    hero.addToInventory(a);
    hero.equipArmor(a);

    riddle.start();
    success = riddle.doChallenge(hero);
    riddle.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a helmet (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto h = getRandomHelmet();
    std::cout << "You receive: " << h->toString() << "\n";
    hero.addToInventory(h);
    hero.equipHelmet(h);

    return true;
}

Rarity PathOfPower::getRandomRarity() {
    int r = std::rand()%100;
    if (r < 40) return Rarity::U;
    if (r < 80) return Rarity::R;
    return Rarity::SR;
}

std::shared_ptr<Weapon> PathOfPower::getRandomWeapon() {
    Rarity rar = getRandomRarity();
    int dmg = (rar == Rarity::U) ? 2 : (rar == Rarity::R) ? 4 : 6;
    return std::make_shared<Weapon>("Hammer of Strength", rar, dmg);
}

std::shared_ptr<Armor> PathOfPower::getRandomArmor() {
    Rarity rar = getRandomRarity();
    int def = (rar == Rarity::U) ? 2 : (rar == Rarity::R) ? 5 : 8;
    return std::make_shared<Armor>("Armor of Titans", rar, def);
}

std::shared_ptr<Helmet> PathOfPower::getRandomHelmet() {
    Rarity rar = getRandomRarity();
    int bonus = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 3 : 5;
    return std::make_shared<Helmet>("Helm of Domination", rar, bonus);
}

bool PathOfPower::take_challenge(MainHero &hero) {
    bats.start();
    bool success = bats.doChallenge(hero);
    bats.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a weapon (1/2/3): ";
    int chest = 0;
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto w = getRandomWeapon();
    std::cout << "You receive: " << w->toString() << "\n";
    hero.addToInventory(w);
    hero.equipWeapon(w);

    ogre.start();
    success = ogre.doChallenge(hero);
    ogre.finish();
    if (!success) return false;

    std::cout << "Choose a chest for armor (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto a = getRandomArmor();
    std::cout << "You receive: " << a->toString() << "\n";
    hero.addToInventory(a);
    hero.equipArmor(a);

    riddle.start();
    success = riddle.doChallenge(hero);
    riddle.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a helmet (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest < 1 || chest > 3) {
        chest = 1;
    }
    auto h = getRandomHelmet();
    std::cout << "You receive: " << h->toString() << "\n";
    hero.addToInventory(h);
    hero.equipHelmet(h);

    return true;
}
