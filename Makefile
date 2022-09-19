CC=g++

# Warnings
LUA_VERSION=5.4

output=myobject.so myfeature.so

.PHONY: build test

build: myobject.so myfeature.so

myobject.so: object/*.cpp
	$(CC) $< -g -llua -fPIC -shared -o $@

myfeature.so: feature/*.cpp
	$(CC) $< -g -llua -fPIC -shared -o $@

test: build
	@lua test.lua

clean:
	rm $(output)
