CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = proj1.x

SRCS = proj1.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) $(OBJS)
.PHONY: all clean
