/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "UserInterface.h"
#include <iostream>
#include <limits>

void UserInterface::showTitle() {
    std::cout << "========================================\n"
              << " [ TEXT RPG: Paths of Destiny ]\n"
              << "========================================\n";
}

void UserInterface::showPause() {
    std::cout << "(Press Enter to continue...)\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

