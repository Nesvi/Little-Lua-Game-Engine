#ifndef _Entity
#define _Entity
#include <SFML/Graphics.hpp>

class Entity{

 private:
  sf::Sprite sprite;
  static sf::Texture texture;
 public:
  int lua_id;
  Entity();

  static void InitializeStatic();

  sf::Sprite Draw();
  void Update();
  

  void setPosition(const float&, const float&);
  float getX();
  float getY();

};


#endif
