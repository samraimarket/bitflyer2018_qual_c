#include <iostream>
#include <algorithm>
using namespace std;
uint64_t* X;
uint64_t* Y;
size_t N, D;

inline 
void inputRangeData(size_t const i) {
    
    Y[i] = 0;
    if (0 == i) return;

    for (size_t j =  i - 1; (X[i] - X[j]) <= D; j--) {
        Y[i]++;
        if (j == 0) break;
    }
    cout << i << ',' << Y[i] << endl;
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
        for (size_t j = k - 1; 1 <= j ; j--) {
            if ((X[k] - X[j]) > D) break;
            size_t i_min = j - Y[j];

            if ((X[k] - X[i_min]) <= D) continue;
            size_t i_max = min<uint64_t>(j - 1, k - Y[k] - 1);
            if (i_min <= i_max) {
                ret += i_max - i_min + 1;
            }

        }
    }
    cout << ret << endl;
    return 0;
}
