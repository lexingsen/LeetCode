#include <iostream>
#include <algorithm>
using namespace std;

void selectSort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = 1 + i; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            swap(a[i], a[minIndex]);
        }
    }
}

int main() {
    int a[] = {1, 3, 4, 2,5};
    int n = sizeof(a) / sizeof(int);
    selectSort(a, n);
    for_each(a, a + n, [] (int x) {cout << x << " ";});
    cout << endl;
    return 0;
}