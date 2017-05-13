#include "PrimeGenerator.h"
#include <set>
#include <cmath>
#include <numeric>
#include <iostream>

/**
  * Generates right trunctable primes based on the previous set, by appending
  * digits to the rhs and checking if it is prime 
  * Each iteration will increase the maximum prime by 10
  * Assumes rightTrunctable Primes will have at least the 4 prime digits and will 
  * contain all right trunctable primes up to a power of 10 (maxPrime).
  */

void generateRightTrunctablePrimes(std::set<long long>& rightTrunctablePrimes, long long maxPrime) {
    // Adding a 2,4,5,6 or 8 at the rhs would make the number not prime
    std::vector<long long> rightTrunctableDigits{1,3,7,9};
    // Use a temporary copy so we do not loop over the newly generated numbers
    auto rtpsTmp = rightTrunctablePrimes;
    for(auto i : rightTrunctableDigits) {
        for(auto rtp : rtpsTmp) {
            // Do not add digits to numbers that have already processed
            if(rtp < maxPrime / 10) {
                continue;
            }
            // Add digit to the right
            auto nextRtp = rtp*10+i;
            if(PrimeGenerator<long long>::isPrime(nextRtp)) {
                rightTrunctablePrimes.insert(nextRtp);
            }
        }
    }
}
/**
  * Generates left trunctable primes based on the previous set, by appending
  * digits to the rhs and checking if it is prime 
  * Each iteration will increase the maximum prime by 10
  * Assumes leftTrunctable Primes will have at least the 4 prime digits and will 
  * contain all left trunctable primes up to a power of 10 (maxPrime).
  */
void generateLeftTrunctablePrimes(std::set<long long>& leftTrunctablePrimes, long long maxPrime) {
    std::vector<long long> leftTrunctableDigits{1,2,3,4,5,6,7,8,9};
    // Use a temporary copy so we do not loop over the newly generated numbers
    auto ltpsTmp = leftTrunctablePrimes;
    for(auto i : leftTrunctableDigits) {
        for(auto ltp : ltpsTmp) {
            // Do not add digits to numbers we have already processed
            if(ltp < maxPrime / 10) {
                continue;
            }
            // Add digit to the left
            auto nextLtp = ltp+i*(int)pow(10,1+std::floor(std::log10(ltp)));
            if(PrimeGenerator<long long>::isPrime(nextLtp)) {
                leftTrunctablePrimes.insert(nextLtp);
            }
        }
    }
}

/**
  * A left trunctable prime, is a prime that when you continually remove the left mostdigit, it remains prime
  * A right trunctable prime, is a prime that when you continually remove the right most digit, it remains prime
  * A truncatble prime is both left and right trunctable.
  * e.g. 313 : 13, 3
  * e.g. 313 : 31, 3
  * Calculate the sum of all trunctable primes. Numbers < 10 are not trunctable as they cannot be truncated.
  */

int main() {
    /** Numbers < 10 are not considered trunctable as they cannot be truncated
      * They are here to use as digits to generate further trunctable primes by appending digits
      */
    std::set<long long> trunctablePrimes { 2, 3, 5, 7};
    std::set<long long> leftTrunctablePrimes { 2, 3, 5, 7};
    std::set<long long> rightTrunctablePrimes { 2, 3, 5, 7};
    // We have generated all trunctable primes up to maxPrime
    long long maxPrime = 10;
    // The problem states there are 11 trunctable numbers. 15 includes those less than 10.
    while(trunctablePrimes.size() < 15) {
        generateRightTrunctablePrimes(rightTrunctablePrimes, maxPrime);
        generateLeftTrunctablePrimes(leftTrunctablePrimes, maxPrime);
        // Find the intersection of both to find the trunctable primes
        std::set_intersection(rightTrunctablePrimes.begin(), rightTrunctablePrimes.end(),
                                leftTrunctablePrimes.begin(), leftTrunctablePrimes.end(),
                                std::inserter(trunctablePrimes, trunctablePrimes.end()));
        // We have generated all trunctable primes up to maxPrime
        maxPrime*= 10;
    }
    // Sum the trunctable primes removing 17 for the sum of the single digit primes
    std::cout << std::accumulate(trunctablePrimes.begin(), trunctablePrimes.end(), 0) - 17 << std::endl;
    return 0;
}

