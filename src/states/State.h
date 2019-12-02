//
// Created by semyon on 30.11.2019.
//

#ifndef MY_OWN_GAME_STATE_H
#define MY_OWN_GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <stack>


enum GlobalVariables
{
    GRID_SIZE,
};

class State
{
private:

protected:
    std::stack<State*>* states;
    sf::RenderWindow * window;
    bool quit;

    float gridSize;
    float keytime;
    float keytimeMax;

    //res
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;


    std::vector<sf::Texture> textures;


public:
    State(sf::RenderWindow * window,std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    const bool getKeyTime();


    virtual void checkForQuit();


    virtual void endState() = 0;
    virtual void updateMousePosition(sf::View* view = NULL);
    virtual void updateInput(const float& time) = 0;
    virtual void updateKeyTime(float time);
    virtual void update(float time) = 0;
    virtual void render(sf::RenderWindow * window) = 0;
};


#endif //MY_OWN_GAME_STATE_H
