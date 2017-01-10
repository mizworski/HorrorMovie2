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
    virtual const AttackPower getAttackPower() const = 0;
};

/*
class LivingBeing : public virtual Living {
public:
    LivingBeing(HealthPoints healthPoints);

    HealthPoints getHealth() const override;

    void takeDamage(AttackPower damage) override;

private:
    HealthPoints healthPoints_;
};

class AttackingBeing : public virtual Attacking {
public:
    AttackingBeing(AttackPower attackPower);

    AttackPower getAttackPower() const;

private:
    AttackPower attackPower_;
};
*/

#endif //HORRORMOVIE2_HELPER_H
