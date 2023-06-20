/*
* Copyright (C) 2023 Spaghetti. All rights reserved.
* Example of how to use TextField.
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "object/textField.h"

#define TILE_SIZE 12 //Tiles are 12x12
#define SCREEN_SIZE_WIDTH 80
#define SCREEN_SIZE_HEIGHT 24

int main()
{
    sf::RenderWindow window(sf::VideoMode(TILE_SIZE * SCREEN_SIZE_WIDTH, TILE_SIZE * SCREEN_SIZE_HEIGHT), "Textfield Test");
    sf::Texture texture;

    if (!texture.loadFromFile("image/tiles12x12.png"))
    {
        std::cout << "tiles12x12.png failed to load\n";
    }

    //Set the textfield size and the texture we are using
    TextField textField(SCREEN_SIZE_WIDTH,SCREEN_SIZE_HEIGHT,texture);

    //=====================
    //Writing to the screen:
    //=====================
    textField.clear(); //Clear the screen of the test screen
    textField.print(0,0,"Hello World!");
    textField.setPair(sf::Color(255,0,255),sf::Color::White);
    textField.print(0,1,"Changing color...");
    textField.setPair(sf::Color::Blue,sf::Color::Black);
    textField.printGlyph(40,3,219); //219 is equal to the 'blank' character
    textField.printGlyph(43,3,219);
    textField.printGlyph(40,5,219);
    textField.printGlyph(41,5,219);
    textField.printGlyph(42,5,219);
    textField.printGlyph(43,5,219);
    textField.printGlyph(41,6,219);
    textField.printGlyph(42,6,219);

    textField.setPair(sf::Color::Magenta,sf::Color::White);
    textField.print(45,6,"< Hey! What's up?)");


    textField.setPair(sf::Color::Green,sf::Color::Black);
    textField.printGlyph(42,20,'#');

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        textField.draw(window); //draw the textField
        window.display();
    }

    return 0;
}
