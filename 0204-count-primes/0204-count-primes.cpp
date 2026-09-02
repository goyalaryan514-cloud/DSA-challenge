class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 1; // just "2"

        int count = 1; // count the prime 2

        // largest odd number strictly less than n
        int lastOdd = (n % 2 == 0) ? (n - 1) : (n - 2);
        if (lastOdd < 3) return count; // no odd candidates below n

        int size = (lastOdd - 3) / 2 + 1; // isPrime[i] represents the odd number (2*i + 3)
        vector<char> isPrime(size, 1);

        for (int i = 0; i < size; i++) {
            long long num = 2LL * i + 3;
            if (num * num >= n) break;
            if (isPrime[i]) {
                for (long long j = num * num; j < n; j += 2 * num) {
                    isPrime[(j - 3) / 2] = 0;
                }
            }
        }

        for (int i = 0; i < size; i++)
            if (isPrime[i]) count++;

        return count;
    }
};