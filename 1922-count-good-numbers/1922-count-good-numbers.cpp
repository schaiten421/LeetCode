class Solution {
public:
    long long powerMOD(int a, long long b, int mod) {
        if(b == 0)
            return 1;
        long long x = powerMOD(a, b/2, mod);
        if(b % 2 == 0)
            return (x * x) % mod;
        else
            return ((a * x)* x) % mod;
    }
    long long countGoodNumbers(long long n) {
        int mod=1e9+7;
        return (powerMOD(5,(n+1)/2,mod)*powerMOD(4,n/2,mod))%mod;
    }
};