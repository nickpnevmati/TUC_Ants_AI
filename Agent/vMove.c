#include "vMove.h"

vMoveNode* initvMList()
{
	vMoveNode* node = (vMoveNode*) malloc(sizeof(vMoveNode));
	node->next = node;
	node->previous = node;
}

vMoveNode* initvMList(vMove* move)
{
	vMoveNode* node = (vMoveNode*) malloc(sizeof(vMoveNode));
	node->next = node;
	node->previous = node;
	node->move = move;
}

void vMpushBack(vMoveNode* list, vMove* move)
{
	vMoveNode* newNode = initvMList(move);
}

void vMpushFront(vMoveNode* list, vMove* move);

vMove* vMpopFront(vMoveNode* list);

vMove* vMpopBack(vMoveNode* list);


//executes the given move on the given board
//does NOT check if move is legal
void thinkMove(vMove* move, Position* state)
{

}

//undoes the given move
//DOES NOT check if undo is legal
void unthinkMove(vMove* move, Position* state)
{

}

//generates and returns a list of all possible moves
//for the given board and player
vMove** generateStepMoves(Position* state, char color)
{

}

//Why double pointer?
vMove** generateJumpMoves(Position* state, char color)
{
	for (int i = 0; i < BOARD_ROWS; ++i)
	{
		for (int j = 0; j < BOARD_COLUMNS; ++j)
		{
			int possibleJumps = canPawnJump(state, i, j);
		}
	}
}

/*
Returns whether pawn can jump and where
	no jump => 0 
	jump left => 1
	jump right => 2
	jump both => 3
*/
int canPawnJump(Position* state, int i, int j)
{
	//if i,j doesnt have a pawn return
	if(state->board[i, j] != WHITE
		&& state->board[i, j] != BLACK) 
		return 0;

	//get direcction of i,j color
	int forward = state->board[i, j] == WHITE ? 2 : -2;
	char color = state->board[i, j];
	int retVal = 0;

	//if jump out of bounds return
	if(i + 2 * forward >= BOARD_ROWS || i + 2 * forward < 0)
		return retVal;


	//TODO replace multiple if statements with ORs
	if(j + 2 < BOARD_COLUMNS)
	{
		if(state->board[i + forward, j + 2] != getOtherSide(color)
			&& state->board[i + forward, j + 2] != color
			&& state->board[i + 1/2 * forward, j + 1] == getOtherSide(color))
			retVal++;
	}

	if(j - 2 >= 0)
	{
		if(state->board[i + forward, j - 2] != getOtherSide(color)
			&& state->boforwardard[i + forward, j - 2] != color
			&& state->board[i + 1/2 * forward, j - 1] == getOtherSide(color))
			retVal += 2;
	}
	return retVal;
}