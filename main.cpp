#include <iostream>
#include <algorithm>
using namespace std;
uint64_t *X, *Y;
size_t N, D;

inline 
void inputRangeData(size_t const i, size_t& min) {
    
    if (0 == i) return;

    for (size_t j =  min; j < i; j++) {
        if ((X[i] - X[j]) > D) min = j;
        else Y[j]++;
    }
}


int main() {
 
    cin >> N >> D;
 
    uint64_t array[N];
    X = array;
    
    uint64_t array2[N] = {0}; 
    Y = array2;

    size_t minimum = 0;
    for (size_t i = 0; i < N; i++) {
         cin >> X[i];
         inputRangeData(i, minimum);
    }

    size_t ret = 0;
    for (size_t i = 0; i < N - 2; i++) {
        if (N <= (i + Y[i] + 1)) break;
        if (Y[i] == 0) continue;        

        size_t const j_min = i + 1;
        size_t const j_max = min<size_t>(N - 2, i + Y[i]);
        if (Y[j_max] == 0) continue;        

        size_t const k_max = j_max + Y[j_max];
        size_t const k_min = j_max + 1;
        if (k_max < k_min) break;

        for (size_t j = j_min; j <= j_max; j++) {
            ret += (j + Y[j]) - j_max;
        }
    }
    cout << ret << endl;
    return 0;
}
