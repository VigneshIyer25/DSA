/*
Given two numbers a and b, we need to find the GCD of them. Largest number which divides both a and b.
When one of the numbers is 0, the answer is the other number. Using brute force, we can find the GCD in O(min(a,b)).
and a space complexity of O(min(a,b)).
Using Dynamic programming we can manage to bring down the SC to O(1).
However to make the algorithm faster, we use Eucledian's theorem.

Originally, it is based on: subtracting the smaller number from the larger until one of the numbers is zero. Once we reach this point,
we can retrun the larger number. 
For a to be less than b, we need to subtract it atleast a/b times.
For eg. (11, 5) ==> 11-(11/5)(5) ==> 11-2*5 ==> 11%5.

This makes the computation even faster.
TC = O(log(min(a,b)))
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// brute force
int gcd(int a, int b){
    int smaller = min(a,b);
    while(smaller > 0){
        if(a%smaller == 0 && b%smaller == 0) break;
        smaller--;
    }
    return smaller;
}

// Recursive function to return gcd of a and b
int gcd2(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

//Using Dynamic Programming
int static dp[1001][1001];

int gcd3(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    // base case
    if (a == b)
        return a;
     
    // if a value is already
    // present in dp
    if(dp[a][b] != -1)
        return dp[a][b];
 
    // a is greater
    if (a > b)
        dp[a][b] = gcd(a-b, b);
     
    // b is greater
    else
        dp[a][b] = gcd(a, b-a);
     
    // return dp
    return dp[a][b];
}

//Using eucleadians algo
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

//using ternary operator
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
