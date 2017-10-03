#include <vector>
#include <unordered_set>

using namespace std;


//https://stackoverflow.com/questions/15160889/how-to-make-unordered-set-of-pairs-of-integers-in-c
struct pair_hash {
	inline std::size_t operator()(const std::pair<int, int> & v) const {
		return v.first * 31 + v.second;
	}
};

// Solution
class wordSearch {
public:
	bool exist(vector<vector<char>>& board, string word) {
		ans = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					unordered_set<pair<int, int>, pair_hash> visited;
					dfs(board, word, 0, i, j, visited);
					if (ans)
						return ans;
				}
			}
		}

		return ans;
	};

private:
	void dfs(vector<vector<char>>& board, string word, int pos, int row, int col, unordered_set<pair<int, int>, pair_hash>& visited) {

		// base case here
		if (pos == word.size() - 1 && !hasVisited(visited, row, col) && board[row][col] == word[word.size() - 1]) {
			ans = true;
			return;
		}

		visited.insert(pair<int, int>(row, col));

		// Look left & see if it's == word[pos + 1]
		int left = (col + 1 >= board[row].size()) ? -1 : col + 1;									// make sure it wraps around
		if (left != -1 && board[row][left] == word[pos + 1] && !hasVisited(visited, row, left) && !ans)
			dfs(board, word, pos + 1, row, left, visited);


		// Look down & see if it's == word[pos + 1]
		int down = (row + 1 >= board.size()) ? -1 : row + 1;
		if (down != -1 && board[down][col] == word[pos + 1] && !hasVisited(visited, down, col) && !ans)
			dfs(board, word, pos + 1, down, col, visited);


		// Look right & see if it's == word[pos + 1]
		int right = (col - 1 < 0) ? -1 : col - 1;
		if (right != -1 && board[row][right] == word[pos + 1] && !hasVisited(visited, row, right) && !ans)
			dfs(board, word, pos + 1, row, right, visited);


		// Look up & see if it's == word[pos + 1]
		int up = (row - 1 < 0) ? -1 : row - 1;
		if (up != -1 && board[up][col] == word[pos + 1] && !hasVisited(visited, up, col) && !ans)
			dfs(board, word, pos + 1, up, col, visited);


		// If we're here, then either ans == true (thus it doesn't matter whats in visited), or we're returning from a failed 
		//  attempt at going somewhere. If the latter is the case then visited contains an incorrect point, so we need to remove it
		unordered_set<pair<int, int>, pair_hash>::iterator it = visited.find(pair<int, int>(row, col));
		if (it != visited.end())
			visited.erase(it);
	};

	// to make dfs(...) more readable
	inline bool hasVisited(unordered_set<pair<int, int>, pair_hash>& visited, int row, int col) {
		if (visited.find(pair<int, int>(row, col)) == visited.end())
			return false;
		return true;
	};

	bool ans;
};