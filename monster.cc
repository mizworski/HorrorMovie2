#include "monster.h"

SingleMonster::SingleMonster(HealthPoints healthPoints,
                             AttackPower attackPower,
                             std::string monsterName) : healthPoints_(healthPoints),
                                                        attackPower_(attackPower),
                                                        monsterName_(monsterName) {}

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

const AttackPower SingleMonster::getAttackPower() const {
    return attackPower_;
}

const std::string SingleMonster::getMonsterName() const {
    return monsterName_;
}

const void SingleMonster::isAttackPowerValid(AttackPower attackPower) const {
    assert(attackPower >= 0);
}

Zombie::Zombie(HealthPoints health, AttackPower attackPower) : SingleMonster(health, attackPower, "Zombie") {};

Vampire::Vampire(HealthPoints health, AttackPower attackPower) : SingleMonster(health, attackPower, "Vampire") {};

Mummy::Mummy(HealthPoints health, AttackPower attackPower) : SingleMonster(health, attackPower, "Mummy") {};

Zombie createZombie(HealthPoints health, AttackPower attackPower) {
    return Zombie(health, attackPower);
}

Vampire createVampire(HealthPoints health, AttackPower attackPower) {
    return Vampire(health, attackPower);
}

Mummy createMummy(HealthPoints health, AttackPower attackPower) {
    return Mummy(health, attackPower);
}

GroupOfMonsters::GroupOfMonsters(std::vector<SingleMonster> monsters) {
    for (auto &monster : monsters) {
        monsters_.push_back(std::make_shared<SingleMonster>(monster));
    }
}

GroupOfMonsters::GroupOfMonsters(std::initializer_list<SingleMonster> monsters) {
    for (auto &monster : monsters) {
        monsters_.push_back(std::make_shared<SingleMonster>(monster));
    }
}

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

const AttackPower GroupOfMonsters::getAttackPower() const {
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

GroupOfMonsters createGroupOfMonsters(std::vector<SingleMonster> monsters) {
    return GroupOfMonsters(monsters);
}
