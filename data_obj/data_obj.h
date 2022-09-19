// Lua C API
#include <lua.hpp>
// C++ input/output streams
#include <iostream>
 
// DataObj as C++ class
class DataObj{
	private:
		int* Points;
        int length;
	public:
		DataObj(int req_length)
        {
            Points = (int*) malloc(sizeof(int) * req_length);
            length = req_length;
        }
		//DataObj(int x) : x(x){} // todo: delet
		void set(int x, int pos){this->Points[pos] = x;}
		double get(int pos) const{return this->Points[pos];}
};
 
// DataObj identifier for the Lua metatable
#define LUA_MYOBJECT "DataObj"
 
static int dataobj_new(lua_State* L);
 
// Free DataObj instance by Lua garbage collection
static int dataobj_delete(lua_State* L);
 
// DataObj member functions in Lua
static int dataobj_set(lua_State* L);

static int dataobj_get(lua_State* L);
