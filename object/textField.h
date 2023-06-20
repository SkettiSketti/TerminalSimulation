/*
*Copyright (C) 2023 Spaghetti. All rights reserved.
*/
#ifndef TEXTFIELD_H_INCLUDED
#define TEXTFIELD_H_INCLUDED
#include <iostream>
#include "SFML/Graphics.hpp"
#include "tileMap.h"

class TextField
{
private:
    const int WIDTH;
    const int HEIGHT;
    int charWidth = 12;
    int charHeight = 12;
    sf::Color frontColor;
    sf::Color backColor;
    //sf::Texture * texture;
    sf::RectangleShape * backRect;
    unsigned int * character;
    //sf::Sprite * sprite;
    TileMap tileMap;

   // sf::Sprite & getSprite(int x, int y);
    void setChar(int x, int y, unsigned int c);
    void setCharColor(int x, int y, sf:: Color color);
    void setBackColor(int x, int y, sf::Color color);
    sf::RectangleShape & getBackRect(int x, int y);
    bool isOutOfBounds(int x, int y);

public:
    TextField(int x, int y, sf::Texture & rTexture);
    void setFrontColor(sf::Color color);
    void setPair(sf::Color frontColor, sf::Color backColor);
    void print(int x, int y, std::string s);
    void printGlyph(int x, int y, unsigned int g);
    void draw(sf::RenderWindow &renderWindow);
    void box(int x, int y, int width, int height);
    void changeTileBackColor(int x, int y, sf::Color c);
    void clear();
    sf::Vector2i getSize();

};

#endif // TEXTFIELD_H_INCLUDED
