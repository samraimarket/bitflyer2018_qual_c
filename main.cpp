#include <iostream>
using namespace std;
uint64_t* X;
size_t N, D;

inline
size_t find(size_t min, size_t mid, size_t max, size_t const end) {

    if (mid == max || min == mid) return mid;

    uint64_t last_p = X[end - 1];
    if ((last_p - X[mid]) <= D) {

        // check next one
        if ((last_p - X[mid + 1]) > D) return mid;
        
        max = mid;
        mid = (min + mid) / 2;
    } else {
        // Go to far
        min = mid;
        mid = (mid + max) / 2;
    }
    return find(min, mid, max, end);
}

inline
size_t startFind(size_t start, size_t end) {
    if ((X[end] - X[end - 1]) > D) return end;
    size_t ret = find(start, (start + end) / 2, end - 1, end);
    return ret;
}
int main() {
 
    cin >> N >> D;
 
    uint64_t array[N];
    X = array;
 
    for (size_t i = 0; i < N; i++) cin >> X[i];
 
    size_t ret = 0;
    for (size_t k = 2; k < N; k++) {
        size_t j = startFind(1, k);
        if (j == k) continue;

        size_t i = startFind(0, j);
        if (j == i) continue;

        ret += (k - j) * (j - i);
    }
    cout << ret << endl;
    return 0;
}
