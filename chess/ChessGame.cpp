//
//  ChessGame.cpp
//  chess
//
//  Created by Sam Clark on 12/2/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessGame.hpp"

ChessGame::ChessGame(int scale): ChessWindow(scale + 250, scale, Color(232, 174, 81)) {
    this->board = new ChessBoard(scale, this);
    this->pickedUpPiece = nullptr;
    this->pickedUpPieceTile = nullptr;
    
    drawButton = new Button(0.8, 0.4, 0.15, 0.075, this, [&] {cout << "Ask for draw" << endl;});
    drawButton->setColor(Color(96, 108, 131));
    
    secedeButton = new Button(0.8, 0.6, 0.15, 0.075, this, [&] {
        this->renderWindow->close();
        MainWindow* mainWindow = new MainWindow();
        mainWindow->launch();
    });
    secedeButton->setColor(Color(96, 108, 131));
    
    this->board->setScale(scale);
}

void ChessGame::resizeEvent(Event event) {
    this->board->setScale(event.size.height);
    this->drawButton->update();
    this->secedeButton->update();
}
