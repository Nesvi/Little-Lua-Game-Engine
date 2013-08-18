#include "Entity.h"
#include "EntityLuaInterface.h"

sf::Texture Entity::texture;

void Entity::InitializeStatic(){

  texture.loadFromFile("./Img/G.tga");

}

Entity::Entity(){
  
  sprite.setTexture(texture);
  EntityLuaInterface::currentInstance = this;
}

sf::Sprite Entity::Draw(){
  return sprite;
}

void Entity::Update(){
  EntityLuaInterface::setInstance(this);
  EntityLuaInterface::update();
  
}

void Entity::setPosition(const float& x, const float& y){

  sprite.setPosition(x,y);

}

float Entity::getX(){

  return sprite.getPosition().x;

}

float Entity::getY(){

  return sprite.getPosition().y;

}
