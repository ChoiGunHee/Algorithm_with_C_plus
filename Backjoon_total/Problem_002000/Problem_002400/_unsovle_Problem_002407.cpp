/**
* 2021. 09. 11
* Creater : Gunhee Choi
* Problem Number : 2407
* Title : 조합

* Problem :
nCm을 출력한다.

* Input :
n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)

    100 6

* Output :
nCm을 출력한다.

    1192052400

**/

//String으로 연산해야함.

#include <iostream>
#define VAL_MOD 1000000007LL

using namespace std;

long long mul(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y%2 != 0) {
            result *= x;
        }
        x *= x;
        y/=2;
    }
    return result;
}

int main(void) {
	long long N, K;
	long long result=1;
	long long tmp1=1;
	long long tmp2=1;
	long long tmp3;
	long long i, j;
	
	scanf("%lld %lld", &N, &K);
	
	for(long long i=1; i<=N; i++) {
		tmp1*=i;
	}
	
	for(long long i=1; i<=K; i++) {
		tmp2*=i;
	}
	
	for(long long i=1; i<=(N-K); i++) {
		tmp2*=i;
	}
	
	tmp3=mul(tmp2,VAL_MOD-2);
	
	result=tmp1*tmp3;
	
	printf("%lld\n", result);
    
	return 0;	
}