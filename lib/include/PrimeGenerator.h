#ifndef PRIME_GENERATOR_SIEVE
#define PRIME_GENERATOR_SIEVE

#include <vector>
#include <algorithm>
/**
  * Generates primes using the sieveOfEratosthenes
  * use setMax to set the maximum prime number in the list
  * getPrimes returns a vector of prime numbers from 2 to max inclusive
  */
template<class T>
class PrimeGenerator {
    T max;
    std::vector<T> sieveOfEratosthenes;
    void seive(typename std::vector<T>::iterator it) {
        for(T i : sieveOfEratosthenes) {
                sieveOfEratosthenes.erase(
                        std::remove_if(it, sieveOfEratosthenes.end(), [i](T t) { return t % i == 0; }),
                        sieveOfEratosthenes.end());
                // If all extra elements have been removed due to not being prime, we are done.
                if(it == sieveOfEratosthenes.end()) {
                    return;
                }
                while(i*i > *it) {
                    //*it is prime, no need to test further
                    it++;
                    if(it == sieveOfEratosthenes.end()) {
                        return;
                    }
                }
        }
    }
public:
    PrimeGenerator(T max = 2) : max(2), sieveOfEratosthenes(1, 2) {
        // We need the first prime in the sieve before increasing the maximum
        setMax(max);
    }
    const std::vector<T>& getPrimes() const {
        return sieveOfEratosthenes;
    }
    void setMax(T newMax) {
        if(newMax <= max) {
            return;
        }
        sieveOfEratosthenes.reserve(static_cast<long long>(newMax-max+sieveOfEratosthenes.size()));
        /**
          * Reserve call above ensures the push_back below does not cause the sieve to resize - i.e. move
          * the data so that the iterator below is not invalidated
          */
        typename std::vector<T>::iterator it = sieveOfEratosthenes.end();
        for(T i = max + 1; i <= newMax; i++) {
            sieveOfEratosthenes.push_back(i);
        }
        seive(it);
        max = newMax;
    }
    T getMax() const {
        return max;
    }
};

#endif
