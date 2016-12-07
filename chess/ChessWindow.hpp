//
//  ChessWindow.hpp
//  chess
//
//  Created by Sam Clark on 12/2/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef ChessWindow_hpp
#define ChessWindow_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <Clickable.hpp>

using namespace sf;
using namespace std;

class ChessWindow {
public:
    ChessWindow(int x, int y, Color backgroundColor);
    
    void launch();
    
    void addClickable(Clickable* clickable);
    void removeClickable(Clickable* clickable);
    
    void addDrawable(Drawable* drawable);
    void removeDrawable(Drawable* drawable);
    
private:
    RenderWindow* renderWindow;
    
    vector<Clickable*> clickables;
    vector<sf::Drawable*> drawables;
    
    RectangleShape* background;
    
    virtual void resizeEvent(Event event) = 0;
};

#endif /* ChessWindow_hpp */