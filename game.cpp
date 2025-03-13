/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "game.h"
#include <cstdlib>
#include <ctime>
#include <limits>


std::string rarityToString(Rarity r) {
    switch(r) {
        case Rarity::U:  return "Common (U)";
        case Rarity::R:  return "Rare (R)";
        case Rarity::SR: return "Super Rare (SR)";
    }
    return "UNKNOWN";
}

Rarity upgradeRarity(Rarity r) {
    switch(r) {
        case Rarity::U:  return Rarity::R;
        case Rarity::R:  return Rarity::SR;
        case Rarity::SR: return Rarity::SR;
    }
    return Rarity::SR;
}

Rarity downgradeRarity(Rarity r) {
    switch(r) {
        case Rarity::SR: return Rarity::R;
        case Rarity::R:  return Rarity::U;
        case Rarity::U:  return Rarity::U;
    }
    return Rarity::U;
}

// BaseCharacter
BaseCharacter::BaseCharacter(int hp, int str, int def)
    : health(hp), strength(str), defense(def), currentEquipment("")
{
}

int BaseCharacter::getHealth() const {
    return health;
}
int BaseCharacter::getStrength() const {
    return strength;
}
int BaseCharacter::getDefense() const {
    return defense;
}
std::string BaseCharacter::getEquipment() const {
    return currentEquipment;
}

void BaseCharacter::setHealth(int h) {
    health = h;
}
void BaseCharacter::setStrength(int s) {
    strength = s;
}
void BaseCharacter::setDefense(int d) {
    defense = d;
}
void BaseCharacter::setEquipment(const std::string &eq) {
    currentEquipment = eq;
}


// Weapon
Weapon::Weapon(const std::string &t, Rarity r, int dmg)
    : type(t), rarity(r), damage(dmg)
{
}
void Weapon::upgrade() {
    rarity = upgradeRarity(rarity);
}
void Weapon::degrade() {
    rarity = downgradeRarity(rarity);
}
std::string Weapon::getType() const {
    return type;
}
Rarity Weapon::getRarity() const {
    return rarity;
}
int Weapon::getDamage() const {
    return damage;
}
std::string Weapon::toString() const {
    return "Weapon: " + type + ", Rarity: " + rarityToString(rarity)
           + ", Damage: " + std::to_string(damage);
}

// Armor
Armor::Armor(const std::string &t, Rarity r, int def)
    : type(t), rarity(r), defense(def)
{
}
void Armor::upgrade() {
    rarity = upgradeRarity(rarity);
}
void Armor::degrade() {
    rarity = downgradeRarity(rarity);
}
std::string Armor::getType() const {
    return type;
}
Rarity Armor::getRarity() const {
    return rarity;
}
int Armor::getDefenseValue() const {
    return defense;
}
std::string Armor::toString() const {
    return "Armor: " + type + ", Rarity: " + rarityToString(rarity)
           + ", Defense: " + std::to_string(defense);
}


// Helmet
Helmet::Helmet(const std::string &t, Rarity r, int bonus)
    : type(t), rarity(r), defenseBonus(bonus)
{
}
void Helmet::upgrade() {
    rarity = upgradeRarity(rarity);
}
void Helmet::degrade() {
    rarity = downgradeRarity(rarity);
}
std::string Helmet::getType() const {
    return type;
}
Rarity Helmet::getRarity() const {
    return rarity;
}
int Helmet::getBonus() const {
    return defenseBonus;
}
std::string Helmet::toString() const {
    return "Helmet: " + type + ", Rarity: " + rarityToString(rarity)
           + ", Defense Bonus: " + std::to_string(defenseBonus);
}


// Inventory
void Inventory::addWeapon(std::shared_ptr<Weapon> w) {
    weapons.push_back(w);
}
void Inventory::addArmor(std::shared_ptr<Armor> a) {
    armors.push_back(a);
}
void Inventory::addHelmet(std::shared_ptr<Helmet> h) {
    helmets.push_back(h);
}
void Inventory::listAll() {
    std::cout << "----- Inventory -----\n";
    std::cout << "Weapons:\n";
    for (auto &w : weapons) {
        std::cout << "  * " << w->toString() << "\n";
    }
    std::cout << "Armors:\n";
    for (auto &a : armors) {
        std::cout << "  * " << a->toString() << "\n";
    }
    std::cout << "Helmets:\n";
    for (auto &h : helmets) {
        std::cout << "  * " << h->toString() << "\n";
    }
    std::cout << "---------------------\n";
}


