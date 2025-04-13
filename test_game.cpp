/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include <gtest/gtest.h>
#include "BaseCharacter.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Inventory.h"
#include "MainHero.h"
#include "Duke.h"
#include "Wizard.h"
#include "Challenge.h"
#include "Path.h"
#include "DiceGame.h"
#include "BattleMechanics.h"
#include "Endings.h"
#include "FinalBattle.h"
#include "Storyline.h"
#include "UserInterface.h"
#include "GameEngine.h"
#include "Rarity.h"

TEST(RarityTest, Upgrade) {
    EXPECT_EQ(upgradeRarity(Rarity::U), Rarity::R);
    EXPECT_EQ(upgradeRarity(Rarity::R), Rarity::SR);
    EXPECT_EQ(upgradeRarity(Rarity::SR), Rarity::SR);
}

TEST(RarityTest, Downgrade) {
    EXPECT_EQ(downgradeRarity(Rarity::SR), Rarity::R);
    EXPECT_EQ(downgradeRarity(Rarity::R), Rarity::U);
    EXPECT_EQ(downgradeRarity(Rarity::U), Rarity::U);
}

TEST(BaseCharacterTest, Initialization) {
    BaseCharacter* character = new Duke();
    EXPECT_GT(character->getHealth(), 0);
    EXPECT_GT(character->getStrength(), 0);
    EXPECT_GT(character->getDefense(), 0);
    delete character;
}

TEST(BaseCharacterTest, SettersGetters) {
    BaseCharacter* character = new Duke();
    character->setHealth(50);
    character->setStrength(8);
    character->setDefense(4);
    character->setEquipment("Sword");
    
    EXPECT_EQ(character->getHealth(), 50);
    EXPECT_EQ(character->getStrength(), 8);
    EXPECT_EQ(character->getDefense(), 4);
    EXPECT_EQ(character->getEquipment(), "Sword");
    delete character;
}

TEST(WeaponTest, Initialization) {
    Weapon weapon("Sword", Rarity::R, 10);
    EXPECT_EQ(weapon.getType(), "Sword");
    EXPECT_EQ(weapon.getRarity(), Rarity::R);
    EXPECT_EQ(weapon.getDamage(), 10);
}

TEST(WeaponTest, UpgradeDegrade) {
    Weapon weapon("Axe", Rarity::U, 5);
    weapon.upgrade();
    EXPECT_EQ(weapon.getRarity(), Rarity::R);
    EXPECT_EQ(weapon.getDamage(), 6);
    
    weapon.degrade();
    EXPECT_EQ(weapon.getRarity(), Rarity::U);
    EXPECT_EQ(weapon.getDamage(), 5);
}

TEST(ArmorTest, Initialization) {
    Armor armor("Shield", Rarity::SR, 15);
    EXPECT_EQ(armor.getType(), "Shield");
    EXPECT_EQ(armor.getRarity(), Rarity::SR);
    EXPECT_EQ(armor.getDefenseValue(), 15);
}

TEST(ArmorTest, UpgradeDegrade) {
    Armor armor("Plate", Rarity::R, 8);
    armor.upgrade();
    EXPECT_EQ(armor.getRarity(), Rarity::SR);
    EXPECT_EQ(armor.getDefenseValue(), 9);
    
    armor.degrade();
    EXPECT_EQ(armor.getRarity(), Rarity::R);
    EXPECT_EQ(armor.getDefenseValue(), 8);
}

TEST(HelmetTest, Initialization) {
    Helmet helmet("GreatHelm", Rarity::U, 3);
    EXPECT_EQ(helmet.getType(), "GreatHelm");
    EXPECT_EQ(helmet.getRarity(), Rarity::U);
    EXPECT_EQ(helmet.getBonus(), 3);
}

TEST(HelmetTest, UpgradeDegrade) {
    Helmet helmet("Cap", Rarity::SR, 5);
    helmet.degrade();
    EXPECT_EQ(helmet.getRarity(), Rarity::R);
    EXPECT_EQ(helmet.getBonus(), 4);
    
    helmet.upgrade();
    EXPECT_EQ(helmet.getRarity(), Rarity::SR);
    EXPECT_EQ(helmet.getBonus(), 5);
}

TEST(InventoryTest, AddItems) {
    Inventory inv;
    auto weapon = std::make_shared<Weapon>("Sword", Rarity::U, 5);
    auto armor = std::make_shared<Armor>("Shield", Rarity::R, 3);
    auto helmet = std::make_shared<Helmet>("Helm", Rarity::SR, 2);
    
    inv.addWeapon(weapon);
    inv.addArmor(armor);
    inv.addHelmet(helmet);
    
    testing::internal::CaptureStdout();
    inv.listAll();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Sword") != std::string::npos);
    EXPECT_TRUE(output.find("Shield") != std::string::npos);
    EXPECT_TRUE(output.find("Helm") != std::string::npos);
}

