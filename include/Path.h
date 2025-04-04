/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <memory>
#include "MainHero.h"
#include "Challenge.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Rarity.h"

class Path {
public:
    virtual ~Path(){}
    virtual bool take_challenge(MainHero &hero) = 0;
};

class PathOfEvil : public Path {
private:
    ChallengeBats bats;
    ChallengeOgre ogre;
    ChallengeRiddle riddle;

public:
    bool take_challenge(MainHero &hero) override;
    std::shared_ptr<Weapon> getRandomWeapon();
    std::shared_ptr<Armor> getRandomArmor();
    std::shared_ptr<Helmet> getRandomHelmet();
    Rarity getRandomRarity();
};

class PathOfVirtue : public Path {
private:
    ChallengeBats bats;
    ChallengeOgre ogre;
    ChallengeRiddle riddle;

public:
    bool take_challenge(MainHero &hero) override;
    std::shared_ptr<Weapon> getRandomWeapon();
    std::shared_ptr<Armor> getRandomArmor();
    std::shared_ptr<Helmet> getRandomHelmet();
    Rarity getRandomRarity();
};

class PathOfPower : public Path {
private:
    ChallengeBats bats;
    ChallengeOgre ogre;
    ChallengeRiddle riddle;

public:
    bool take_challenge(MainHero &hero) override;
    std::shared_ptr<Weapon> getRandomWeapon();
    std::shared_ptr<Armor> getRandomArmor();
    std::shared_ptr<Helmet> getRandomHelmet();
    Rarity getRandomRarity();
};
