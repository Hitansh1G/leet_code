#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canConnectStrings(const string& str1, const string& str2) {
    return str1[1] == str2[0];
}

bool canConnectAllStrings(const vector<string>& A, int K) {
    if (K == 0) {
        return true;
    }

    for (int i = 1; i <= K; i++) {
        if (!canConnectStrings(A[i - 1], A[i])) {
            return false;
        }
    }

    return true;
}

string solution(const vector<string>& A, int N) {
    string result;
    for (int i = 0; i < N; i++) {
        if (canConnectAllStrings(A, i)) {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

int main() {
    vector<string> A = {"he", "T", "To", "ell"};
    int N = A.size();
    cout << solution(A, N) << endl; // Output: "1001"

    A = {"fab", "be", "bq"};
    N = A.size();
    cout << solution(A, N) << endl; // Output: "111"

    return 0;
}
