#include <stdio.h>
#include "bb.h"

// Pawn move mask function
U64
pawn_singlepush(U64 empty, U64 pawn, char side)
{
    if (side == WHITE)
    {
        return (empty & move_up(pawn));
    } else {
        return (empty & move_down(pawn));
    }
}

U64
pawn_doublepush(U64 empty, U64 pawn, char side)
{
    U64 pawn_mask = pawn_singlepush(empty, pawn, side);
    pawn_mask = pawn_singlepush(empty, pawn_mask, side);
    return (side ? rank4 : rank5) & pawn_mask;
}



// Testing and debugging
void
printboard(U64 board)
{
    printf("\nBoard:\n");

    int rank, file, index;
    for (rank = 0; rank < 8; rank++)
    {
        for (file = 0; file < 8; file++)
        {
            index = (8 * rank) + file;

            printf(" %d ", (board & (1ULL << index)) ? 1 : 0);
        }
        printf("\n");
    }

    printf("Hex Value: %llx\n", board);
}
