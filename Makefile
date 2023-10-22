.PHONY: main

# List all the source files in the StanfordCPPLib directory
SRCS := $(wildcard libs/*.cpp)
MAIN := main.cpp
EXE := main

main:
	g++ -Isrc/Include -I./libs  -std=c++11 -Lsrc/lib -o $(EXE) $(MAIN) $(SRCS) -lmingw32 -lSDL2_image  -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer
	./$(EXE)