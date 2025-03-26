#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int islandPerimeter(const vector<vector<int>>& grid){
    int rows = grid.size();
    if(rows == 0) 
        return 0;
    int cols = grid[0].size();
    
    //visited
    vector<vector <bool>> visited(rows, vector<bool>(cols, false));
    
    //punct start
    int startR = -1; //rows
    int startC = -1; //columns
    
    for (int i = 0; i < rows && startR == -1; ++i) {
        for (int j = 0; j < cols && startR == -1; ++j) {
            if(grid[i][j]) {
                startR = i;
                startC = j;
            }
        }
    }
    if (startR == -1) 
        return 0;
    
    int perimeter = 0;
    
    //que bfs
    queue<pair<int, int>> q;
    q.push({startR, startC});
    visited[startR][startC] = true;
    
    //poruszanie sie gora0 prawo1 dol2 lewo3
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    //przeszukiwanie bfs
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        int i = cell.first; //rows
        int j = cell.second; //columns
        
        int cellPermiter = 0;
        
        //sprawdzenie permiter cell
        for(int k = 0; k < 4; k++)
        {
            int newRow = i + dx[k];
            int newCol = j + dy[k];
            
            //sasiad za burta
            if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
            {
                cellPermiter++;
            }
            //sasiad water
            else if(grid[newRow][newCol] == 0)
            {
                cellPermiter++;
            }
            //sasiad lad niedodany
            else if (!visited[newRow][newCol])
            {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
        perimeter += cellPermiter;
    }
    
    return perimeter;
}

int main() {
    int rows, cols;
    
    cin >> rows >> cols;
    
    //grid
    vector<vector<int>> grid(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int result = islandPerimeter(grid);

    cout << "Obwod wyspy (BFS): " << result << endl;
    return 0;
}
