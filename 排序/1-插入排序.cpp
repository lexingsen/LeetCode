
void insertSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int j;
        int e = a[i];
        for (j = i; j >= 1 && a[j - 1] > e; --j) {
            a[j] = a[j - 1];
        }
        a[j] = e;
    }
    return ;
}
