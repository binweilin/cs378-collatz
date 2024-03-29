// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <map>
#include "Collatz.h"

//std::map<int, int> cache;
int cache[1000000] = {0};

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i;
    r >> i;
    if (!r)
        return std::make_pair(0, 0);
    int j;
    r >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    int max = 0;

    if(i > j){
        int temp = i;
        i = j;
        j = temp;
    }

    if(i < j /2)
        i = j/2;

    for(int k = i; k <= j; k++){       
        int length = 1;
        int n = k;
        // if(cache.count(k) != 0)
        //     length = cache[k];

        if(cache[k] != 0)
            length = cache[k];
        else{
            while(n != 1){
                if(n%2 == 0){
                    n /= 2;
                    length++;
                }
                else{
                    n = (3*n + 1)/2;
                    length+=2;
                }
                // if(cache.count(n) != 0){
                //     length += cache[n] - 1;
                //     n = 1;
                // }
                if(n < 1000000 && cache[n] != 0){
                    length += cache[n] - 1;
                    n = 1;
                }
            }
            cache[k] = length;
        }

        if(length > max)
            max = length;
    }
    return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int v = collatz_eval(p.first, p.second);
        collatz_print(w, p.first, p.second, v);}}
