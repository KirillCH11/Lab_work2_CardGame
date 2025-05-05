/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Storyline.h"
#include <iostream>

void Storyline::showIntro() {
    std::cout << "Rumors have spread about the local duke's madness.\n"
              << "They say he changed drastically after returning from an excavation site...\n";
}

void Storyline::showAfterPath() {
    std::cout << "\nApproaching the castle, you encounter a Wizard.\n"
              << "He speaks of a strange artifact that drove the duke insane.\n";
}

void Storyline::showBeforeFinal() {
    std::cout << "You enter the castle... In the throne room rests the sword 'Soul Executioner',\n"
              << " radiating a dark aura. The Duke is waiting!\n";
}