TEST(MainHeroTest, Initialization) {
    MainHero hero;
    EXPECT_EQ(hero.getHealth(), 100);
    EXPECT_EQ(hero.getStrength(), 10);
    EXPECT_EQ(hero.getDefense(), 5);
}

TEST(MainHeroTest, AttackDefend) {
    MainHero hero;
    int attackDamage = hero.attack();
    EXPECT_GE(attackDamage, 10); // Base 10 + weapon if equipped
    
    hero.defend(20);
    EXPECT_LT(hero.getHealth(), 100); // Health should be reduced
}

TEST(MainHeroTest, EquipmentManagement) {
    MainHero hero;
    auto weapon = std::make_shared<Weapon>("Sword", Rarity::U, 5);
    auto armor = std::make_shared<Armor>("Plate", Rarity::R, 3);
    auto helmet = std::make_shared<Helmet>("Helm", Rarity::SR, 2);
    
    hero.equipWeapon(weapon);
    hero.equipArmor(armor);
    hero.equipHelmet(helmet);
    
    EXPECT_EQ(hero.attack(), 15); // 10 (base) + 5 (weapon)
    
    hero.defend(20);
    // Defense: 5 (base) + 3 (armor) + 2 (helmet) = 10
    // Damage taken: 20 - 10 = 10
    EXPECT_EQ(hero.getHealth(), 90);
}

TEST(DukeTest, SpecialAbilities) {
    Duke duke;
    testing::internal::CaptureStdout();
    duke.absorption();
    duke.angry();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("absorption") != std::string::npos);
    EXPECT_TRUE(output.find("angry") != std::string::npos);
}

TEST(WizardTest, DiceRoll) {
    Wizard wizard;
    int roll = wizard.roll_dice();
    EXPECT_GE(roll, 1);
    EXPECT_LE(roll, 6);
}

TEST(ChallengeTest, BasicFunctionality) {
    ChallengeBats bats;
    EXPECT_EQ(bats.getDifficulty(), 1);
    EXPECT_EQ(bats.getDescription(), "Challenge: Defeat Bats");
    EXPECT_EQ(bats.getReward(), "Bat Wing");
    
    testing::internal::CaptureStdout();
    bats.start();
    bats.finish();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Starting") != std::string::npos);
    EXPECT_TRUE(output.find("Finishing") != std::string::npos);
}

TEST(ChallengeTest, DoChallenge) {
    ChallengeOgre ogre;
    MainHero hero;
    
    testing::internal::CaptureStdout();
    bool result = ogre.doChallenge(hero);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(result);
    EXPECT_TRUE(output.find("ogre") != std::string::npos);
}

TEST(PathTest, PathOfEvilRewards) {
    PathOfEvil path;
    MainHero hero;
    
    auto weapon = path.getRandomWeapon();
    auto armor = path.getRandomArmor();
    auto helmet = path.getRandomHelmet();
    
    EXPECT_TRUE(weapon->getType() == "Sword of Darkness");
    EXPECT_TRUE(armor->getType() == "Dark Shield");
    EXPECT_TRUE(helmet->getType() == "Helm of Shadows");
}


TEST(DiceGameTest, Initialization) {
    Wizard wizard;
    MainHero hero;
    DiceGame game(wizard, hero);
    
    EXPECT_FALSE(game.isGameActive());
    EXPECT_EQ(game.getHeroWins(), 0);
    EXPECT_EQ(game.getWizardWins(), 0);
    EXPECT_EQ(game.getRounds(), 0);
}

TEST(BattleMechanicsTest, BattleOutcome) {
    MainHero hero;
    Duke duke;
    
    // Set up hero to be very strong
    hero.setHealth(1000);
    hero.setStrength(100);
    hero.setDefense(100);
    
    // Duke normal stats
    bool result = BattleMechanics::battle(hero, duke);
    EXPECT_TRUE(result);
}

TEST(EndingsTest, PlayEndings) {
    testing::internal::CaptureStdout();
    BadEnding::playEnding();
    GoodEnding::playEnding();
    NeutralEnding::playEnding();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("BAD Ending") != std::string::npos);
    EXPECT_TRUE(output.find("GOOD Ending") != std::string::npos);
    EXPECT_TRUE(output.find("NEUTRAL Ending") != std::string::npos);
}

TEST(StorylineTest, ShowMessages) {
    testing::internal::CaptureStdout();
    Storyline::showIntro();
    Storyline::showAfterPath();
    Storyline::showBeforeFinal();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Rumors") != std::string::npos);
    EXPECT_TRUE(output.find("Wizard") != std::string::npos);
    EXPECT_TRUE(output.find("castle") != std::string::npos);
}

TEST(UserInterfaceTest, ShowTitle) {
    testing::internal::CaptureStdout();
    UserInterface::showTitle();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("TEXT RPG") != std::string::npos);
}
