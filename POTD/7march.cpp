#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:    
    void SieveOfEranthoses(vector<bool>& isPrime) {
        for (int i = 2; i*i <= isPrime.size(); i++) {
            if (isPrime[i]) {
                for (int j = i*i; j <= isPrime.size(); j+=i) {
                    isPrime[j] = false;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        SieveOfEranthoses(isPrime);

        vector<int> prime;

        for (int i = left; i <= right; i++) {
            if (isPrime[i]) prime.push_back(i);
        }

        int minimum = INT_MAX;
        int num1 = -1, num2 = -1;

        for (int i = 1; i < prime.size(); i++) {
            if (minimum > prime[i] - prime[i - 1]) {
                minimum = prime[i] - prime[i-1];
                num1 = prime[i-1];
                num2 = prime[i];
            }
        }

        return {num1,num2};
    }
};

int main()
{
    int left = 10, right = 19;
    Solution sol;
    vector<int> result = sol.closestPrimes(left, right);
    cout << "Closest Primes: " << result[0] << " " << result[1];
    return 0;
}