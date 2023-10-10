.PHONY: main

# List all the source files in the StanfordCPPLib directory
SRCS := $(wildcard 01-section-starterproj/lib/StanfordCPPLib/*.cpp)
STACKTRACE := $(wildcard 01-section-starterproj/lib/StanfordCPPLib/stacktrace/*.cpp)
PRIVATE := 01-section-starterproj/lib/StanfordCPPLib/private
HEADERS = 01-section-starterproj/lib/StanfordCPPLib
STACKTRACE_HEADERS := 01-section-starterproj/lib/StanfordCPPLib/stacktrace

main: 
	gcc -std=c++11 -I$(HEADERS) -I$(PRIVATE) -I$(STACKTRACE_HEADERS) -o main $(SRCS) $(STACKTRACE) 01-section-starterproj/src/problems.cpp
	./main
