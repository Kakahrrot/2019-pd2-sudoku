#test: test.o sudoku.o
#	g++ -o test test.o sudoku.o
#test.o: test.cpp sudoku.h
#	g++ -c test.cpp
all: solve generate transform
solve: solve.o sudoku.o 
	g++ -o solve solve.o sudoku.o Clock.o
solve.o: solve.cpp sudoku.h Clock.h
	g++ -c solve.cpp
transform: transform.o sudoku.o Clock.o
	g++ -o transform transform.o sudoku.o Clock.o
transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp
generate: generate.o sudoku.o Clock.o
	g++ -o generate generate.o sudoku.o Clock.o
generate.o: generate.cpp sudoku.h
	g++ -c generate.cpp
sudoku.o: sudoku.cpp sudoku.h Clock.o
	g++ -c sudoku.cpp
Clock.o: Clock.cpp Clock.h
	g++ -c Clock.cpp
