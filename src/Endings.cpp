/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Endings.h"
#include <iostream>

void BadEnding::playEnding() {
    std::cout << "BAD Ending: The hero kills the duke but becomes possessed by the dark spirit!\n";
}

void GoodEnding::playEnding() {
    std::cout << "GOOD Ending: The hero destroys the cursed sword,\n" << " freeing the duke from the evil spirit!\n" << "The grateful duke rewards the hero generously.\n";
}

void NeutralEnding::playEnding() {
    std::cout << "NEUTRAL Ending: The hero kills the duke using the mighty artifact,\n" << " simultaneously destroying the ancient spirit.\n" << "The hero then becomes the new ruler (the new duke).\n";
}
