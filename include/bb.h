#ifndef BITBOARD_h
#define BITBOARD_h

// Bitboard type declaration
#define U64 unsigned long long


// Color side declaration
#define WHITE 0
#define BLACK 1

// Square enum declaration
typedef enum
{
    a1, b1, c1, d1, e1, f1, g1, h1,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a8, b8, c8, d8, e8, f8, g8, h8,
} square;

// Bitshift macros
#define move_up(board) (board << 8)
#define move_upright(board) (board << 9)
#define move_upleft(board) (board << 7)
#define move_right(board) (board << 1)
#define move_left(board) (board >> 1)
#define move_down(board) (board >> 8)
#define move_downright(board) (board >> 7)
#define move_downleft(board) (board >> 9)

// Game board declaration
struct game
{
    U64 empty;
    U64 white;
    U64 black;

    U64 w_pawns;
    U64 b_pawns;
};

// Move mask function declarations
U64             pawn_singlepush(U64, U64, char);

// Debug function declaration
#define         setsq(board, square) (board | (1ULL << square))
#define         getsq(board, square) (board & (1ULL << square))
void            printboard(U64);

#endif
