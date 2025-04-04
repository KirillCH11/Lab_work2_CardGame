/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(int hp, int str, int def)
    : health(hp), strength(str), defense(def), currentEquipment("") {}

int BaseCharacter::getHealth() const { return health; }
int BaseCharacter::getStrength() const { return strength; }
int BaseCharacter::getDefense() const { return defense; }
std::string BaseCharacter::getEquipment() const { return currentEquipment; }

void BaseCharacter::setHealth(int h) { health = h; }
void BaseCharacter::setStrength(int s) { strength = s; }
void BaseCharacter::setDefense(int d) { defense = d; }
void BaseCharacter::setEquipment(const std::string &eq) { currentEquipment = eq; }
