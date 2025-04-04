PROJECT = GameProject
LIBPROJECT = lib$(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
A = ar
AFLAGS = rcs
CXXFLAGS = -Iinclude -std=c++17 -Wall -Werror -Wpedantic -g -fPIC

LDXXFLAGS = $(CXXFLAGS) -Lbuild -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TEST_SRC = test.game.cpp
TEST_OBJ = $(BUILD_DIR)/test.game.o

.PHONY: all test clean cleanall

all: $(PROJECT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $(BUILD_DIR)/$@ $^

$(PROJECT): $(LIBPROJECT)

$(TEST_OBJ): $(TEST_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJ)
	$(CXX) -o $(BUILD_DIR)/$@ $(TEST_OBJ) $(LDGTESTFLAGS)

test: $(TESTPROJECT)
	./$(BUILD_DIR)/$(TESTPROJECT)

clean:
	rm -f $(BUILD_DIR)/*.o

cleanall: clean
	rm -f $(BUILD_DIR)/$(LIBPROJECT)
	rm -f $(BUILD_DIR)/$(TESTPROJECT)
