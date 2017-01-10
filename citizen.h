#ifndef HORRORMOVIE2_CITIZEN_H
#define HORRORMOVIE2_CITIZEN_H

#include "helper.h"
#include "monster.h"

class Citizen : public virtual Living {
public:
    Citizen(HealthPoints healthPoints, Age age) : healthPoints_(healthPoints),  age_(age) {}

//    virtual ~Citizen() {}

    HealthPoints getHealth() const override;

    const Age getAge() const;

    void takeDamage(AttackPower damage) override;

    virtual void fightAgainstMonsters(GroupOfMonsters monsters);

private:
    HealthPoints healthPoints_;
    const Age age_;
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age);
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age);
};

class Sheriff : public Citizen, public virtual Attacking {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attackPower);

    const AttackPower getAttackPower() const override ;

    void fightAgainstMonsters(GroupOfMonsters monsters) ;

private:
    const void isAttackPowerValid(AttackPower attackPower) const;

    const AttackPower attackPower_;
};

Teenager createTeenager(HealthPoints health, Age age);

Adult createAdult(HealthPoints health, Age age);

Sheriff createSheriff(HealthPoints health, Age age, AttackPower attackPower);

#endif //HORRORMOVIE2_CITIZEN_H
