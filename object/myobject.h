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
 
