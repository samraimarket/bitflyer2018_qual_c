#include <iostream>
#include <algorithm>
using namespace std;
uint64_t *X, *Y, *minMemo;
size_t N, D;

inline 
void inputRangeData(size_t const i) {
    
    Y[i] = 0;
    minMemo[i] = N;
    if (0 == i) return;

    for (size_t j =  i - 1; (X[i] - X[j]) <= D; j--) {
        Y[i]++;
        if (j == 0) break;
    }
}

inline
size_t find(size_t min, size_t mid, size_t max, size_t end) {
    if (minMemo[end] != N) return minMemo[end];

    if ((X[end] - X[mid]) > D) {
        min = mid;
        mid = (mid + max) / 2;
    } else {
        if (((X[end] - X[mid - 1]) > D) || (mid == min)) return mid;
        max = mid;
        mid = (mid + min) / 2 ;
    }
    
    return find(min, mid, max, end);    
}

inline
size_t  startFind(size_t start, size_t end) {

    if ((X[end] - X[end - 1]) > D) return end;
    
    if (minMemo[end] == N) minMemo[end] = find(start, (start + end) / 2, end, end);
    return minMemo[end];
}

int main() {
 
    cin >> N >> D;
 
    uint64_t array[N];
    X = array;
    
    uint64_t array2[N];
    Y = array2;

    uint64_t array3[N];
    minMemo = array3;

    for (size_t i = 0; i < N; i++) {
         cin >> X[i];
         inputRangeData(i);
    }

    size_t ret = 0;
    for (size_t k = 2; k < N; k++) {

        for (size_t j = startFind(k - Y[k], k); j < k; j++) {
            size_t i_min = j - Y[j];
            size_t const i_max = min<uint64_t>(k - Y[k], j);
            if (i_min >= i_max) break;
            i_min = find(i_min, (i_max + i_min) / 2, i_max, j);
            ret += i_max - i_min;
        }
    }
    cout << ret << endl;
    return 0;
}
