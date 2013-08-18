#include "GameManager.h"

#define XRES 600
#define YRES 600

GameManager::GameManager(){
  

  App.create(sf::VideoMode( XRES, YRES), "Lua Test" );
  App.setFramerateLimit( 60 );
  App.setVerticalSyncEnabled(true);

  initialize();

  gameLoop();
  
}

void GameManager::gameLoop(){
 
  while ( App.isOpen() )
    {
      // Process events
      sf::Event event;
      while (App.pollEvent(event))
        {
	  // Close App : exit
	  if (event.type == sf::Event::Closed)
	    App.close();
        }
      // Clear screen
      App.clear();
      
      ET.restart();
      
      input();
      update();
      draw();
      
      // Update the App
      App.display();
	
    }

}

void GameManager::input(){
  /*
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) 
    Ship.GetBody()->ApplyForce( b2Vec2(-5.0f, 0.0f),
				Ship.GetBody()->GetWorldCenter()
				);

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) 
    Ship.GetBody()->ApplyForce( b2Vec2(5.0f, 0.0f),
				Ship.GetBody()->GetWorldCenter()
				);

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) 
    Ship.GetBody()->ApplyForce( b2Vec2(0.0f, -5.0f),
				Ship.GetBody()->GetWorldCenter()
				);

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) 
    Ship.GetBody()->ApplyForce( b2Vec2(0.0f, 5.0f),
				Ship.GetBody()->GetWorldCenter()
				);
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::N) ) 
    Start(2);+
  //NextLevel();//Start(0);
  */
}

void GameManager::update(){

  for( int i = 0; i < EntityLuaInterface::entityInstances.size(); i++)
    EntityLuaInterface::entityInstances[i]->Update();

}

void GameManager::draw(){
  //std::cout << "Tamaño de las entidades" << EntityLuaInterface::entityInstances.size() << std::endl;
  for( int i = 0; i < EntityLuaInterface::entityInstances.size(); i++)
    App.draw( EntityLuaInterface::entityInstances[i]->Draw() );

}

void GameManager::initialize(){

  ELI.initialize();
  ELI.defineCFunctions();
  ELI.loadMain();

  Entity::InitializeStatic();


  ELI.initGameEngine();
}


