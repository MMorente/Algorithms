// Test.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <queue>
#include <map>
#include <vector>

namespace Algos {
	class ShortestPath {
	public:
		ShortestPath(const std::vector<std::vector<int>>& m);
		bool is_valid(int row, int col);
		int solve();

	private:
		std::vector<std::vector<int>> matrix;
		std::queue<std::pair<std::pair<int, int>, int>> q;
		const int rows;
		const int cols;
		int rowNum[4] = { -1, 0, 0, 1 };
		int colNum[4] = { 0, -1, 1, 0 };

	};
}