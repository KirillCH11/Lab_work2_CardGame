/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "FinalBattle.h"
#include <iostream>

void FinalBattle::startFinal(MainHero &hero) {
    Duke duke;
    duke.preBattleDialogue(hero);
    
    bool result = BattleMechanics::battle(hero, duke, false);
    if(result) {
        hero.getAchievements().unlock("Duke's Winner");
        
        int path = hero.getChosenPath();
        if(path == 1) {
            BadEnding::playEnding();
            hero.getAchievements().unlock("The Dark Lord");
        } else if(path == 2) {
            GoodEnding::playEnding();
            hero.getAchievements().unlock("The Savior of the Kingdom");
        } else {
            NeutralEnding::playEnding();
            hero.getAchievements().unlock("The New Ruler");
        }
    } else {
        std::cout << "The hero was slain in the final battle...\n";
    }
}
