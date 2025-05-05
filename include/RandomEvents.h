/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include "MainHero.h"
#include <memory>

class RandomEvent {
public:
    virtual ~RandomEvent() = default;
    virtual void trigger(MainHero& hero) = 0;
};

class BanditEncounter : public RandomEvent {
public:
    void trigger(MainHero& hero) override;
};

std::unique_ptr<RandomEvent> createRandomEvent();
