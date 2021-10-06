/**
* 2021. 10. 06
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

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string f[101][101];

string m_bignum_plus(string n1, string n2) {
    int sum=0;
    string result;
    
    while(!n1.empty() || !n2.empty() || sum) {
        if(!n1.empty()) {
            sum+=n1.back()-'0';
            n1.pop_back();
        }
        
        if(!n2.empty()) {
            sum+=n2.back()-'0';
            n2.pop_back();
        }
        
        result.push_back((sum%10)+'0');
        sum/=10;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string m_combination(int n, int r) {
    if(n==r || r==0)
        return "1";
    
    string &result=f[n][r];
    
    if(result!="")
        return result;
    
    result=m_bignum_plus(m_combination(n-1,r-1), m_combination(n-1,r));
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    
    cin>>n>>m;
    
    cout<<m_combination(n,m)<<"\n";
    
	return 0;
}