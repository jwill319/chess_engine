#include <stdio.h>
#include <assert.h>
#include "tests.h"
#include "bb.h"

int
test_pawn_singlepush(void)
{
    U64 wpawn, bpawn, empty, test;

    wpawn = setsq(0ULL, e2);
    empty = ~wpawn;

    wpawn = pawn_singlepush(empty, wpawn, WHITE);
    test = setsq(0ULL, e3);

    if (wpawn != test)
    {
        printf("FAILED: white pawn_singlepush is not equivalent\n");
        printboard(wpawn);
        printboard(test);
        return 0;
    }

    bpawn = setsq(0ULL, e7);
    empty = ~bpawn;

    bpawn = pawn_singlepush(empty, bpawn, BLACK);
    test = setsq(0ULL, e6);

    if (bpawn != test)
    {
        printf("FAILED: black pawn_singlepush is not equivalent\n");
        printboard(bpawn);
        printboard(test);
        return 0;
    }

    return 1;
}

int
test_pawn_doublepush(void)
{
    U64 wpawn, bpawn, empty, test;

    wpawn = setsq(0ULL, e2);
    empty = ~wpawn;

    wpawn = pawn_doublepush(empty, wpawn, WHITE);
    test = setsq(0ULL, e4);

    if (wpawn != test)
    {
        printf("FAILED: white pawn_doublepush is not equivalent\n");
        printboard(wpawn);
        printboard(test);
        return 0;
    }

    bpawn = setsq(0ULL, e7);
    empty = ~bpawn;

    bpawn = pawn_doublepush(empty, bpawn, BLACK);
    test = setsq(0ULL, e5);

    if (bpawn != test)
    {
        printf("FAILED: black pawn_doublepush is not equivalent\n");
        printboard(bpawn);
        printboard(test);
        return 0;
    }

    return 1;
}

int
main()
{
    assert(test_pawn_singlepush());
    assert(test_pawn_doublepush());
    return 0;
}
