/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int count = 0,dx[4] = {0, 1, 0, -1},dy[4] = {1, 0, -1, 0}, step = 0, i = 0, j = 0;
        while(count < n * n) {
            matrix[i][j] = ++count;
            int x = i + dx[step], y = j + dy[step];
            if(!check_ok(n, x, y) || matrix[x][y] != 0) {
                step = (step + 1) % 4;
            }
            i += dx[step];
            j += dy[step];
        }

        return matrix;
    }

    bool check_ok(int n,int x,int y) {
        if(x < 0 || y < 0 || x >= n || y >=n) return 0;
        return 1;
    }
};
// @lc code=end

