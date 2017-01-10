#ifndef HORRORMOVIE2_HELPER_H
#define HORRORMOVIE2_HELPER_H

#include <cassert>
#include <memory>

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

class Living {
public:
    virtual HealthPoints getHealth() const = 0;

    virtual void takeDamage(AttackPower damage) = 0;
};

class Attacking {
public:
    virtual AttackPower getAttackPower() const = 0;
};

#endif //HORRORMOVIE2_HELPER_H
