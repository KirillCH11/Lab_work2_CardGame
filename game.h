/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include <string>
#include <vector>
#include <memory>
#include <iostream>


enum class Rarity {
    U,   //Common
    R,   //Rare
    SR   //Super rare
};

Rarity upgradeRarity(Rarity r);
Rarity downgradeRarity(Rarity r);

class BaseCharacter {
protected:
    int health;                 //Current health (number of lives in game context)
    int strength;               //Attack power
    int defense;                //Base defense
    std::string currentEquipment; //String description of equipment (simplified)

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


class Weapon {
private:
    std::string type; //Weapon name/type
    Rarity rarity;    //Item rarity
    int damage;       //Damage output

public:
    Weapon(const std::string &t, Rarity r, int dmg);

    void upgrade();
    void degrade();

    std::string getType() const;
    Rarity getRarity() const;
    int getDamage() const;
    std::string toString() const;
};

class Armor {
private:
    std::string type;
    Rarity rarity;
    int defense;

public:
    Armor(const std::string &t, Rarity r, int def);

    void upgrade();
    void degrade();

    std::string getType() const;
    Rarity getRarity() const;
    int getDefenseValue() const;
    std::string toString() const;
};

class Helmet {
private:
    std::string type;
    Rarity rarity;
    int defenseBonus;

public:
    Helmet(const std::string &t, Rarity r, int bonus);

    void upgrade();
    void degrade();

    std::string getType() const;
    Rarity getRarity() const;
    int getBonus() const;
    std::string toString() const;
};


class Inventory {
private:
    std::vector<std::shared_ptr<Weapon>> weapons; ///< Collection of weapons
    std::vector<std::shared_ptr<Armor>> armors;   ///< Collection of armors
    std::vector<std::shared_ptr<Helmet>> helmets; ///< Collection of helmets

public:
    Inventory() {}

    void addWeapon(std::shared_ptr<Weapon> w);
    void addArmor(std::shared_ptr<Armor> a);
    void addHelmet(std::shared_ptr<Helmet> h);
    void listAll();
};

class MainHero : public BaseCharacter {
private:
    Inventory inventory;                    //The hero's inventory
    std::shared_ptr<Weapon> equippedWeapon; //Equipped weapon
    std::shared_ptr<Armor> equippedArmor;   //Equipped armor
    std::shared_ptr<Helmet> equippedHelmet; //Equipped helmet
    int chosenPath;                         //Chosen path (1 - Evil, 2 - Virtue, 3 - Power)

public:
    MainHero();
    virtual ~MainHero(){}

    int attack() override;
    void defend(int incomingDamage) override;
    void selectPath();
    int getChosenPath() const;

    // Equipment methods
    void equipWeapon(std::shared_ptr<Weapon> w);
    void equipArmor(std::shared_ptr<Armor> a);
    void equipHelmet(std::shared_ptr<Helmet> h);

    // Inventory methods
    void addToInventory(std::shared_ptr<Weapon> w);
    void addToInventory(std::shared_ptr<Armor> a);
    void addToInventory(std::shared_ptr<Helmet> h);

    void showInventory();
    void upgradeAllEquipment();
    void degradeAllEquipment();
};

class Duke : public BaseCharacter {
public:
    Duke();
    virtual ~Duke(){}

    int attack() override;
    void defend(int incomingDamage) override;
    void absorption();
    void angry();
};


class Wizard : public BaseCharacter {
public:
    Wizard();
    virtual ~Wizard(){}

    int attack() override;
    void defend(int incomingDamage) override;
    void start_game();
    int roll_dice();
};


class Challenge {
protected:
    std::string description; //Basic description
    int difficulty;          //Some abstract difficulty
    std::string reward;      //Reward name (string)

public:
    Challenge(const std::string &desc, int diff, const std::string &rew);
    virtual ~Challenge(){}

    virtual void start() = 0;
    virtual void finish() = 0;

    std::string getDescription() const;
    int getDifficulty() const;
    std::string getReward() const;
};


class ChallengeBats : public Challenge {
public:
    ChallengeBats();
    void start() override;
    void finish() override;
    bool doChallenge(MainHero &hero);
};

class ChallengeOgre : public Challenge {
public:
    ChallengeOgre();
    void start() override;
    void finish() override;
    bool doChallenge(MainHero &hero);
};


class ChallengeRiddle : public Challenge {
public:
    ChallengeRiddle();
    void start() override;
    void finish() override;
    bool doChallenge(MainHero &hero);
};


class Path {
public:
    virtual ~Path(){}
    virtual bool take_challenge(MainHero &hero) = 0;
};

class PathOfEvil : public Path {
private:
    ChallengeBats bats;
    ChallengeOgre ogre;
    ChallengeRiddle riddle;
public:
    bool take_challenge(MainHero &hero) override;

    // Loot generation methods
    std::shared_ptr<Weapon> getRandomWeapon();
    std::shared_ptr<Armor> getRandomArmor();
    std::shared_ptr<Helmet> getRandomHelmet();
    Rarity getRandomRarity();
};


class PathOfVirtue : public Path {
private:
    ChallengeBats bats;
    ChallengeOgre ogre;
    ChallengeRiddle riddle;
public:
    bool take_challenge(MainHero &hero) override;

    std::shared_ptr<Weapon> getRandomWeapon();
    std::shared_ptr<Armor> getRandomArmor();
    std::shared_ptr<Helmet> getRandomHelmet();
    Rarity getRandomRarity();
};


class PathOfPower : public Path {
private:
    ChallengeBats bats;
    ChallengeOgre ogre;
    ChallengeRiddle riddle;
public:
    bool take_challenge(MainHero &hero) override;

    std::shared_ptr<Weapon> getRandomWeapon();
    std::shared_ptr<Armor> getRandomArmor();
    std::shared_ptr<Helmet> getRandomHelmet();
    Rarity getRandomRarity();
};


class Wizard;  

class DiceGame {
private:
    Wizard &wizard;
    MainHero &hero;
    bool isActive;
    int heroWins;
    int wizardWins;
    int rounds;

public:
    DiceGame(Wizard &w, MainHero &h);

    void start();
    void processRound();
    void end();
    int heroRollDice();
};


class BattleMechanics {
public:
    static bool battle(MainHero &hero, Duke &duke);
};

class BadEnding {
public:
    static void playEnding();
};

class GoodEnding {
public:
    static void playEnding();
};


class NeutralEnding {
public:
    static void playEnding();
};


class FinalBattle {
public:
    static void startFinal(MainHero &hero);
};


class Storyline {
public:
    static void showIntro();
    static void showAfterPath();
    static void showBeforeFinal();
};


class UserInterface {
public:
    static void showTitle();
    static void showPause();
};

class GameEngine {
private:
    MainHero hero;
    std::unique_ptr<Path> chosenPath;
    Wizard wizard;
    DiceGame diceGame;

public:
    GameEngine();
    void run();
};
