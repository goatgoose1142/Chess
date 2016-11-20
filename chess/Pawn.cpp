//
//  Pawn.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Pawn.hpp"
#include "ChessBoard.hpp"

Pawn::Pawn(int x, int y, Player* player): Piece(x, y, player, "pawn") {
    hasMoved = false;
}

vector<Tile*> Pawn::getLegalMoves() {
    int teamDirection;
    if (player->getSide() == WHITE) {
        teamDirection = -1;
    } else {
        teamDirection = 1;
    }
    
    vector<Coordinate> moves;
    moves.push_back(Coordinate(x, y));
    moves.push_back(Coordinate(x, y + (1 * teamDirection)));
    
    if (!hasMoved) {
        moves.push_back(Coordinate(x, y + (2 * teamDirection)));
    }
    
    vector<Tile*> legalMoves;
    for (int i = 0; i < moves.size(); i++) {
        Coordinate move = moves[i];
        if (moveIsPossible(moves[i])) {
            legalMoves.push_back(board->getTile(move));
        }
    }
    
    Tile* diagonalLeft = board->getTile(Coordinate(x - 1, y + teamDirection));
    if (diagonalLeft->piece != nullptr && diagonalLeft->piece->getSide() != this->side) {
        legalMoves.push_back(diagonalLeft);
    }
    
    Tile* diagonalRight = board->getTile(Coordinate(x + 1, y + teamDirection));
    if (diagonalRight->piece != nullptr && diagonalRight->piece->getSide() != this->side) {
        legalMoves.push_back(diagonalRight);
    }
    
    return legalMoves;
}

void Pawn::moveTo(int x, int y) {
    Piece::moveTo(x, y);
    hasMoved = true;
}

