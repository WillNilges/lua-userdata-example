CC=g++

# Warnings
LUA_VERSION=5.4

output=myobject.so

build: *.cpp
	$(CC) $< -g -llua -fPIC -shared -o $(output)

clean:
	rm $(output)
