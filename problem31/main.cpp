#include <iostream>
#include <vector>

std::vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200};

/** Calculated the numer of ways to make £2 using coins
  * Uses a recursive algorithm to calculate by calculating the remaining ammount of 
  * combinations left after selecting a coin. We start with the highest coin fo fine
  * the most efficient combination first. The iterator is used to set the largest 
  * coin that can be used to avoid couting different permutations of the same combination.
  */
int countCombinationsOfCoinsToMakeXPounds(int x, std::vector<int>::reverse_iterator it = coins.rbegin()) {
    if(x == 0) {
        return 1;
    }
    int count = 0;
    for(; it != coins.rend(); it++) {
        if (x - *it >= 0) {
            count += countCombinationsOfCoinsToMakeXPounds(x - *it, it);
        }
    }
    return count;
}


int main() {
    std::cout << countCombinationsOfCoinsToMakeXPounds(200) << std::endl;
    return 0;
}

