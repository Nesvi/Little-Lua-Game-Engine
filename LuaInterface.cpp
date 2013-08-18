
#include "LuaInterface.h"

lua_State* LuaInterface::L;

LuaInterface::LuaInterface(){}

void LuaInterface::initialize(){
  L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L, "./LuaSystemScripts/LuaClassSystem.lua");
}

void LuaInterface::loadScript(const char* filename){
  
  luaL_dofile(L, filename);

}
/*
void LuaInterface::Update(){

  lua_getglobal(L, "update");
  lua_call(L, 0, 0);
  }*/

LuaInterface::~LuaInterface(){

 lua_close(L);

}


