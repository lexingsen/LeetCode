#include <queue>
#include <vector>
#include <iostream>
using namespace std;


int wpl(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x: nums) {
        pq.push(x);
    }

    int res = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        res += (a + b);
        pq.push(a + b);
    }
    return res;
}

int main() {
    vector<int> nums = {2, 3, 6, 9, 14, 15, 16, 17};
    int ans = wpl(nums);
    cout << "wpl : " << ans << endl;
    return 0;
}