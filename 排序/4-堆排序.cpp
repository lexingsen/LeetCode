

void shiftDown(int i) {
    while (2 * i <= cnt) {
        int j = 2 * i;
        if (j + 1 <= cnt && data[j + 1] < data[j]) {
            j++;
        }
        if (data[i] <= data[j]) {
            break;
        }
        swap(data[i], data[j]);
        i = j;  
    }
}