#include "monster.h"

SingleMonster::SingleMonster(HealthPoints healthPoints,
                             AttackPower attackPower,
                             std::string monsterName) : healthPoints_(healthPoints),
                                                        attackPower_(attackPower),
                                                        monsterName_(monsterName) {
    isAttackPowerValid(attackPower);
}

HealthPoints SingleMonster::getHealth() const {
    return healthPoints_;
}

void SingleMonster::takeDamage(AttackPower damage) {
    if (damage >= healthPoints_) {
        healthPoints_ = 0;
    } else {
        healthPoints_ -= damage;
    }
}

AttackPower SingleMonster::getAttackPower() const {
    return attackPower_;
}

const std::string SingleMonster::getMonsterName() const {
    return monsterName_;
}

void SingleMonster::isAttackPowerValid(AttackPower attackPower) const {
    assert(attackPower >= 0);
}

Zombie::Zombie(HealthPoints health, AttackPower attackPower) : SingleMonster(health, attackPower, "Zombie") {};

Vampire::Vampire(HealthPoints health, AttackPower attackPower) : SingleMonster(health, attackPower, "Vampire") {};

Mummy::Mummy(HealthPoints health, AttackPower attackPower) : SingleMonster(health, attackPower, "Mummy") {};

GroupOfMonsters::GroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters) : monsters_(monsters) {};

GroupOfMonsters::GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters) : monsters_(monsters) {};

HealthPoints GroupOfMonsters::getHealth() const {
    HealthPoints healthPoints = 0;

    for (auto &monster : monsters_) {
        healthPoints += monster->getHealth();
    }

    return healthPoints;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (auto &monster : monsters_) {
        monster->takeDamage(damage);
    }
}

AttackPower GroupOfMonsters::getAttackPower() const {
    AttackPower attackPower = 0;

    for (auto &monster : monsters_) {
        if (monster->getHealth() > 0) {
            attackPower += monster->getAttackPower();
        }
    }

    return attackPower;
}

const std::string GroupOfMonsters::getMonsterName() const {
    return monsterName_;
}

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Zombie>(Zombie(health, attackPower));
}

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Vampire>(Vampire(health, attackPower));
}

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Mummy>(Mummy(health, attackPower));
}

GroupOfMonsters createGroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters) {
    return GroupOfMonsters(monsters);
}
