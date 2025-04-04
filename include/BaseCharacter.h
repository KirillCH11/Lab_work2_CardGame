/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#pragma once
#include <string>

class BaseCharacter {
protected:
    int health;
    int strength;
    int defense;
    std::string currentEquipment;

public:
    BaseCharacter(int hp, int str, int def);
    virtual ~BaseCharacter() {}
    // Getters/Setters
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    std::string getEquipment() const;
    void setHealth(int h);
    void setStrength(int s);
    void setDefense(int d);
    void setEquipment(const std::string &eq);
    virtual int attack() = 0;
    virtual void defend(int incomingDamage) = 0;
};
