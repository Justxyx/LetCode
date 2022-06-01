#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // 纵
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = -1;
                    break;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0)
                obstacleGrid[i][0] = 1;
            else
                break;
        }
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 0)
                obstacleGrid[0][i] = 1;
            else
                break;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == -1)
                    break;
                else if (obstacleGrid[i-1][j] == -1){
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                } else if (obstacleGrid[i][j-1] == -1){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                } else{
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        for (const auto &item : obstacleGrid){
            for (const auto &i : item){
                cout << i << "," ;
            }
            cout << endl;
        }
        return obstacleGrid.back().back();
    }
};


int main() {
    int i = 3;
    if (i >1){
        cout << " i > 3";
    } else if (i > 2 ){
        cout << "i > 2";
    } else{
        cout << "else";
    }
    return 0;
}

