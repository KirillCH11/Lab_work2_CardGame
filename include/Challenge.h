/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <string>
#include "MainHero.h"

class Challenge {
protected:
    std::string description;
    int difficulty;
    std::string reward;

public:
    Challenge(const std::string &desc, int diff, const std::string &rew);
    virtual ~Challenge(){}
    virtual void start() = 0;
    virtual void finish() = 0;
    std::string getDescription() const;
    int getDifficulty() const;
    std::string getReward() const;
};

class ChallengeBats : public Challenge {
public:
    ChallengeBats();
    void start() override;
    void finish() override;
    bool doChallenge(MainHero &hero);
};

class ChallengeOgre : public Challenge {
public:
    ChallengeOgre();
    void start() override;
    void finish() override;
    bool doChallenge(MainHero &hero);
};

class ChallengeRiddle : public Challenge {
public:
    ChallengeRiddle();
    void start() override;
    void finish() override;
    bool doChallenge(MainHero &hero);
};
