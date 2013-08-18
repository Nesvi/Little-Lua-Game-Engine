#ifndef _GameManager
#define _GameManager

#include <vector>
#include <SFML/Graphics.hpp>
#include "EntityLuaInterface.h"


class GameManager{

 private:
  sf::Clock ET;

  sf::RenderWindow App;

  EntityLuaInterface ELI;

  Entity* entity;

 public:

  GameManager();

  void gameLoop();
  void update();
  void draw();
  void input();  

  void initialize();

};

#endif 
