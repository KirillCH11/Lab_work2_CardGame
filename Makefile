CXX = g++
AR = ar
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -Wpedantic -Iinclude -g
ARFLAGS = rcs

PROJECT = MyAwesomeGame
LIBPROJECT = lib$(PROJECT).a

GAME_SRCS = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
GAME_OBJS = $(GAME_SRCS:.cpp=.o)

all: $(PROJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIBPROJECT): $(GAME_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(PROJECT): $(LIBPROJECT) src/main.o
	$(CXX) $(CXXFLAGS) -o $@ src/main.cpp -L. -l:$(LIBPROJECT)

clean:
	rm -f src/*.o *.o

cleanall: clean
	rm -f $(PROJECT) $(LIBPROJECT)

