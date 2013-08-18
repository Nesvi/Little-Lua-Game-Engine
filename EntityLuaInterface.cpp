#include "EntityLuaInterface.h"
#include "ConvertInt.h"

/*
++++++Ejemplo de función que puede ser embedded

static int average(lua_State *L)
{
	// get number of arguments 
	int n = lua_gettop(L);
	double sum = 0;
	int i;

// loop through each argument 
	for (i = 1; i <= n; i++)
	{
		/* total the arguments 
		sum += lua_tonumber(L, i);
	}

// push the average 
	lua_pushnumber(L, sum / n);

// push the sum 
	lua_pushnumber(L, sum);

// return the number of results 
	return 2;
}
*/



//Estáticos
Entity* EntityLuaInterface::currentInstance;
std::vector<Entity*> EntityLuaInterface::entityInstances;

int LuaEntity_getY( lua_State *L){
 
  lua_pushnumber(L, 
		 EntityLuaInterface::currentInstance->getY()
		 );
  return 1;

}

int LuaEntity_getX( lua_State *L){
 
  lua_pushnumber(L, 
		 EntityLuaInterface::currentInstance->getX()
		 );
  return 1;

}

int LuaEntity_setPosition(lua_State *L){

  EntityLuaInterface::currentInstance->setPosition(
						   lua_tonumber(L, 1),
						   lua_tonumber(L, 2)
						   );
  
  return 0;
}

int LuaEntity_newCInstance(lua_State* L){

  Entity* aux = new Entity;
  aux->lua_id = lua_tonumber(L,1);
  EntityLuaInterface::currentInstance = aux;
  lua_pushnumber(L,EntityLuaInterface::addNewInstance(aux));
  return 1;
}

void EntityLuaInterface::defineCFunctions(){

  lua_register(L, "getX", LuaEntity_getX);

  lua_pushcfunction(L, LuaEntity_getY);
  lua_setglobal(L, "getY");

  lua_register(L, "setPosition", LuaEntity_setPosition);

  lua_register(L, "newCInstance", LuaEntity_newCInstance);

}

void EntityLuaInterface::loadMain(){

  loadScript("./LuaScripts/Main.lua");

}

void EntityLuaInterface::setInstance( Entity* in){

  currentInstance = in;

}

void EntityLuaInterface::update(){

  std::string auxString = "system_class_instances[";
  auxString += ConvertInt(currentInstance->lua_id);
  auxString += "]:update()";

  luaL_dostring(L, auxString.c_str());
}

int EntityLuaInterface::addNewInstance(Entity* in){

  entityInstances.push_back( in );
  return entityInstances.size()-1;

}

void EntityLuaInterface::initGameEngine(){

  lua_getglobal(L, "Start");
  lua_call(L,0,0);

}
