
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../../../include/Engine/renderer/Renderer2D.h"
#include "../../../platform/Window/SFMLWindow.h"
#include "../../../include/SandBox/start/Application.h"


int main()

{
 std::cout<< "Engine is work" << std::endl;

 /*
 sf::RenderWindow window(sf::VideoMode(800,600),"hello");


 while(window.isOpen())
 {
  sf::Event event;

  while(window.pollEvent(event))
  {
   if(event.type ==sf::Event::Closed)
    window.close();
  }

  window.clear();

  window.display();
 }
*/
 Application app;
 app.Run();


 return 0;
 }
