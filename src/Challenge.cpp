/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Challenge.h"
#include <iostream>

Challenge::Challenge(const std::string &desc, int diff, const std::string &rew)
    : description(desc), difficulty(diff), reward(rew) {}

std::string Challenge::getDescription() const { return description; }
int Challenge::getDifficulty() const { return difficulty; }
std::string Challenge::getReward() const { return reward; }

ChallengeBats::ChallengeBats() : Challenge("Challenge: Defeat Bats", 1, "Bat Wing") {}

void ChallengeBats::start() { std::cout << "Starting bat challenge.\n"; }
void ChallengeBats::finish() { std::cout << "Finishing bat challenge.\n"; }

bool ChallengeBats::doChallenge(MainHero &hero) {
    std::cout << "Hero is defeating bats.\n";
    hero.setHealth(hero.getHealth() - 5);
    return true;
}

ChallengeOgre::ChallengeOgre() : Challenge("Challenge: Defeat Ogre", 2, "Ogre Club") {}

void ChallengeOgre::start() { std::cout << "Starting ogre challenge.\n"; }
void ChallengeOgre::finish() { std::cout << "Finishing ogre challenge.\n"; }

bool ChallengeOgre::doChallenge(MainHero &hero) {
    std::cout << "Hero is defeating ogre.\n";
    hero.setStrength(hero.getStrength() + 1);
    return true;
}

ChallengeRiddle::ChallengeRiddle() : Challenge("Challenge: Solve Riddle", 3, "Ancient Tome") {}

void ChallengeRiddle::start() { std::cout << "Starting riddle challenge.\n"; }
void ChallengeRiddle::finish() { std::cout << "Finishing riddle challenge.\n"; }

bool ChallengeRiddle::doChallenge(MainHero &hero) {
    std::cout << "Hero is solving riddle.\n";
    hero.setDefense(hero.getDefense() + 1);
    return true;
}
