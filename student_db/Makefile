CC = gcc

DEBUG_FLAGS = -g -Wall
RELEASE_FLAGS = -O2 -Wall

MODE ?= debug

ifeq ($(MODE),debug)
CFLAGS = $(DEBUG_FLAGS)
else
CFLAGS = $(RELEASE_FLAGS)
endif

INCLUDE = -Iinclude

SRC_DIR = src
APP_DIR = apps
BUILD_DIR = build
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
APP_FILES = $(wildcard $(APP_DIR)/*.c)

SRC_OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
APP_OBJ = $(patsubst $(APP_DIR)/%.c,$(BUILD_DIR)/%.o,$(APP_FILES))

COMMON_OBJ = $(BUILD_DIR)/add_student.o \
             $(BUILD_DIR)/search_student.o \
             $(BUILD_DIR)/display_student.o \
             $(BUILD_DIR)/file_ops.o \
             $(BUILD_DIR)/common.o

all: directories \
     $(BIN_DIR)/add_student \
     $(BIN_DIR)/search_student \
     $(BIN_DIR)/display_student

directories:
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

$(BIN_DIR)/add_student: $(BUILD_DIR)/add_main.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/search_student: $(BUILD_DIR)/search_main.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/display_student: $(BUILD_DIR)/display_main.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

$(BUILD_DIR)/%.o: $(APP_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

run:
	./bin/display_student

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(BUILD_DIR)/*.d
