CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/animal.o ./obj/snake.o ./obj/monkey.o ./obj/jungle.o ./obj/main.o ./obj/final_unittest.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/animal.o: ./cpp/animal.cpp ./h/animal.h
	$(CXX) $(CXXFLAGS) ./cpp/animal.cpp -o ./obj/animal.o
./obj/monkey.o: ./cpp/monkey.cpp ./h/monkey.h
	$(CXX) $(CXXFLAGS) ./cpp/monkey.cpp -o ./obj/monkey.o
./obj/snake.o: ./cpp/snake.cpp ./h/snake.h
	$(CXX) $(CXXFLAGS) ./cpp/snake.cpp -o ./obj/snake.o
./obj/jungle.o: ./cpp/jungle.cpp ./h/jungle.h
	$(CXX) $(CXXFLAGS) ./cpp/jungle.cpp -o ./obj/jungle.o
./obj/final.o: ./cpp/final.cpp ./h/final.h
	$(CXX) $(CXXFLAGS) ./cpp/final.cpp -o ./obj/final.o
./obj/final_unittest.o: ./cpp/final_unittest.cpp
	$(CXX) $(CXXFLAGS) ./cpp/final_unittest.cpp -o ./obj/final_unittest.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)