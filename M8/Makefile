CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
LDLIBS   := -lncurses

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := complexlab

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDLIBS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
