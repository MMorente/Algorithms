#include "ShortestPath.h"

namespace Algos {
	ShortestPath::ShortestPath(const std::vector<std::vector<int>>& m) : matrix(m), rows(m.size()), cols(m[0].size()) {}

	bool ShortestPath::is_valid(int row, int col) {
		return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
	}

	int ShortestPath::solve() {
		//Visited cells vector
		std::vector<std::vector<int>> visited(rows, std::vector<int>(cols));
		//We always start from the top left, mark it as visited.
		visited[0][0] = 1;

		q.push({ {0, 0}, 0 });

		while (!q.empty()) {
			auto current_cell = q.front();
			auto position = current_cell.first;
			auto distance = current_cell.second;

			if (matrix[position.first][position.second] == 9) {
				return distance;
			}

			q.pop();

			for (int i = 0; i < 4; i++) {
				int row = position.first + rowNum[i];
				int col = position.second + colNum[i];

				if (is_valid(row, col) && matrix[row][col] && !visited[row][col]) {
					visited[row][col] = 1;
					q.push({ {row, col}, distance + 1 });
				}
			}
		}
		return -1;
	}
}