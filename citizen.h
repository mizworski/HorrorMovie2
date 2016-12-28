#ifndef HORRORMOVIE2_CITIZEN_H
#define HORRORMOVIE2_CITIZEN_H

#include <cassert>

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

class Citizen {
public:
    Citizen(HealthPoints health, Age age) : health_(health), age_(age) {} //todo virtual?

    HealthPoints getHealth();

    Age getAge();

    void takeDamage(AttackPower damage);

protected:
    Age LOWER_BOUND_TEENAGER = 11;
    Age UPPER_BOUND_TEENAGER = 17;
    Age LOWER_BOUND_ADULT = 18;
    Age UPPER_BOUND_ADULT = 100;
private:
    HealthPoints health_; //todo change type
    Age age_; //todo
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age);
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age);
};

class Sheriff : public Citizen {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attack_power);

    AttackPower getAttackPower();

private:
    AttackPower attackPower;
};

Teenager createTeenager(HealthPoints health, Age age);

Adult createAdult(HealthPoints health, Age age);

Sheriff createSheriff(HealthPoints health, Age age, AttackPower attackPower);

#endif //HORRORMOVIE2_CITIZEN_H