// MainHero
MainHero::MainHero()
    : BaseCharacter(1, 5, 0), chosenPath(0)
{
}
int MainHero::attack() {
    int weaponDamage = 0;
    if (equippedWeapon) {
        weaponDamage = equippedWeapon->getDamage();
    }
    int totalDamage = strength + weaponDamage;
    std::cout << "[Hero attacks] Damage: " << totalDamage << "\n";
    return totalDamage;
}
void MainHero::defend(int incomingDamage) {
    int totalDefense = defense;
    if (equippedArmor) {
        totalDefense += equippedArmor->getDefenseValue();
    }
    if (equippedHelmet) {
        totalDefense += equippedHelmet->getBonus();
    }
    int damageTaken = incomingDamage - totalDefense;
    if (damageTaken < 0) damageTaken = 0;

    health -= damageTaken;
    std::cout << "[Hero defends] Damage taken: " << damageTaken 
              << ", Current health: " << health << "\n";
}
void MainHero::selectPath() {
    std::cout << "Choose your path:\n";
    std::cout << " 1 - Path of Evil\n";
    std::cout << " 2 - Path of Virtue\n";
    std::cout << " 3 - Path of Power\n";
    int choice = 0;
    std::cin >> choice;
    while(std::cin.fail() || choice < 1 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid input, enter 1, 2 or 3: ";
        std::cin >> choice;
    }
    chosenPath = choice;
}
int MainHero::getChosenPath() const {
    return chosenPath;
}
void MainHero::equipWeapon(std::shared_ptr<Weapon> w) {
    equippedWeapon = w;
    std::cout << "[Equipped Weapon]: " << w->toString() << "\n";
}
void MainHero::equipArmor(std::shared_ptr<Armor> a) {
    equippedArmor = a;
    std::cout << "[Equipped Armor]: " << a->toString() << "\n";
}
void MainHero::equipHelmet(std::shared_ptr<Helmet> h) {
    equippedHelmet = h;
    std::cout << "[Equipped Helmet]: " << h->toString() << "\n";
}
void MainHero::addToInventory(std::shared_ptr<Weapon> w) {
    inventory.addWeapon(w);
}
void MainHero::addToInventory(std::shared_ptr<Armor> a) {
    inventory.addArmor(a);
}
void MainHero::addToInventory(std::shared_ptr<Helmet> h) {
    inventory.addHelmet(h);
}
void MainHero::showInventory() {
    inventory.listAll();
}
void MainHero::upgradeAllEquipment() {
    if (equippedWeapon) equippedWeapon->upgrade();
    if (equippedArmor)  equippedArmor->upgrade();
    if (equippedHelmet) equippedHelmet->upgrade();
    std::cout << "[All equipped items have been upgraded!]\n";
}
void MainHero::degradeAllEquipment() {
    if (equippedWeapon) equippedWeapon->degrade();
    if (equippedArmor)  equippedArmor->degrade();
    if (equippedHelmet) equippedHelmet->degrade();
    std::cout << "[All equipped items have been downgraded!]\n";
}


// Duke
Duke::Duke()
    : BaseCharacter(10, 6, 3)
{
}
int Duke::attack() {
    std::cout << "[Duke attacks] Strength=" << strength << "\n";
    return strength;
}
void Duke::defend(int incomingDamage) {
    int dmg = incomingDamage - defense;
    if (dmg < 0) dmg = 0;
    health -= dmg;
    std::cout << "[Duke is hit] Damage=" << dmg 
              << ", Health=" << health << "\n";
}
void Duke::absorption() {
    // Just a story effect
    std::cout << "Duke attempts to absorb the hero's soul...\n";
}
void Duke::angry() {
    strength += 2;
    std::cout << "Duke enrages. New strength=" << strength << "\n";
}


// Wizard
Wizard::Wizard()
    : BaseCharacter(5, 2, 0)
{
}
int Wizard::attack() {
    std::cout << "[Wizard casts a magical missile], power=" << strength << "\n";
    return strength;
}
void Wizard::defend(int incomingDamage) {
    int dmg = incomingDamage - defense;
    if (dmg < 0) dmg=0;
    health -= dmg;
    std::cout << "[Wizard is hit] Damage=" << dmg 
              << ", Remaining health=" << health << "\n";
}
void Wizard::start_game() {
    std::cout << "Wizard: 'Let's play dice!' (3 rounds)\n";
}
int Wizard::roll_dice() {
    int d1 = 1 + rand()%6;
    int d2 = 1 + rand()%6;
    return d1 + d2;
}


