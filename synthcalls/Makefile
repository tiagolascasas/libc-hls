# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -fPIC
LDFLAGS = -shared

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
BUILD_DIR = build

# Library files
LIB_SRC = $(SRC_DIR)/synthcalls.c
LIB_SO = $(BUILD_DIR)/libsynthcalls.so

# Test files
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)  # Find all .c files in the test directory
TEST_EXEC = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%, $(TEST_SRC))  # Map .c to executables

# Default target: build the library and all test programs
all: $(LIB_SO) tests

# Build the shared library
$(LIB_SO): $(LIB_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIB_SRC) -o $(LIB_SO)

# Build all test programs
tests: $(TEST_EXEC)

# Rule to build each test program
$(BUILD_DIR)/%: $(TEST_DIR)/%.c $(LIB_SO) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ -L$(BUILD_DIR) -lsynthcalls

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run all test programs sequentially
run-tests: tests
	@echo "Running all tests..."
	@for exec in $(TEST_EXEC); do \
		echo "Running $$exec:"; \
		LD_LIBRARY_PATH=$(BUILD_DIR) $$exec; \
	done

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean tests run-tests
