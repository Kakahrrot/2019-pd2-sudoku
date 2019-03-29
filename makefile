test: test.o sudoku.o
	g++ -o test test.o sudoku.o
test.o: test.cpp sudoku.h
	g++ -c test.cpp
transform: transform.o sudoku.o
	g++ -o transform transform.o sudoku.o
transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp
generate: generate.o sudoku.o
	g++ -o generate generate.o sudoku.o
generate.o: generate.cpp sudoku.h
	g++ -c generate.cpp
sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp
