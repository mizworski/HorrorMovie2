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

GroupOfMOnsters::GroupOfMOnsters(const std::vector<Monster> &monsters) : monsters_(monsters), health_(0), attackPower_(0) {
    for (auto &monster : monsters_) {
        HealthPoints health = monster.getHealth();
        health_ += health;

        // todo is that if neccessary?
        if (health > 0) {
            attackPower_ += monster.getAttackPower();
        } else {
//                monsters_.erase(monster); //todo
        }
    }
}

// todo do we need 2 constructors for lvalues and rvalues?
GroupOfMOnsters::GroupOfMOnsters(std::vector<Monster> &&monsters) : monsters_(monsters), health_(0), attackPower_(0) {
    for (auto &monster : monsters_) {
        HealthPoints health = monster.getHealth();
        health_ += health;

        // todo is that if neccessary?
        if (health > 0) {
            attackPower_ += monster.getAttackPower();
        } else {
//                monsters_.erase(monster); //todo
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
        HealthPoints health = monster.getHealth();

        monster.takeDamage(damage);

        if (damage >= health) {
            health_ -= health;
            attackPower_ -= monster.getAttackPower();
//                monsters_.erase(monster); //todo
        } else {
            health_ -= damage;
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