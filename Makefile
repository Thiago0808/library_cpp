# ============================================================
#  Makefile - C++ Library Project
# ============================================================

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC_DIR  = src
INC_DIR  = include
BUILD    = build

SOURCES  = $(SRC_DIR)/main.cpp \
           $(SRC_DIR)/book.cpp \
           $(SRC_DIR)/library.cpp \
           $(SRC_DIR)/utils.cpp

TARGET   = library

# Default rule
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(SOURCES) -o $(TARGET)
	@echo "\nCompiled successfully! Run: ./$(TARGET)\n"

# Cleanup
clean:
	rm -f $(TARGET)

.PHONY: all clean
