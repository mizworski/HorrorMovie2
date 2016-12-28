#ifndef HORRORMOVIE2_MONSTER_H
#define HORRORMOVIE2_MONSTER_H

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

#include <vector>

class Monster {
public:
    Monster(HealthPoints health, AttackPower attackPower);

    HealthPoints getHealth();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);

private:
    HealthPoints health_; //todo change type
    AttackPower attackPower_;
};

class Zombie : public Monster {
public :
    Zombie(HealthPoints health, AttackPower attackPower);
};

class Vampire : public Monster {
public :
    Vampire(HealthPoints health, AttackPower attackPower);
};

class Mummy : public Monster {
public :
    Mummy(HealthPoints health, AttackPower attackPower);
};

class GroupOfMOnsters {
public:
    GroupOfMOnsters(const std::vector<Monster> &monsters);

    // todo do we need 2 constructors for lvalues and rvalues?
    GroupOfMOnsters(std::vector<Monster> &&monsters);

    //todo need constructor(s) for std::initializer_list

    HealthPoints getHealth();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);

private:
    std::vector<Monster> monsters_;
    HealthPoints health_; //todo change type
    AttackPower attackPower_;
};

Zombie createZombie(HealthPoints health, AttackPower attackPower);

Vampire createVampire(HealthPoints health, AttackPower attackPower);

Mummy createMummy(HealthPoints health, AttackPower attackPower);

#endif //HORRORMOVIE2_MONSTER_H
