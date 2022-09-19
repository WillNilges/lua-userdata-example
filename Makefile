CC=g++

# Warnings
LUA_VERSION=5.4

output=myobject.so myfeature.so dataobj.so

.PHONY: build test

build: $(output) 

myobject.so: object/*.cpp
	$(CC) $< -g -llua -fPIC -shared -o $@

myfeature.so: feature/*.cpp
	$(CC) $< -g -llua -fPIC -shared -o $@

dataobj.so: data_obj/*.cpp
	$(CC) $< -g -llua -fPIC -shared -o $@

test: build
	@lua test.lua

clean:
	rm $(output)
