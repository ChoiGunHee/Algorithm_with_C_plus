/**
* 2021. 10. 14
* Creater : Gunhee Choi
* Problem Number : 3733
* Title : Shares

* Problem :
A group of N persons and the ACM Chief Judge share equally a number of S shares (not necessary all of them). Let x be the number of shares aquired by each person (x must be an integer). The problem is to compute the maximum value of x.

Write a program that reads pairs of integer numbers from an input text file. Each pair contains the values of 1 ≤ N ≤ 10000 and 1 ≤ S ≤ 109 in that order. The input data are separated freely by white spaces, are correct, and terminate with an end of file. For each pair of numbers the program computes the maximum value of x and prints that value on the standard output from the beginning of a line, as shown in the example below.

* Input :

    1 100
    2 7
    10 9
    10 10

* Output :

    50
    2
    0
    0

**/

#include <iostream>
using namespace std;

int N, S;

int main() {
    while(cin>>N>>S)
        cout<<(S/(N+1))<<"\n";

    return 0;
}