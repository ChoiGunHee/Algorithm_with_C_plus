/**
* 2021. 09. 23
* Creater : Gunhee Choi
* Problem Number : 15439
* Title : Vera and Outfits

* Problem :
Vera owns N tops and N pants. The i-th top and i-th pants have colour i, for 1 ≤ i ≤ N, where all N colours are different from each other.

An outfit consists of one top and one pants. Vera likes outfits where the top and pants are not the same colour.

How many different outfits does she like?

* Input :
The input will be in the format:

    N
Constraints:

1 ≤ N ≤ 2017
N is integer

	5

* Output :
Output one line with the number of different outfits Vera likes.

	20
    
**/

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
    
    cin>>N;
    cout<<N*(N-1)<<"\n";
    
	return 0;	
}