// Challenge (Abstract)
Challenge::Challenge(const std::string &desc, int diff, const std::string &rew)
    : description(desc), difficulty(diff), reward(rew)
{
}
std::string Challenge::getDescription() const { return description; }
int Challenge::getDifficulty() const { return difficulty; }
std::string Challenge::getReward() const { return reward; }

// ChallengeBats
ChallengeBats::ChallengeBats()
    : Challenge("Furious bats", 3, "Ranged weapon")
{
}
void ChallengeBats::start() {
    std::cout << "[Challenge 1]: " << description 
              << "\nYou must dodge them for 30 seconds!\n";
}
void ChallengeBats::finish() {
    std::cout << "The bats finally retreated!\n";
}
bool ChallengeBats::doChallenge(MainHero &hero) {
    // We simulate 5 waves. Player must press 'd' to dodge each wave.
    // If fail, hero loses 1 HP.
    std::cout << "Try to dodge bat attacks! You have " << hero.getHealth() 
              << " HP.\n";
    for (int i=1; i<=5; i++) {
        std::cout << "Wave #" << i << " (type 'd' to dodge): ";
        char c;
        std::cin >> c;
        if (c != 'd' && c != 'D') {
            std::cout << "You failed to dodge!\n";
            hero.defend(1);
            if (hero.getHealth()<=0) {
                std::cout << "The hero died to the bats...\n";
                return false;
            }
        } else {
            std::cout << "Successful dodge!\n";
        }
    }
    return true; 
}

// ChallengeOgre
ChallengeOgre::ChallengeOgre()
    : Challenge("Huge ogre", 5, "Armor")
{
}
void ChallengeOgre::start() {
    std::cout << "[Challenge 2]: " << description 
              << "\nYou have to land 3 hits!\n";
}
void ChallengeOgre::finish() {
    std::cout << "The ogre is defeated!\n";
}
bool ChallengeOgre::doChallenge(MainHero &hero) {
    int ogreHP = 3;
    std::cout << "Battle with the ogre begins! Ogre HP=3.\n";

    while (ogreHP>0 && hero.getHealth()>0) {
        std::cout << "(Your action: a - attack, d - dodge) > ";
        char c;
        std::cin >> c;

        if (c=='a' || c=='A') {
            int dmg = hero.attack();
            (void)dmg; // We won't track exact damage, we just subtract 1 from ogreHP
            ogreHP -= 1;
            std::cout << "You hit the ogre, ogre HP is now: " << ogreHP << "\n";
        } else if (c=='d' || c=='D') {
            std::cout << "You try to dodge the incoming blow...\n";
            int roll = rand()%100;
            if (roll<80) {
                std::cout << "Successful dodge!\n";
            } else {
                std::cout << "Failed to dodge!\n";
                hero.defend(1);
            }
        } else {
            std::cout << "Invalid command, you skip your turn.\n";
        }
        // Ogre attacks if still alive
        if (ogreHP>0) {
            int roll = rand()%100;
            if (roll<20) {
                std::cout << "Ogre strikes back!\n";
                hero.defend(1);
                if (hero.getHealth()<=0) {
                    std::cout << "The hero has fallen...\n";
                    return false;
                }
            } else {
                std::cout << "Ogre misses!\n";
            }
        }
    }
    if (hero.getHealth()<=0) {
        return false;
    }
    return true;
}

// ChallengeRiddle
ChallengeRiddle::ChallengeRiddle()
    : Challenge("Wizard's riddle", 2, "Helmet")
{
}
void ChallengeRiddle::start() {
    std::cout << "[Challenge 3]: " << description 
              << "\nThe wizard asks you a riddle...\n";
}
void ChallengeRiddle::finish() {
    std::cout << "You solved the riddle!\n";
}
bool ChallengeRiddle::doChallenge(MainHero &hero) {
    std::cout << "Riddle: 'Which creature walks on four legs in the morning,\n"
                 " two legs at noon, and three legs in the evening?' (The famous Sphinx riddle)\n"
                 "Your answer: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::string answer;
    std::getline(std::cin, answer);

    // Convert to lowercase
    for (auto & c: answer) {
        c = tolower(c);
    }
    bool correct = false;
    // Check if it contains "man" or "human"
    if (answer.find("man")!=std::string::npos || answer.find("human")!=std::string::npos) {
        correct = true;
    }
    if (!correct) {
        std::cout << "Wrong answer! The wizard punishes you.\n";
        hero.defend(1);
        if (hero.getHealth()<=0) {
            std::cout << "The hero dies due to the wizard's punishment...\n";
            return false;
        }
    }
    return true;
}


