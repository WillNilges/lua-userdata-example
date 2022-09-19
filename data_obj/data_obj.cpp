#include "data_obj.h"
// Create & return DataObj instance to Lua
static int dataobj_new(lua_State* L)
{
	int length = luaL_checkinteger(L, 1);
	*reinterpret_cast<DataObj**>(lua_newuserdata(L, sizeof(DataObj*))) = new DataObj(length);
	luaL_setmetatable(L, LUA_MYOBJECT);
	return 1;
}
 
// Free DataObj instance by Lua garbage collection
static int dataobj_delete(lua_State* L)
{
	delete *reinterpret_cast<DataObj**>(lua_touserdata(L, 1));
	return 0;
}
 
// DataObj member functions in Lua
static int dataobj_set(lua_State* L)
{
	(*reinterpret_cast<DataObj**>(luaL_checkudata(L, 1, LUA_MYOBJECT)))->set(luaL_checkinteger(L, 2), luaL_checkinteger(L, 3));
	return 0;
}

static int dataobj_get(lua_State* L)
{
	lua_pushnumber(L, (*reinterpret_cast<DataObj**>(luaL_checkudata(L, 1, LUA_MYOBJECT)))->get(luaL_checkinteger(L, 2)));
	return 1;
}
 
// Register DataObj to Lua
static void register_dataobj(lua_State* L){
	lua_register(L, LUA_MYOBJECT, dataobj_new);
	luaL_newmetatable(L, LUA_MYOBJECT);
	lua_pushcfunction(L, dataobj_delete); lua_setfield(L, -2, "__gc");
	lua_pushvalue(L, -1); lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, dataobj_set); lua_setfield(L, -2, "set"); // fixme: this might need to be -3 or some shit.
	lua_pushcfunction(L, dataobj_get); lua_setfield(L, -2, "get");
	lua_pop(L, 1);
}
 
extern "C" {
// Program entry
int luaopen_dataobj(lua_State *L)
{
		luaL_openlibs(L);
		register_dataobj(L);
	return 1;
}
}
