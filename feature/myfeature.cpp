#include "myfeature.h"

int do_thing(lua_State *L)
{
    
    MyObject* object; // Declare pointer
    object = new MyObject(300); // Initialize pointer
    *reinterpret_cast<MyObject**>(lua_newuserdata(L, sizeof(MyObject*))) = object; // Make Lua aware of it
	luaL_setmetatable(L, LUA_MYOBJECT); // Metatable magic

    object->set(3000); // Mess with it

    std::cout << "Chom!\n";
    return 1;
}

extern "C" {
    //library to be registered
    static const struct luaL_Reg myfeature [] = {
          {"do_thing", do_thing},
          {NULL, NULL}  /* sentinel */
    };

    // Program entry
    int luaopen_myfeature(lua_State *L)
    {
        //luaL_openlibs(L);
        luaL_newlib(L, myfeature);
        return 1;
    }
}