// PathOfEvil
bool PathOfEvil::take_challenge(MainHero &hero) {
    // 1) Bats
    bats.start();
    bool success = bats.doChallenge(hero);
    bats.finish();
    if (!success) return false;

    // Reward - weapon
    std::cout << "You see 3 chests with possible weapons. Choose (1/2/3): ";
    int chest = 0;
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) {
        chest = 1;
    }
    auto w = getRandomWeapon();
    std::cout << "You pick chest #" << chest << " -> " 
              << w->toString() << "\n";
    hero.addToInventory(w);
    hero.equipWeapon(w);

    // 2) Ogre
    ogre.start();
    success = ogre.doChallenge(hero);
    ogre.finish();
    if (!success) return false;

    // Reward - armor
    std::cout << "Pick a chest for armor (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) {
        chest = 1;
    }
    auto a = getRandomArmor();
    std::cout << "Chest #" << chest << " -> " << a->toString() << "\n";
    hero.addToInventory(a);
    hero.equipArmor(a);

    // 3) Riddle
    riddle.start();
    success = riddle.doChallenge(hero);
    riddle.finish();
    if (!success) return false;

    // Reward - helmet
    std::cout << "Pick a chest for a helmet (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) {
        chest = 1;
    }
    auto h = getRandomHelmet();
    std::cout << "Chest #" << chest << " -> " << h->toString() << "\n";
    hero.addToInventory(h);
    hero.equipHelmet(h);

    return true;
}
std::shared_ptr<Weapon> PathOfEvil::getRandomWeapon() {
    Rarity rar = getRandomRarity();
    int dmg = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Weapon>("Dark Bow", rar, dmg);
}
std::shared_ptr<Armor> PathOfEvil::getRandomArmor() {
    Rarity rar = getRandomRarity();
    int def = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Armor>("Dark Armor", rar, def);
}
std::shared_ptr<Helmet> PathOfEvil::getRandomHelmet() {
    Rarity rar = getRandomRarity();
    int bonus = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Helmet>("Helm of Horror", rar, bonus);
}
Rarity PathOfEvil::getRandomRarity() {
    int r = rand()%100; 
    if (r<60) return Rarity::U;
    if (r<90) return Rarity::R;
    return Rarity::SR;
}


// PathOfVirtue
bool PathOfVirtue::take_challenge(MainHero &hero) {
    // Similar steps + different flavor
    bats.start();
    bool success = bats.doChallenge(hero);
    bats.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a weapon (1/2/3): ";
    int chest=0;
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) { chest=1; }
    auto w = getRandomWeapon();
    std::cout << "Chest #" << chest << ": " << w->toString() << "\n";
    hero.addToInventory(w);
    hero.equipWeapon(w);

    ogre.start();
    success = ogre.doChallenge(hero);
    ogre.finish();
    if (!success) return false;

    std::cout << "Choose a chest for armor (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) { chest=1; }
    auto a = getRandomArmor();
    std::cout << "Chest #" << chest << ": " << a->toString() << "\n";
    hero.addToInventory(a);
    hero.equipArmor(a);

    riddle.start();
    success = riddle.doChallenge(hero);
    riddle.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a helmet (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) { chest=1; }
    auto h = getRandomHelmet();
    std::cout << "Chest #" << chest << ": " << h->toString() << "\n";
    hero.addToInventory(h);
    hero.equipHelmet(h);

    return true;
}
std::shared_ptr<Weapon> PathOfVirtue::getRandomWeapon() {
    Rarity rar = getRandomRarity();
    int dmg = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Weapon>("Bow of Light", rar, dmg);
}
std::shared_ptr<Armor> PathOfVirtue::getRandomArmor() {
    Rarity rar = getRandomRarity();
    int def = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Armor>("Blessed Armor", rar, def);
}
std::shared_ptr<Helmet> PathOfVirtue::getRandomHelmet() {
    Rarity rar = getRandomRarity();
    int bonus = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Helmet>("Helm of Grace", rar, bonus);
}
Rarity PathOfVirtue::getRandomRarity() {
    int r = rand()%100;
    if (r<60) return Rarity::U;
    if (r<90) return Rarity::R;
    return Rarity::SR;
}

