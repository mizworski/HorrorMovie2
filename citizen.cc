#include "citizen.h"

HealthPoints Citizen::getHealth() {
    return health_;
}

Age Citizen::getAge() {
    return age_;
}

void Citizen::takeDamage(AttackPower damage) {
    if (damage >= health_) {
        health_ = 0; //todo HealthPoints.zero() ?
    } else {
        health_ -= damage;
    }
}

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= LOWER_BOUND_TEENAGER && age <= UPPER_BOUND_TEENAGER);
}

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= LOWER_BOUND_ADULT && age <= UPPER_BOUND_ADULT);
}

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attack_power) : Citizen(health, age), attackPower(attack_power) {
        assert(age >= LOWER_BOUND_ADULT && age <= UPPER_BOUND_ADULT);
}

AttackPower Sheriff::getAttackPower() {
    return attackPower;
}

Teenager createTeenager(HealthPoints health, Age age) {
    Teenager teenager(health, age);
    return teenager;
}

Adult createAdult(HealthPoints health, Age age) {
    Adult adult(health, age);
    return adult;
}

Sheriff createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    Sheriff sheriff(health, age, attackPower);
    return sheriff;
}
