#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

bool checkPrime(int a){
	if(a==0 || a==1){
		return  false;
	}
	for(int i=2; i<a; i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
vi generatePrimes(int start, int amount){
	int a=start, count=0;
	vi primes;
	while(count<amount){
		if(checkPrime(a)){
			primes.push_back(a);
			count++;
		}
		a++;
	}
	return primes;
}
int main() {
	for(int i=0; i<5; i++){
		int a;
		cin>>a;
		vi primes=generatePrimes(0, a);
		int p=1;
		for(vi::iterator itr=primes.begin(); itr!=primes.end(); itr++){
			p*= *itr;
		}
		vi qprimes=generatePrimes(p+2, 1);
		int q=qprimes.front();
		cout<<q-p<<endl;
	}
	for(int j=0; j<5; j++){
		int b;
		cin>>b;
		vi bprimes=generatePrimes(0, b);
		int bp=1;
		for(vi::iterator it=bprimes.begin(); it!=bprimes.end(); it++){
			bp*=*it;
		}
		int qb;
		for(int k=bp-2; k>=2; k--){
			if(checkPrime(k)){
				qb=k;
				break;
			}
		}
		cout<<bp-qb<<endl;
	}
}
