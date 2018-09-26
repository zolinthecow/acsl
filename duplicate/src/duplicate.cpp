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

int main() {
	unsigned int a;
	cin>>a;
	string bob;
	getline(cin, bob);
	vector<char> thing;
	char previousChar;
	int answer=0;
	for(unsigned int i=0; i<bob.length(); i++){
		if(bob.at(i)!=' '){
			char blob=toupper(bob.at(i));
			thing.push_back(blob);
			sort(thing.begin(), thing.end());
			if(i>=a){
				if(thing[a-1]!=previousChar){
					answer++;
				}
			}
			previousChar=thing[a-1];
		}
	}
	cout<<answer;
}
