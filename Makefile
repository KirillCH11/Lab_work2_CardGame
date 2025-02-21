CXX := g++
CXXFLAGS := -Wall -std=c++17

SRC := main.cpp
TEST_SRC := tests/test.cpp

EXEC := CardGame
TEST_EXEC := TestCardGame

all: $(EXEC) $(TEST_EXEC)

$(EXEC): $(SRC)
    $(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_EXEC): $(TEST_SRC)
    $(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_EXEC)
    ./$(TEST_EXEC)

clean:
    rm -f $(EXEC) $(TEST_EXEC)

.PHONY: all test clean
