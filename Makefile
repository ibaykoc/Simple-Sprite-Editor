CC = clang++
C_FLAGS = -Wall
SRC_PATH = src/
TARGET_PATH = bin/
INCLUDE_PATH = dependencies/include/
FRAMEWORK_PATH = dependencies/framework/
FRAMEWORKS = -framework sfml-system -framework sfml-graphics -framework sfml-window -framework sfml-audio
TARGET = test
APP_NAME = test

all: build_app

build_app: $(TARGET_PATH)Main.o
	$(CC) -o $(TARGET_PATH)$(TARGET) $(TARGET_PATH)Main.o -lsfml-graphics -lsfml-window -lsfml-system
	$(TARGET_PATH)$(TARGET)

$(TARGET_PATH)Main.o: $(SRC_PATH)Main.cpp
	$(CC) -c $(SRC_PATH)Main.cpp -o $(TARGET_PATH)Main.o


clean:
	rm -f $(TARGET_PATH)$(TARGET) $(TARGET_PATH)*.o
	rm -rf bin/$(APP_NAME).app/
