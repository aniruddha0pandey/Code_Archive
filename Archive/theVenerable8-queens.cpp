// https://www.codesdope.com/blog/article/backtracking-explanation-and-n-queens-problem/
// https://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/
// file:///H:/Programming/PDF/H19-RecBacktrackExamples.pdf

#include <iostream>
#define COLUMN N

inline bool allQueenPlaced(int N) { return (N == 0); }

inline bool horizontalClear() {

}

inline bool diagonalsClear() {

}

bool blitz() {
	return !(horizontalClear() && diagonalsClear());
}

void place() {

}

void remove() {
	
}

bool nQueen(int N) {
	int board[N][N] = {};

	if ( allQueenPlaced(N) )
		return true;

	for (int i = 0; i < COLUMN; i++) {
		
	}

	return false;
}

void print(int *board, int N) {
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++)
			std::cout << *((board + row * N) + col) << " ";
		puts("");
	}
}

int main(void) {
	int N;
	std::cin >> N;
	if ( nQueen(N) )
		print((int *)board, N);
		std::cout << "\nProgram Stops Exploring on Solution...";
	else
		std::cout << "Solution Doesn't Exist...";	
	return 0;
}