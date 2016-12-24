#include <iostream>
#include <algorithm>

/**
  * In a 20 by 20 grid, how many paths are there from top left to bottom right
  * are there if you can only go right or down
  * Solution uses choose algorithm. For n*n grid solution is choose(2n, n), discoverd by hand
  */

/**
 * Calculates n choose r. n!/((n-r)!*r!)
 * The (n-r)! cancels out some of the top so we get
 * n * (n-1) * (n-2) * ... * (n-r+1) / i!
 * We can divide by i safely and get an integer each time as
 * at least one of i consecutive natural numbers is
 * always divisible by i
 * This was done to avoid overflow when calculating 40!
 */
long long choose(long long n, long long r) {
    long long choose = 1;
    for(int i = 1; i <= r; i++) {
        choose = (choose * (n - i + 1)) / i;
    }
    return choose;
}

long long countPaths(long long dimension) {
    return choose(dimension*2,dimension);
}

int main() {
    int dimension = 20;
    std::cout << countPaths(dimension) << std::endl;
}

