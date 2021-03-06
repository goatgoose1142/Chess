//
//  Pawn.cpp
//  chess
//
//  Created by Sam Clark
//

#include "Pawn.hpp"
#include "ChessBoard.hpp"

Pawn::Pawn(int x, int y, Player* player): Piece(x, y, player, "pawn") {
    hasMoved = false;
}

vector<Tile*> Pawn::getLegalMoves() {
    int teamDirection;
    if (player->getSide() == WHITE) {
        teamDirection = 1;
    } else {
        teamDirection = -1;
    }
    
    vector<Coordinate> moves;
    if (board->getTile(Coordinate(x, y + (1 * teamDirection)))->piece == nullptr) {
        moves.push_back(Coordinate(x, y + (1 * teamDirection)));
        
        Coordinate twoAhead(x, y + (2 * teamDirection));
        if (!hasMoved && player->board->getTile(twoAhead)->piece == nullptr) {
            moves.push_back(twoAhead);
        }
    }
    
    vector<Tile*> legalMoves;
    for (int i = 0; i < moves.size(); i++) {
        Coordinate move = moves[i];
        if (moveIsPossible(move)) {
            legalMoves.push_back(board->getTile(move));
        }
    }
    
    Tile* diagonalLeft = board->getTile(Coordinate(x - 1, y + teamDirection));
    if (moveIsPossible(diagonalLeft)) { // if the tile exists
        if (diagonalLeft->piece != nullptr) { // if the tile contains a piece
            if (diagonalLeft->piece->getSide() != this->side) { // if it's an enemy
                legalMoves.push_back(diagonalLeft);
            }
        }
    }
    
    Tile* diagonalRight = board->getTile(Coordinate(x + 1, y + teamDirection));
    if (moveIsPossible(diagonalRight)) {
        if (diagonalRight->piece != nullptr) {
            if (diagonalRight->piece->getSide() != this->side) {
                legalMoves.push_back(diagonalRight);
            }
        }
    }
    
    return legalMoves;
}

void Pawn::moveTo(Tile* tile) {
    Piece::moveTo(tile);
    hasMoved = true;
}

