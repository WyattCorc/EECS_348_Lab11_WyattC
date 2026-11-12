CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
 
TARGET := lab11
SRC    := Lab11.cpp
 
all: $(TARGET)
 
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<
 
run: $(TARGET)
	./$(TARGET)
 
clean:
	rm -f $(TARGET)
 
.PHONY: all run clean