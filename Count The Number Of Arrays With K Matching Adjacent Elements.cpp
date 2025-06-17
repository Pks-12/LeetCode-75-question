class Solution {
    const int MOD = 1e9 + 7;          // Large prime modulus for modulo operations to prevent overflow
    vector<long long> fact, invFact;  // Vectors to store factorials and modular inverses of factorials

    // Fast modular exponentiation (base^exp % MOD)
    // Uses binary exponentiation to efficiently compute power under modulo
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while(exp > 0) {
            if(exp & 1)                    // If current bit is set, multiply result by base
                result = (result * base) % MOD;
            base = (base * base) % MOD;    // Square the base
            exp >>= 1;                     // Shift exponent right by 1 bit
        }
        return result;
    }

    // Modular multiplicative inverse using Fermat's little theorem:
    // a^(MOD-2) mod MOD is the inverse of a (when MOD is prime)
    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    // Precompute factorials and inverse factorials for all numbers from 0 to maxN
    // This allows efficient calculation of nCr (binomial coefficients) under modulo
    void precomputeFactorials(int maxN) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);

        fact[0] = 1;
        for(int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i-1] * i) % MOD;   // factorial computation modulo MOD
        }

        invFact[maxN] = modInverse(fact[maxN]);  // inverse factorial of maxN using modular inverse
        for(int i = maxN - 1; i >= 0; i--) {
            // Using property: invFact[i] = invFact[i+1] * (i+1) mod MOD
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
        }
    }

    // Calculate nCr (binomial coefficient) modulo MOD
    // Using precomputed factorials and inverse factorials
    long long nCr(int n, int r) {
        if(r > n || r < 0) return 0;
        return (fact[n] * ((invFact[r] * invFact[n - r]) % MOD)) % MOD;
    }

public:
    // Main function to count number of good arrays
    // n = length of array
    // m = max value of elements (1 to m)
    // k = number of adjacent pairs that are equal
    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n);  // Prepare factorials and inverse factorials up to n

        // Formula:
        // Number of good arrays = m * nCr(n-1, k) * (m-1)^(n-1-k) mod MOD
        // Explanation:
        // - m choices for the first element
        // - Choose k positions (out of n-1) for equal adjacent pairs
        // - For other positions, choose different elements (m-1 choices each)
        
        long long res = m;
        res = (res * nCr(n - 1, k)) % MOD;                    // multiply by combination count
        res = (res * modPow(m - 1, n - 1 - k)) % MOD;         // multiply by power of (m-1)
        return (int)res;
    }
};
