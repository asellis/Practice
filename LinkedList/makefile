main: LinkedList.hpp tests.cpp main.cpp
	g++ LinkedList.hpp tests.cpp main.cpp -o main.out -std=c++11

run:
	./main.out

val:
	valgrind ./main.out

clean:
	rm main.out