// PathOfPower
bool PathOfPower::take_challenge(MainHero &hero) {
    bats.start();
    bool success = bats.doChallenge(hero);
    bats.finish();
    if (!success) return false;

    int chest=0;
    std::cout << "Choose a chest for a weapon (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) { chest=1; }
    auto w = getRandomWeapon();
    std::cout << "You receive: " << w->toString() << "\n";
    hero.addToInventory(w);
    hero.equipWeapon(w);

    ogre.start();
    success = ogre.doChallenge(hero);
    ogre.finish();
    if (!success) return false;

    std::cout << "Choose a chest for armor (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) { chest=1; }
    auto a = getRandomArmor();
    std::cout << "You receive: " << a->toString() << "\n";
    hero.addToInventory(a);
    hero.equipArmor(a);

    riddle.start();
    success = riddle.doChallenge(hero);
    riddle.finish();
    if (!success) return false;

    std::cout << "Choose a chest for a helmet (1/2/3): ";
    std::cin >> chest;
    if (std::cin.fail() || chest<1 || chest>3) { chest=1; }
    auto h = getRandomHelmet();
    std::cout << "You receive: " << h->toString() << "\n";
    hero.addToInventory(h);
    hero.equipHelmet(h);

    return true;
}
std::shared_ptr<Weapon> PathOfPower::getRandomWeapon() {
    Rarity rar = getRandomRarity();
    int dmg = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Weapon>("Crossbow of Power", rar, dmg);
}
std::shared_ptr<Armor> PathOfPower::getRandomArmor() {
    Rarity rar = getRandomRarity();
    int def = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Armor>("Royal Armor", rar, def);
}
std::shared_ptr<Helmet> PathOfPower::getRandomHelmet() {
    Rarity rar = getRandomRarity();
    int bonus = (rar == Rarity::U) ? 1 : (rar == Rarity::R) ? 2 : 3;
    return std::make_shared<Helmet>("Helm of Dominion", rar, bonus);
}
Rarity PathOfPower::getRandomRarity() {
    int r = rand()%100;
    if (r<60) return Rarity::U;
    if (r<90) return Rarity::R;
    return Rarity::SR;
}

// DiceGame
DiceGame::DiceGame(Wizard &w, MainHero &h)
    : wizard(w), hero(h), isActive(false), heroWins(0), wizardWins(0), rounds(0)
{
}
void DiceGame::start() {
    isActive = true;
    heroWins=0; 
    wizardWins=0;
    rounds=0;
    wizard.start_game();
    std::cout << "(Press Enter when prompted to roll the dice)\n";
}
void DiceGame::processRound() {
    if (!isActive) return;
    if (rounds>=3) {
        std::cout << "All 3 rounds have been played!\n";
        return;
    }
    rounds++;
    std::cout << "Press Enter to roll dice for round " << rounds << "...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int heroRollVal = heroRollDice();
    int wizardRollVal = wizard.roll_dice();
    std::cout << "[Round " << rounds << "]: Hero rolled " << heroRollVal 
              << ", Wizard rolled " << wizardRollVal << "\n";
    if (heroRollVal > wizardRollVal) {
        heroWins++;
        std::cout << "(Hero wins this round)\n";
    } else if (wizardRollVal > heroRollVal) {
        wizardWins++;
        std::cout << "(Wizard wins this round)\n";
    } else {
        std::cout << "(Round is a draw)\n";
    }
}
void DiceGame::end() {
    isActive=false;
    std::cout << "Dice game results: Hero " << heroWins 
              << " vs. " << wizardWins << " Wizard\n";
    if (heroWins>=2) {
        std::cout << "Hero wins the dice game! Upgrading equipment.\n";
        hero.upgradeAllEquipment();
    } else {
        std::cout << "Hero did not achieve 2 round-wins... Downgrading equipment.\n";
        hero.degradeAllEquipment();
    }
}
int DiceGame::heroRollDice() {
    int d1 = 1 + rand()%6;
    int d2 = 1 + rand()%6;
    return d1 + d2;
}

