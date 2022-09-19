myfeature = require "myfeature"
myobject = require "myobject"
dataobj = require "dataobj"

local obj = MyObject(42)

print(obj:get())    -- 42
obj:set(-1.5)
print(obj:get())    -- -1.5

object = myfeature.do_thing()

print(object:get()) -- busted

data = DataObj(10)

-- Lol the C++ is still zero-indexed. Gotta watch out for that.
data:set(1398398, 1)
print(data:get(1))
data:set(1414141, 0)
print(data:get(0))
data:set(22222, 1)
print(data:get(1))
print(data:get(2))
