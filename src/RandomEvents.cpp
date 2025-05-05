/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "RandomEvents.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void BanditEncounter::trigger(MainHero& hero) {
    std::srand(std::time(0));
    int chance = 30 + hero.getChosenPath() * 10;
    
    if((std::rand() % 100) < chance) {
        std::cout << "\n=== A SUDDEN EVENT ===\n"
                  << "A group of bandits blocked your path!\n"
                  << "1. Try to negotiate\n"
                  << "2. To attack\n"
                  << "3. To escape\nChoice: ";
        
        int choice;
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                if(hero.getChosenPath() == 2) {
                    auto weapon = std::make_shared<Weapon>("An old sword", Rarity::U, 3);
                    hero.addToInventory(weapon);
                    hero.getAchievements().unlock("The diplomat");
                    std::cout << "The bandits are impressed by your honesty and give you gifts " << weapon->toString() << "!\n";
                } else {
                    hero.setStrength(hero.getStrength() - 1);
                    std::cout << "The bandits are laughing and taking your money! (-1 to strength)\n";
                }
                break;
                
            case 2:
                break;
                
            case 3:
                break;
        }
    }
}

std::unique_ptr<RandomEvent> createRandomEvent() {
    std::srand(std::time(0));
    if((std::rand() % 3) == 0) {
        return std::make_unique<BanditEncounter>();
    }
    return nullptr;
}
