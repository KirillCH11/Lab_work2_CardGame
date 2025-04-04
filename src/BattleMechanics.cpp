/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "BattleMechanics.h"
#include <iostream>
#include <limits>

bool BattleMechanics::battle(MainHero &hero, Duke &duke) {
    std::cout << "\n--- Final battle with the Duke! ---\n";
    int timeCounter = 0;
    while (duke.getHealth() > 0 && hero.getHealth() > 0) {
        std::cout << "(Hero turn: 'a' to attack / 'd' to defend) > ";
        char action;
        std::cin >> action;
        if (action == 'a' || action == 'A') {
            int dmg = hero.attack();
            duke.defend(dmg);
        } else if (action == 'd' || action == 'D') {
            std::cout << "You prepare to defend, reducing incoming damage.\n";
        } else {
            std::cout << "Invalid command, you skip your turn.\n";
        }
        
        if (duke.getHealth() <= 0) {
            std::cout << "The Duke is defeated!\n";
            break;
        }

        int dukeDamage = duke.attack();
        if (action == 'd' || action == 'D') {
            dukeDamage /= 2;
        }
        hero.defend(dukeDamage);

        if (hero.getHealth() <= 0) {
            std::cout << "The hero has fallen...\n";
            break;
        }

        // Every 2 cycles (~10 seconds):
        timeCounter += 5;
        if (timeCounter >= 10) {
            std::cout << "[Mighty Soul Wave] The Duke unleashes a -3 HP wave!\n";
            hero.setHealth(hero.getHealth() - 3);
            if (hero.getHealth() <= 0) {
                std::cout << "Hero did not survive the wave...\n";
                break;
            }
            timeCounter = 0;
        }
    }
    return (hero.getHealth() > 0 && duke.getHealth() <= 0);
}
