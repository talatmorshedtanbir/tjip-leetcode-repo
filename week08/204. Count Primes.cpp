// https://leetcode.com/problems/count-primes/
// Time Complexity: O(N*log(log(N)))
// Space Complexity: O(N)

class Solution {
public:
    int SieveOfEratosthenes(int n) {
        int totalPrimes = 0;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p*p < n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        for (int p = 2; p < n; p++)
            if (prime[p])
                totalPrimes++;
    
        return totalPrimes;
    }
 
    int countPrimes(int n) {
        return SieveOfEratosthenes(n);
    }
};