/**
* 2021. 09. 30
* Creater : Gunhee Choi
* Problem Number : 6749
* Title : Next in line

* Problem :
You know a family with three children. Their ages form an arithmetic sequence: the difference in ages between the middle child and youngest child is the same as the difference in ages between the oldest child and the middle child. For example, their ages could be 5, 10 and 15, since both adjacent pairs have a difference of 5 years.

Given the ages of the youngest and middle children, what is the age of the oldest child?

* Input :
The input consists of two integers, each on a separate line. The first line is the age Y of the youngest child (0 ≤ Y ≤ 50). The second line is the age M of the middle child (Y ≤ M ≤ 50).

    12
    15

* Output :
The output will be the age of the oldest child.

    18

**/

#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int y, m;
    cin >> y >> m;
    cout << m + m - y;
    
    return 0;
}