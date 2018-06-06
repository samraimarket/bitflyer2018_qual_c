#include <iostream>
#include <algorithm>
using namespace std;
uint64_t *X, *Y;
size_t N, D;

inline 
void inputRangeData(size_t const i) {
    
    Y[i] = 0;
    if (0 == i) return;

    for (size_t j =  i - 1; (X[i] - X[j]) <= D; j--) {
        Y[i]++;
        if (j == 0) break;
    }
}

inline find(size_t min, size_t mid, size_t max, size_t end) {

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
    return find(start, (start + end) / 2, end, end);

}

int main() {
 
    cin >> N >> D;
 
    uint64_t array[N];
    X = array;
    
    uint64_t array2[N];
    Y = array2;

    for (size_t i = 0; i < N; i++) {
         cin >> X[i];
         inputRangeData(i);
    }

    size_t ret = 0;
    for (size_t k = N - 1; 2 <= k; k--) {
        for (size_t j = startFind(k - Y[k], k); j < k; j++) {
            size_t const i_min = j - Y[j];
            size_t const i_max = startFind(i_min, k);
            if (i_max == 0) continue;
            if ((X[k] - X[i_max - 1]) <= D) continue;
            ret += i_max - i_min;

        }
    }
    cout << ret << endl;
    return 0;
}
