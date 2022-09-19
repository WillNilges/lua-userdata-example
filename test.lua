myfeature = require "myfeature"
myobject = require "myobject"

local obj = MyObject(42)

print(obj:get())    -- 42
obj:set(-1.5)
print(obj:get())    -- -1.5

myfeature.do_thing()
