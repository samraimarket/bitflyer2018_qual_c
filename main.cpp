#include <iostream>
using namespace std;
 
int main() {
 
    size_t N, D;
    cin >> N >> D;
 
    uint64_t X[N];
 
    for (size_t i = 0; i < N; i++) cin >> X[i];
 
    size_t ret = 0;
    for (size_t k = 2; k < N; k++) {
        size_t M = (k - 1);
        for (size_t i = 0; i < M; i++) {
            if((X[k] - X[i]) <= D) break;
            for (size_t j = i; j < k; j++) {
                if ((X[j] - X[i]) > D) break;
                if ((X[k] - X[j]) <= D) ret++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
