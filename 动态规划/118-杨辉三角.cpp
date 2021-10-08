#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> line(i + 1);
            line[0] = 1;
            line[i] = 1;
            for (int j = 1; j < i; j++) {
                line[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.emplace_back(line);
        }
        return ans;
    }
};