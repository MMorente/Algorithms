#include "ShortestPath.h"


int main(int argc, char* argv[]) {
	std::vector<std::vector<int>> test{ {1,1,1,1,1},{0,1,1,1,0},{1,1,0,1,1},{1,1,1,1,9} };

	Algos::ShortestPath solver(test);
	int solution = solver.solve();

	std::cout << "The shortest path for the given 2D matrix is " << solution << " jumps.\n";
}