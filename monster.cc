#include "monster.h"

Monster::Monster(HealthPoints health, AttackPower attackPower) : health_(health),
                                                                 attackPower_(attackPower) {} //todo virtual?

HealthPoints Monster::getHealth() {
    return health_;
}

AttackPower Monster::getAttackPower() {
    return attackPower_;
}

void Monster::takeDamage(AttackPower damage) {
    if (damage >= health_) {
        health_ = 0; //todo HealthPoints.zero() ?
    } else {
        health_ -= damage;
    }
}

Zombie::Zombie(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};

Vampire::Vampire(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};

Mummy::Mummy(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};

/// Group of monsters.

GroupOfMOnsters::GroupOfMOnsters() : health_(0), attackPower_(0) {};

GroupOfMOnsters::GroupOfMOnsters(std::vector<Monster> monsters) : monsters_(monsters), health_(0),
                                                                  attackPower_(0) {
    for (auto &monster : monsters_) {
        HealthPoints health = monster.getHealth();

        if (health > 0) {
            health_ += health;
            attackPower_ += monster.getAttackPower();
        }
    }
}

GroupOfMOnsters::GroupOfMOnsters(std::initializer_list<Monster> monsters) : monsters_(monsters), health_(0),
                                                                            attackPower_(0) {
    for (auto &monster : monsters_) {
        HealthPoints health = monster.getHealth();

        if (health > 0) {
            health_ += health;
            attackPower_ += monster.getAttackPower();
        }
    }
}

HealthPoints GroupOfMOnsters::getHealth() {
    return health_;
}

AttackPower GroupOfMOnsters::getAttackPower() {
    return attackPower_;
}

void GroupOfMOnsters::takeDamage(AttackPower damage) {
    for (auto &monster : monsters_) {
        if (monster.getHealth() > 0) {
            HealthPoints health = monster.getHealth();

            monster.takeDamage(damage);

            if (damage >= health) {
                health_ -= health;
                attackPower_ -= monster.getAttackPower();
            } else {
                health_ -= damage;
            }
        }
    }
}


Zombie createZombie(HealthPoints health, AttackPower attackPower) {
    Zombie zombie(health, attackPower);
    return zombie;
}

Vampire createVampire(HealthPoints health, AttackPower attackPower) {
    Vampire vampire(health, attackPower);
    return vampire;
}

Mummy createMummy(HealthPoints health, AttackPower attackPower) {
    Mummy mummy(health, attackPower);
    return mummy;
}

GroupOfMOnsters createGroupOfMonsters(std::vector<Monster> monsters) {
    return GroupOfMOnsters(monsters);
}

GroupOfMOnsters createGroupOfMonsters(std::initializer_list<Monster> monsters) {
    return GroupOfMOnsters(monsters);
}