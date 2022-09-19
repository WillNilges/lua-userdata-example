// Lua C API
#include <lua.hpp>
// C++ input/output streams
#include <iostream>
 
// MyObject as C++ class
class MyObject{
	private:
		double x;
	public:
		MyObject(double x) : x(x){}
		void set(double x){this->x = x;}
		double get() const{return this->x;}
};
 
// MyObject identifier for the Lua metatable
#define LUA_MYOBJECT "MyObject"
 
static int myobject_new(lua_State* L);
 
// Free MyObject instance by Lua garbage collection
static int myobject_delete(lua_State* L);
 
// MyObject member functions in Lua
static int myobject_set(lua_State* L);

static int myobject_get(lua_State* L);
