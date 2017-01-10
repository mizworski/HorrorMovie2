#include "citizen.h"

HealthPoints Citizen::getHealth() const {
    return healthPoints_;
}

const Age Citizen::getAge() const {
    return age_;
}

void Citizen::takeDamage(AttackPower damage) {
    if (damage >= healthPoints_) {
        healthPoints_ = 0;
    } else {
        healthPoints_ -= damage;
    }
}

void Citizen::fightAgainstMonsters(GroupOfMonsters monsters) {
    takeDamage(monsters.getAttackPower());
}

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= 11 && age <= 17);
}

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= 18 && age <= 100);
}

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attackPower) : Citizen(health, age),
                                                                          attackPower_(attackPower) {
    assert(age >= 18 && age <= 100);
    isAttackPowerValid(attackPower);
}

const AttackPower Sheriff::getAttackPower() const {
    return attackPower_;
}

const void Sheriff::isAttackPowerValid(AttackPower attackPower) const {
    assert(attackPower >= 0);
}

void Sheriff::fightAgainstMonsters(GroupOfMonsters monsters)  {
    if (getHealth() > 0) {
        takeDamage(monsters.getAttackPower());
        monsters.takeDamage(getAttackPower());
    }
}

Teenager createTeenager(HealthPoints health, Age age) {
    return Teenager(health, age);
}

Adult createAdult(HealthPoints health, Age age) {
    return Adult(health, age);
}

Sheriff createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return Sheriff(health, age, attackPower);
}
