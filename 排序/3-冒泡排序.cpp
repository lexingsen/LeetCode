#include <iostream>
#include <algorithm>
using namespace std;


void BubbleSort(int *a, int n) {
    bool flag = false;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        flag = false;
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

int main() {
    int a[] = {1, 3, 4, 2,5};
    int n = sizeof(a) / sizeof(int);
    BubbleSort(a, n);
    for_each(a, a + n, [] (int x) {cout << x << " ";});
    cout << endl;
    return 0;
}