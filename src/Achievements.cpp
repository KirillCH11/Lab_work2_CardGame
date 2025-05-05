/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Achievements.h"
#include <algorithm>

void Achievements::unlock(const std::string& achievement) {
    if(!has(achievement)) {
        unlocked.push_back(achievement);
        std::cout << "\n=== THE ACHIEVEMENT IS UNLOCKED: " << achievement << " ===\n";
    }
}

void Achievements::show() const {
    if(unlocked.empty()) {
        std::cout << "You don't have any achievements yet\n";
        return;
    }
    
    std::cout << "\n=== YOUR ACHIEVEMENTS ===\n";
    for(const auto& a : unlocked) {
        std::cout << "- " << a << "\n";
    }
}

bool Achievements::has(const std::string& achievement) const {
    return std::find(unlocked.begin(), unlocked.end(), achievement) != unlocked.end();
}
