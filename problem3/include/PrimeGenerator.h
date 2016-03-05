#ifndef PRIME_GENERATOR_SIEVE
#define PRIME_GENERATOR_SIEVE

#include <vector>
#include <algorithm>
template<class T>
class PrimeGenerator {
    T max;
    std::vector<T> sieveOfEratosthenes;
    void seive(typename std::vector<T>::iterator it) {
        for(T i : sieveOfEratosthenes) {
                sieveOfEratosthenes.erase(std::remove_if(it, sieveOfEratosthenes.end(), [i](T t) { return t % i == 0; }), sieveOfEratosthenes.end());
                it++;
        }
    }
public: 
    PrimeGenerator(T max = 2) : max(2), sieveOfEratosthenes(1, 2) {
        increaseMax(max);
    }
    const std::vector<T>& getPrimes() const {
        return sieveOfEratosthenes;
    }
    void increaseMax(T newMax) {
        if(newMax <= max) {
            return;
        }
        sieveOfEratosthenes.reserve(newMax-max+sieveOfEratosthenes.size());
        typename std::vector<T>::iterator it = sieveOfEratosthenes.end();
        for(T i = max + 1; i <= newMax; i++) {
            sieveOfEratosthenes.push_back(i);
        }
        seive(it);
        max = newMax;
    }
};

#endif