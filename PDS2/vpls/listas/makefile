vpl_execution: build/list.o build/main.o
	g++ build/list.o build/main.o -o vpl_execution

build/list.o: src/list.cpp include/node.hpp include/list.hpp
	g++ -c src/list.cpp -Iinclude -o build/list.o

build/main.o: src/main.cpp include/node.hpp include/list.hpp
	g++ -c src/main.cpp -Iinclude -o build/main.o

	INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

$(BUILD_DIR)/list.o: $(SRC_DIR)/list.cpp $(INCLUDE_DIR)/node.hpp $(INCLUDE_DIR)/list.hpp
	g++ -c $(SRC_DIR)/list.cpp -I$(INCLUDE_DIR) -o $(BUILD_DIR)/list.o
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/node.hpp $(INCLUDE_DIR)/list.hpp
	g++ -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(BUILD_DIR)/main.o
vpl_execution: $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o
	g++ $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o -o vpl_execution

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

$(BUILD_DIR)/list.o: $(SRC_DIR)/list.cpp $(INCLUDE_DIR)/node.hpp $(INCLUDE_DIR)/list.hpp
	g++ -c $(SRC_DIR)/list.cpp -I$(INCLUDE_DIR) -o $(BUILD_DIR)/list.o
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/node.hpp $(INCLUDE_DIR)/list.hpp
	g++ -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(BUILD_DIR)/main.o
vpl_execution: $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o
	g++ $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o -o vpl_execution	