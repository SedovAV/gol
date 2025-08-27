CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/Quest_1

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_DIR)/dmanager_module.c $(SRC_DIR)/door_struct.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)
