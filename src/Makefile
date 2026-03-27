# Oracle home
ORACLE_HOME ?= /opt/oracle/product/19c/dbhome_1

# Tools
PROC = proc
CC   = gcc

# Paths
INC_DIR = ../include
LIB_DIR = ../lib
OBJ_DIR = ../obj
BIN_DIR = ../bin

# Target
TARGET = $(BIN_DIR)/app

# Compiler flags
CFLAGS  = -I$(INC_DIR) -I$(ORACLE_HOME)/precomp/public -Wall -Wextra
LDFLAGS = -L$(ORACLE_HOME)/lib -lclntsh

# Source files
MAIN_PC = main.pc
DB_PC   = $(LIB_DIR)/db.pc

# Generated C files
MAIN_C = $(OBJ_DIR)/main.c
DB_C   = $(OBJ_DIR)/db.c

# Object files
MAIN_O = $(OBJ_DIR)/main.o
DB_O   = $(OBJ_DIR)/db.o

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Step 1: Pro*C -> C
$(MAIN_C): $(MAIN_PC)
	$(PROC) iname=$(MAIN_PC) oname=$(MAIN_C) include=$(INC_DIR)

$(DB_C): $(DB_PC)
	$(PROC) iname=$(DB_PC) oname=$(DB_C) include=$(INC_DIR)

# Step 2: C -> Object
$(MAIN_O): $(MAIN_C)
	$(CC) $(CFLAGS) -c $(MAIN_C) -o $(MAIN_O)

$(DB_O): $(DB_C)
	$(CC) $(CFLAGS) -c $(DB_C) -o $(DB_O)

# Step 3: Object -> Binary
$(TARGET): $(MAIN_O) $(DB_O)
	$(CC) $(MAIN_O) $(DB_O) -o $(TARGET) $(LDFLAGS)

run: all
	$(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.c $(OBJ_DIR)/*.o $(TARGET)

rebuild: clean all

.PHONY: all dirs run clean rebuild