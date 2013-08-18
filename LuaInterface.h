extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <iostream>
#include <fstream>
#include <string>

class LuaInterface{

private:
  
public:
  LuaInterface();
  ~LuaInterface();

  static lua_State *L;

  static void loadScript(const char* );
  /*void Update();*/
  static void initialize();

};
