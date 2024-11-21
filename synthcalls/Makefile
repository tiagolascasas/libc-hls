# Compiler and flags
CC = gcc
CXX = g++
CFLAGS = -Iinclude -Wall -Wextra -fPIC
CXXFLAGS = -Iinclude -Wall -Wextra
LDFLAGS = -shared

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
BUILD_DIR = build

# Library files
LIB_SRC = $(SRC_DIR)/async.c $(SRC_DIR)/sync.c
LIB_SO = $(BUILD_DIR)/libsynthcalls.so

# Test files
TEST_C_SRC = $(wildcard $(TEST_DIR)/*.c)        # Find all .c files in the test directory
TEST_CPP_SRC = $(wildcard $(TEST_DIR)/*.cpp)    # Find all .cpp files in the test directory

TEST_C_EXEC = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%, $(TEST_C_SRC))   # Map .c to executables
TEST_CPP_EXEC = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%, $(TEST_CPP_SRC)) # Map .cpp to executables

# Combine all test executables
TEST_EXEC = $(TEST_C_EXEC) $(TEST_CPP_EXEC)

# Default target: build the library and all test programs
all: $(LIB_SO) tests

# Build the shared library
$(LIB_SO): $(LIB_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIB_SRC) -o $(LIB_SO)

# Build all test programs
tests: $(TEST_EXEC)

# Rule to build each C test program
$(BUILD_DIR)/%: $(TEST_DIR)/%.c $(LIB_SO) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ -L$(BUILD_DIR) -lsynthcalls

# Rule to build each C++ test program
$(BUILD_DIR)/%: $(TEST_DIR)/%.cpp $(LIB_SO) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -L$(BUILD_DIR) -lsynthcalls

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run all test programs sequentially
run-tests: tests
	@echo "Running all tests..."
	@for exec in $(TEST_EXEC); do \
		echo "\n--------------------------------\nRunning $$exec:"; \
		LD_LIBRARY_PATH=$(BUILD_DIR) $$exec; \
	done

# Run a single test program
run-%: $(BUILD_DIR)/%
	@echo "Running test $*..."
	LD_LIBRARY_PATH=$(BUILD_DIR) $<

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean tests run-tests run-%
