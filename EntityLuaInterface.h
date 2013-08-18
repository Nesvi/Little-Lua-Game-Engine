#ifndef _EntityLuaInterface
#define _EntityLuaInterface

#include "Entity.h"
#include "LuaInterface.h"

int LuaEntity_getY(lua_State *L);
int LuaEntity_getX(lua_State *L);
int LuaEntity_setPosition(lua_State *L);
int LuaEntity_newCInstance(lua_State *L);

class EntityLuaInterface : public LuaInterface {

private:
 

public:
 static std::vector<Entity*> entityInstances;
  static Entity* currentInstance;
  
  static int addNewInstance(Entity*);
  static void defineCFunctions();
  static void setInstance( Entity*);
  static void update();
  static void initGameEngine();
  static void loadMain();
};

#endif
