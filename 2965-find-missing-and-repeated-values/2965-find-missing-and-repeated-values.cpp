class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
    long long n = a.size(); 

    long long nn=n*n;
    long long SN = (nn * (nn + 1)) / 2;
    long long S2N = (nn * (nn + 1) * (2 * nn + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            S += a[i][j];
            S2 += (long long)a[i][j] * (long long)a[i][j];
        }
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
    }
};