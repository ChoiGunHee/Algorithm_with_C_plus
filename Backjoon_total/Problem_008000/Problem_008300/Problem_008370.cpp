/**
* 2021. 09. 10
* Creater : Gunhee Choi
* Problem Number : 8370
* Title : Plane

* Problem :
Byteland Airlines recently extended their aircraft fleet with a new model of a plane. The new acquisition has n1 rows of seats in the business class and n2 rows in the economic class. In the business class each row contains k1 seats, while each row in the economic class has k2 seats.

Write a program which:

reads information about available seats in the plane,
calculates the sum of all seats available in that plane,
writes the result.

* Input :
In the first and only line of the standard input there are four integers n1, k1, n2 and k2 (1 ≤ n1, k1, n2, k2 ≤ 1 000), separated by single spaces.

    2 5 3 20

* Output :
The first and only line of the standard output should contain one integer - the total number of seats available in the plane.

    70

**/

#include <iostream>
using namespace std;

int main() {
    int n1, k1, n2, k2;
    cin>>n1>>k1>>n2>>k2;
    cout<<n1*k1+n2*k2<<endl;
	return 0;
}