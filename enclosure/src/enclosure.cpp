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

vector<int> getPositions(string operations){\
	vector<int> answers;
	bool open=false;
	int length=operations.length(), position;
	for(int i=0; i<length; i++){
		if(operations.at(i)=='('){
			open=true;
			position=i;
			break;
		}else if(operations.at(i)==')'){
			position=i;
			break;
		}
	}
	if(open){
		for(int j=position+2; j<length; j++){
			if(operations.at(j)!='+'&&operations.at(j)!='-'&&operations.at(j)!='/'&&operations.at(j)!='*'){
				answers.push_back(j+2);
			}
		}
	}else{
		for(int j=position-2; j>=0; j--){
			if(operations.at(j)!='+'&&operations.at(j)!='-'&&operations.at(j)!='/'&&operations.at(j)!='*'){
				answers.push_back(j+1);
			}
		}
	}
	return answers;
}
int main() {
	ifstream kevinisstupid;
	kevinisstupid.open("retard.txt");
	for(int i=0; i<5; i++){
		string operations;
		kevinisstupid>>operations;
		vector<int> answers=getPositions(operations);
		sort(answers.begin(), answers.end());
		int size=answers.size();
		int count=1;
		for(vector<int>::iterator itr=answers.begin(); itr!=answers.end(); itr++){
			cout<<*itr;
			if(count<size){
				cout<<", ";
			}
			count++;
		}
		cout<<endl;
	}

}
