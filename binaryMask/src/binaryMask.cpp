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
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000;

string charToString(char a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s;
}

set<vi> solve(int on, string mask, int oneCount, int number){
	if(on==1){
		set<vi> realanswer;
		for(int i=0; i<(int)mask.length(); i++){
			vi answer(mask.length(), 0);
			if(stoi(charToString(mask[i]))<number){
				answer[i]=1;
				realanswer.insert(answer);
			}
		}
		return realanswer;
	}else if(on<oneCount){
		set<vi> prev=solve(on-1, mask, oneCount, number);
		set<vi> ans;
		for(auto itr : prev){
			int sum=0;
			for(int i=0; i<(int)itr.size(); i++){
				if(itr[i]==1){
					sum+=stoi(charToString(mask[i]));
				}
			}
			for(int i=0; i<(int)mask.length(); i++){
				vi possibleAnswer=itr;
				if(stoi(charToString(mask[i]))+sum<number){
					possibleAnswer[i]=1;
					ans.insert(possibleAnswer);
				}
			}

		}
		return ans;
	}else{
		set<vi> prev=solve(on-1, mask, oneCount, number);
		set<vi> ans;
		for(auto itr : prev){
			int sum=0;
			for(int i=0; i<(int)itr.size(); i++){
				if(itr[i]==1){
					sum+=stoi(charToString(mask[i]));
				}
			}
			for(int i=0; i<(int)mask.length(); i++){
				vi possibleAnswer=itr;
				if(stoi(charToString(mask[i]))+sum==number){
					possibleAnswer[i]=1;
					ans.insert(possibleAnswer);
				}
			}
		}
		return ans;
	}
}
int main() {
	ifstream fin;
	fin.open("text.txt");
	for(int z=0; z<10; z++){
		string mask;
		int oneCount, number;
		cin>>mask>>oneCount>>number;
		if(number==0){
			cout<<"NONE"<<endl;
			continue;
		}
		set<vi> answers;
		answers=solve(oneCount, mask, oneCount, number);
		for(auto itr : answers){
			for(auto it : itr){
				cout<<it;
			}
			cout<<endl;
		}
	}
}
