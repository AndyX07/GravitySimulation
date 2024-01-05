CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++17 -march=native -O2
SDL_LIBS := -lSDL2

TARGET := simulation

SRC := main.cpp Planet.cpp Simulate.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(SDL_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(SDL_LIBS)

clean:
	rm -f $(TARGET) $(OBJ)
