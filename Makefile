CXX = g++
AR = ar
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -g
ARFLAGS = rcs

PROJECT = MyAwesomeGame
LIBPROJECT = lib$(PROJECT).a
TESTPROJECT = test-$(PROJECT)

GAME_SRCS = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
GAME_OBJS = $(GAME_SRCS:.cpp=.o)

TEST_SRCS = test_game.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

.PHONY: all clean cleanall test

all: $(PROJECT) $(TESTPROJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIBPROJECT): $(GAME_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(PROJECT): $(LIBPROJECT) src/main.o
	$(CXX) $(CXXFLAGS) -o $@ src/main.cpp -L. -l:$(LIBPROJECT)

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJS) -L. -l:$(LIBPROJECT) -lgtest -lgtest_main -pthread

clean:
	rm -f src/*.o *.o

cleanall: clean
	rm -f $(PROJECT) $(TESTPROJECT) $(LIBPROJECT)

test: $(TESTPROJECT)
	./$(TESTPROJECT)
