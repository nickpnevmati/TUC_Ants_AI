#ifndef _VMOVE_H
#define _VMOVE_H

#include "global.h"

//forward declaration
typedef struct vMove;
typedef struct vMoveNode;

//intrusive list node declaration
//may have many children but only one parent
typedef struct
{
	vMove* move;

	vMoveNode* next;
	vMoveNode* prev;
} vMoveNode;

//virtual move declaration
//basically the same as <<struct Move>>
//but holds more data so we can undo
//and evaluate it
typedef struct
{
	char tile[2][MAXIMUM_MOVE_SIZE];
	char color;
	int scoreGain;

	int eval;

	vMoveNode node;
} vMove;

//List util
vMoveNode* initvMList();

void vMpushBack(vMove* move);

void vMpushFront(vMove* move);

vMove* vMpopFront();

vMove* vMpopBack();




//executes the given move on the given board
//does NOT check if move is legal
void thinkMove(vMove* move, Position* state);

//undoes the given move
//DOES NOT check if undo is legal
void unthinkMove(vMove* move, Position* state);

//generates and returns a list of all possible moves
//for the given board and player
vMove** generateStepMoves(Position* state, char color);

//same as generateStepMoves only it returns jump moves
vMove** generateJumpMoves(Position* state, char color);

// returns if the given player has an available jump move
bool canJump(Position* state, char color);

// can specific pawn jump?
//if only left ret 1
//if only right ret 2
//if both ret 3
int canPawnJump(Position* state, int i, int j);

#endif