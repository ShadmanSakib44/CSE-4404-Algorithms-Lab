#include <iostream>
#include <vector>
using namespace std;

int rowNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int colNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool isValid(int row, int col) {
    return row >= 0 && row < 5 && col >= 0 && col < 8;
}

void DFS(vector<vector<int>>& grid, int row, int col) {
    grid[row][col] = 1;

    for (int i = 0; i < 8; i++) {
        int newRow = row + rowNbr[i];
        int newCol = col + colNbr[i];

        if (isValid(newRow, newCol) && grid[newRow][newCol] == 0) {
            DFS(grid, newRow, newCol);
        }
    }
}

int countIslands(vector<vector<int>>& grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) {
                count++;
                DFS(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid(5, vector<int>(8));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }

    int islandCount = countIslands(grid);

    cout << islandCount << endl;

    return 0;
}
