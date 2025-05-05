/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Achievements {
private:
    std::vector<std::string> unlocked;
    
public:
    void unlock(const std::string& achievement);
    void show() const;
    bool has(const std::string& achievement) const;
};
