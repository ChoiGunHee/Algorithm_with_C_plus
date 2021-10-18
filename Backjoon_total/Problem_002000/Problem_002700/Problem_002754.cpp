/**
* 2021. 10. 14
* Creater : Gunhee Choi
* Problem Number : 2754
* Title : 학점계산

* Problem :
어떤 사람의 C언어 성적이 주어졌을 때, 평점은 몇 점인지 출력하는 프로그램을 작성하시오.

A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0

* Input :
첫째 줄에 C언어 성적이 주어진다. 성적은 문제에서 설명한 13가지 중 하나이다.

    A0

* Output :
첫째 줄에 C언어 평점을 출력한다.

    4.0

**/

#include <iostream>
#include <string>
using namespace std;

string score;
double result;

int main() {
    cin>>score;

    result += 4-(score[0]-65);
    if(score[1]=='+')
        result += 0.3;
    else if(score[1]=='-')
        result -= 0.3;
    
    if(score[0]=='F')
        result = 0.0;

    printf("%.1f\n", result);

    return 0;
}