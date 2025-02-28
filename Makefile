CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = tests/test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

TARGET = CardGame
TEST_TARGET = TestCardGame

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

.PHONY: clean
