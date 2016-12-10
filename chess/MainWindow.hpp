//
//  MainWindow.hpp
//  chess
//
//  Created by Craig Conway on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef MainWindow_hpp
#define MainWindow_hpp

#include <ChessWindow.hpp>
#include <ChessGame.hpp>
#include <Button.hpp>

class MainWindow: public ChessWindow {
public:
    MainWindow();

private:
    Button* localButton;
    Button* multiplayerButton;
    virtual void resizeEvent(Event event) override;
    
    
};


#endif /* MainWindow_hpp */