CXX = g++
CXXFLAGS = -Iinclude -ISFML/include -std=c++17 -Wall -Wextra -DSFML_STATIC

LDFLAGS = -DSFML_STATIC -L SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lpthread -lopengl32 -lfreetype -lwinmm -lgdi32

SRC = src/main.cpp src/car.cpp src/map.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = needforfeed.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q src\\*.o $(TARGET)

.PHONY: all clean
