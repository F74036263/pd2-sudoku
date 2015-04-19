all: Sudoku2.o solve.cpp give_question.cpp
	g++ -o solve Sudoku2.o solve.cpp
	g++ -o give_question Sudoku2.o give_question.cpp

Sudoku.o: Sudoku.h Sudoku.cpp
	g++ -c Sudoku.h Sudoku.cpp





