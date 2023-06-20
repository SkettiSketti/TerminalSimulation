/*
*Copyright (C) 2023 Spaghetti. All rights reserved.
*/

#include "textField.h"


/**
*
*Constructor for the Text Field Array.
*@param x The width of the text field (in characters).
*@param y The height of the text field (in characters).
*
**/
TextField::TextField(int x, int y, sf::Texture & rTexture):
    WIDTH(x),
    HEIGHT(y)
{
    character = new unsigned int[x*y];

    backRect = new sf::RectangleShape[x*y];
    frontColor = sf::Color::White;
    backColor = sf::Color::Black;
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            getBackRect(x,y).setPosition(charWidth*x,charHeight*y);
            getBackRect(x,y).setSize(sf::Vector2f(charWidth,charHeight));
            setBackColor(x,y,sf::Color::Black);
            character[(WIDTH*y)+x] = 'c';
        }
    }

    if (!tileMap.load("image/tiles12x12.png",sf::Vector2u(12,12),character,WIDTH,HEIGHT))
    {
        std::cout << "Failed" << std::endl;
        exit(0);
    }
    setChar(0,0,'@');

    ///////////////////////////
    //TODO: warning
    //Testing stuff down here
    //
    ///////////////////////////

    //print(2,2,"Hello World!");

}

/**
*Draw the text field to the render window.
*@param renderWindow The SFML Renderwindow to draw to.
**/
void TextField::draw(sf::RenderWindow &renderWindow)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            renderWindow.draw(getBackRect(x,y));
        }
    }
    renderWindow.draw(tileMap);
}

/**
*This method is PRIVATE. Use printGlyph.
*Draw a character at a coorinate position.
*@param x - The x coordinate of the (x,y) pair
*@param y - The y coordinate of the (x,y) pair
*@param c - The character to set at the (x,y) coordinate
**/
void TextField::setChar(int x, int y, unsigned int c)
{
    if (isOutOfBounds(x,y))
        return;

    tileMap.changeTile(x,y,c);
}
/**
*This method is PRIVATE. Use setPair or setFrontColor.
*Set the foreground colour of a character
*@param x - The x coordinate of the (x,y) pair
*@param y - The y coordinate of the (x,y) pair
*@param color - The color for the character
**/
void TextField::setCharColor(int x, int y, sf::Color color)
{
    if (isOutOfBounds(x,y)) return;
    tileMap.changeTileColor(x,y,color);
}
/**
*This method is PRIVATE. Use setPair or changeTileBackColor.
*Set the background colour of a character
*@param x - The x coordinate of the (x,y) pair
*@param y - The y coordinate of the (x,y) pair
*@param color - The color for the character
**/
void TextField::setBackColor(int x, int y, sf::Color color)
{
    if (isOutOfBounds(x,y)) return;
    getBackRect(x,y).setFillColor(color);
}

/**
*A private method
**/
sf::RectangleShape &TextField::getBackRect(int x, int y)
{
    return backRect[(WIDTH*y)+x];
}

/**
*Clear the screen
**/
void TextField::clear()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            setCharColor(x,y,sf::Color(0,0,0,0));
            setBackColor(x,y,sf::Color::Black);
            setChar(x,y,' ');
        }
    }
}

/**
*Check if a tile is outside of the screen space
*@return If position is inside valid screen position, then return true otherwise false
**/
bool TextField::isOutOfBounds(int x, int y)
{
    return (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0);
}

/**
*Print a string to the screen
*String placement begins at coordinate pair (x,y) and then subsequent characters continue to the right.
**/
void TextField::print(int x, int y, std::string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        setCharColor(x+i,y,frontColor);
        setBackColor(x+i,y,backColor);
        setChar(x+i,y,s.at(i));
    }
}

/**
*Prints a character (a.k.a. Glyph) to the screen.
*@param g - A character to print to the screen.
*Note: Instead of an unsigned int you can just use a char
*Example: textField.printGlyph(0,0,'@');
**/
void TextField::printGlyph(int x, int y, unsigned int g)
{
    setCharColor(x,y,frontColor);
    setBackColor(x,y,backColor);
    setChar(x,y,g);
}

/**
*Set tile front color
**/
void TextField::setFrontColor(sf::Color color)
{
    frontColor = color;
}

/**
*Set front and back color for a tile
**/
void TextField::setPair(sf::Color frontColor, sf::Color backColor)
{
    setFrontColor(frontColor);
    this->backColor = backColor;
}

/**
*Draw a box (Can't guarentee this works. It's old.)
**/
void TextField::box(int x, int y, int width, int height)
{
    for(int w = 0; w < width; w++)
    {
        for(int h = 0; h < height; h++)
        {
            print(x+w,y+h," ");
            if (w == 0 || w == width-1) //left side or right
            {
                print(x+w,y+h,std::string(1,179));
            }
            if (h == 0 || h == height-1) //left side or right
            {
                print(x+w,y+h,std::string(1,196));
            }
        }
    }

    setChar(x,y,218);
    setChar(x+width-1,y,16*11+15);
    setChar(x,y+height-1,16*12);
    setChar(x+width-1,y+height-1,16*13+9);

}

/**
*Get the size of the textfield as a 2D Integer Vector.
**/
sf::Vector2i TextField::getSize()
{
    return sf::Vector2i(WIDTH,HEIGHT);
}

/**
*Change the background color of an integer
**/
void TextField::changeTileBackColor(int x, int y, sf::Color c)
{
    setBackColor(x,y,c);
}
