CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

GTEST_LIBS = -lgtest -lgtest_main -pthread

GAME_SRCS = game.cpp main.cpp
TEST_SRCS = test_game.cpp

GAME_OBJS = $(GAME_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

GAME_EXE = MyAwesomeGame
TEST_EXE = MyGameTests

all: $(GAME_EXE) $(TEST_EXE)

$(GAME_EXE): $(GAME_OBJS) game.h
	$(CXX) $(CXXFLAGS) -o $@ $(GAME_OBJS)

$(TEST_EXE): game.o $(TEST_OBJS) game.h
	$(CXX) $(CXXFLAGS) -o $@ game.o $(TEST_OBJS) $(GTEST_LIBS)

%.o: %.cpp game.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o
	rm -f $(GAME_EXE)
	rm -f $(TEST_EXE)

.PHONY: clean all
