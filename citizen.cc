#include "citizen.h"

HealthPoints Citizen::getHealth() const {
    return healthPoints_;
}

Age Citizen::getAge() const {
    return age_;
}

void Citizen::takeDamage(AttackPower damage) {
    if (damage >= healthPoints_) {
        healthPoints_ = 0;
    } else {
        healthPoints_ -= damage;
    }
}

void Citizen::fightAgainstMonster(std::shared_ptr<Monster> monster) {
    takeDamage(monster->getAttackPower());
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

AttackPower Sheriff::getAttackPower() const {
    return attackPower_;
}

void Sheriff::isAttackPowerValid(AttackPower attackPower) const {
    assert(attackPower >= 0);
}

void Sheriff::fightAgainstMonster(std::shared_ptr<Monster> monster)  {
    if (getHealth() > 0) {
        takeDamage(monster->getAttackPower());
        monster->takeDamage(getAttackPower());
    }
}

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age) {
    return std::make_shared<Teenager>(Teenager(health, age));
}

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age) {
    return std::make_shared<Adult>(Adult(health, age));
}

std::shared_ptr<Sheriff> createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return std::make_shared<Sheriff>(Sheriff(health, age, attackPower));
}
