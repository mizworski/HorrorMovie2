#include <iostream>
#include "citizen.h"
#include "smalltown.h"

int main() {


    auto groupOfMonsters = createGroupOfMonsters({
        createMummy(90, 1),
        createZombie(20, 1),
        createVampire(30, 1)
    });
    auto smallTown = SmallTown::Builder()
        .monster(groupOfMonsters)
        .startTime(3)
        .maxTime(27)
        .citizen(createSheriff(100, 35, 20))
        .citizen(createAdult(100, 21))
        .citizen(createTeenager(50, 14))
        .build();

    smallTown.tick(18);
    smallTown.tick(3);


    auto status_ = smallTown.getStatus();
    assert(status_.getMonsterName() == "GroupOfMonsters");
    assert(status_.getMonsterHealth() == 80);
    assert(status_.getAliveCitizens() == 3);

    // simple Draw Test
    groupOfMonsters = createGroupOfMonsters({
                                                         createMummy(50, 1000)
                                                 });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createSheriff(100, 100, 2000))
            .build();

    smallTown.tick(3);
    auto status = smallTown.getStatus();
    assert(status.getAliveCitizens()==0);
    assert(status.getMonsterHealth()==0);

    // simple win test
    groupOfMonsters = createGroupOfMonsters({
                                                    createMummy(50, 1)
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createSheriff(100, 100, 2000))
            .build();

    smallTown.tick(3);
    status = smallTown.getStatus();
    assert(status.getAliveCitizens()==1);
    assert(status.getMonsterHealth()==0);



    // win test for a group
    groupOfMonsters = createGroupOfMonsters({
                                                    createMummy(50, 1),
                                                    createVampire(50,1),
                                                    createVampire(50,1),
                                                    createVampire(50,1),
                                                    createZombie(50,1)
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createSheriff(10, 100, 2000))
            .build();

    smallTown.tick(3);
    status = smallTown.getStatus();
    assert(status.getAliveCitizens()==1);
    assert(status.getMonsterHealth()==0);



    // draw test for a group
    groupOfMonsters = createGroupOfMonsters({
                                                    createMummy(50, 1),
                                                    createVampire(50,1),
                                                    createVampire(50,8),
                                                    createVampire(50,1),
                                                    createZombie(50,1)
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createSheriff(10, 100, 2000))
            .build();

    smallTown.tick(3);
    status = smallTown.getStatus();
    assert(status.getAliveCitizens()==0);
    assert(status.getMonsterHealth()==0);



    // lose test for a group
    groupOfMonsters = createGroupOfMonsters({
                                                    createMummy(50, 1),
                                                    createVampire(20000,1),
                                                    createVampire(50,8),
                                                    createVampire(50,1),
                                                    createZombie(50,1)
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createSheriff(10, 100, 2000))
            .build();

    smallTown.tick(3);
    status = smallTown.getStatus();
    assert(status.getAliveCitizens()==0);
    assert(status.getMonsterHealth()!=0);

    // time moves by 7 and 3 not following 21 test
    groupOfMonsters = createGroupOfMonsters({
                                                    createMummy(50, 1)
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(1)
            .maxTime(27)
            .citizen(createSheriff(1, 100, 1))
            .build();

    assert(smallTown.getStatus().getAliveCitizens()==1);
    smallTown.tick(20);
    assert(smallTown.getStatus().getAliveCitizens()==1);
    smallTown.tick(3);
    smallTown.tick(3);
    assert(smallTown.getStatus().getAliveCitizens()==0);


    // group of sheeps test
    groupOfMonsters = createGroupOfMonsters({
                                                    createVampire(20000,20),
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .build();

    smallTown.tick(3);
    status = smallTown.getStatus();
    assert(status.getAliveCitizens()==0);
    assert(status.getMonsterHealth()==20000);



    // group of sheeps test
    groupOfMonsters = createGroupOfMonsters({
                                                    createVampire(20000,20),
                                            });
    smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .citizen(createAdult(10, 100))
            .build();

    smallTown.tick(3);
    status = smallTown.getStatus();
    assert(status.getAliveCitizens()==0);
    assert(status.getMonsterHealth()==20000);

    return 0;
}
