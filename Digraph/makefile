graph: Digraph.hpp
	g++ Digraph.hpp tests.cpp main.cpp -o main.out -std=c++11

run: main.out
	./main.out

clean:
	rm main.out

auto:
	g++ Digraph.hpp tests.cpp main.cpp -o main.out -std=c++11
	./main.out
	rm main.out

val:
	g++ Digraph.hpp tests.cpp main.cpp -o main.out -std=c++11
	valgrind ./main.out
	rm main.out