// BattleMechanics
bool BattleMechanics::battle(MainHero &hero, Duke &duke) {
    std::cout << "\n--- Final battle with the Duke! ---\n";
    int timeCounter=0; 
    while (duke.getHealth()>0 && hero.getHealth()>0) {
        std::cout << "(Hero turn: 'a' to attack / 'd' to defend) > ";
        char action;
        std::cin >> action;
        if (action=='a' || action=='A') {
            int dmg = hero.attack();
            duke.defend(dmg);
        } else if (action=='d' || action=='D') {
            std::cout << "You prepare to defend, reducing incoming damage.\n";
        } else {
            std::cout << "Invalid command, you skip your turn.\n";
        }
        if (duke.getHealth()<=0) {
            std::cout << "The Duke is defeated!\n";
            break;
        }
        // Duke attacks
        int dukeDamage = duke.attack();
        if (action=='d' || action=='D') {
            dukeDamage /= 2; 
        }
        hero.defend(dukeDamage);
        if (hero.getHealth()<=0) {
            std::cout << "The hero has fallen...\n";
            break;
        }
        // Every 2 cycles (~10 seconds):
        timeCounter += 5;
        if (timeCounter>=10) {
            std::cout << "[Mighty Soul Wave] The Duke unleashes a -3 HP wave!\n";
            hero.setHealth(hero.getHealth()-3);
            if (hero.getHealth()<=0) {
                std::cout << "Hero did not survive the wave...\n";
                break;
            }
            timeCounter=0;
        }
    }
    return (hero.getHealth()>0 && duke.getHealth()<=0);
}

// Endings
void BadEnding::playEnding() {
    std::cout << "BAD Ending: The hero kills the duke but becomes possessed by the dark spirit!\n";
}
void GoodEnding::playEnding() {
    std::cout << "GOOD Ending: The hero destroys the cursed sword,\n"
              << " freeing the duke from the evil spirit!\n"
              << "The grateful duke rewards the hero generously.\n";
}
void NeutralEnding::playEnding() {
    std::cout << "NEUTRAL Ending: The hero kills the duke using the mighty artifact,\n"
              << " simultaneously destroying the ancient spirit.\n"
              << "The hero then becomes the new ruler (the new duke).\n";
}

// FinalBattle
void FinalBattle::startFinal(MainHero &hero) {
    Duke duke;
    bool result = BattleMechanics::battle(hero, duke);
    if (result) {
        int path = hero.getChosenPath();
        if (path==1) {
            BadEnding::playEnding();
        } else if (path==2) {
            GoodEnding::playEnding();
        } else {
            NeutralEnding::playEnding();
        }
    } else {
        std::cout << "The hero was slain in the final battle...\n";
    }
}

// Storyline
void Storyline::showIntro() {
    std::cout << "Rumors have spread about the local duke's madness.\n"
                 "They say he changed drastically after returning from an excavation site...\n";
}
void Storyline::showAfterPath() {
    std::cout << "\nApproaching the castle, you encounter a Wizard.\n"
                 "He speaks of a strange artifact that drove the duke insane.\n";
}
void Storyline::showBeforeFinal() {
    std::cout << "You enter the castle... In the throne room rests the sword 'Soul Executioner',\n"
                 " radiating a dark aura. The Duke is waiting!\n";
}

// UserInterface
void UserInterface::showTitle() {
    std::cout << "========================================\n"
              << "   [ TEXT RPG: Paths of Destiny ]\n"
              << "========================================\n";
}
void UserInterface::showPause() {
    std::cout << "(Press Enter to continue...)\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

// GameEngine
GameEngine::GameEngine()
    : diceGame(wizard, hero)
{
    srand(static_cast<unsigned>(time(NULL)));
}
void GameEngine::run() {
    UserInterface::showTitle();
    Storyline::showIntro();
    hero.selectPath();

    switch(hero.getChosenPath()) {
        case 1:
            chosenPath = std::make_unique<PathOfEvil>(); 
            break;
        case 2:
            chosenPath = std::make_unique<PathOfVirtue>();
            break;
        case 3:
            chosenPath = std::make_unique<PathOfPower>();
            break;
        default:
            chosenPath = std::make_unique<PathOfEvil>();
            break;
    }

    bool success = chosenPath->take_challenge(hero);
    if(!success) {
        std::cout << "The hero died during the trials...\nGame Over.\n";
        return;
    }

    Storyline::showAfterPath();
    std::cout << "Wizard: 'Do you want to play dice or just ignore me?' (1 - play / 2 - ignore)\n";
    int choice=0;
    std::cin >> choice;
    if (choice==1) {
        diceGame.start();
        for(int i=0; i<3; i++) {
            diceGame.processRound();
        }
        diceGame.end();
    } else {
        std::cout << "You ignored the wizard...\n";
    }

    std::cout << "\n--- Would you like to check your inventory? (1 - yes, 0 - no): ";
    int invChoice=0;
    std::cin >> invChoice;
    if(invChoice==1) {
        hero.showInventory();
    }

    Storyline::showBeforeFinal();
    UserInterface::showPause();
    FinalBattle::startFinal(hero);
};
