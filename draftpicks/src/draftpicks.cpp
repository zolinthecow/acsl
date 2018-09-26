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
using namespace std;

int over10Mil(map<int, double>picks){
	int count=0;
	for(map<int, double>::iterator itr=picks.begin(); itr!=picks.end(); itr++){
		if((*itr).second>10000000){
			count++;
		}
	}
	return count;
}
int averageSalary(map<int, double>picks){
	int count;
	for(map<int, double>::iterator itr=picks.begin(); itr!=picks.end(); itr++){
		count+=(*itr).second;
	}
	count/=5;
	return count;
}
int sixteenSalary(map<int, double>picks){
	int mintemp1=picks.begin()->second;
	float min=mintemp1/16;
	int realmin;
	for(map<int, double>::iterator itr=picks.begin(); itr!=picks.end(); itr++){
		if((*itr).second/16<min){
			float temp=(*itr).second/16;
			min=temp;
			realmin=int(min+.5);
		}
	}
	return realmin;
}
int eighteenSalary(map<int, double>picks){
	float max=0;
	int realmax;
	for(map<int, double>::iterator itr=picks.begin(); itr!=picks.end(); itr++){
		if((*itr).second/18>max){
			max=(*itr).second/18;
			realmax=int(max+.5);
		}
	}
	return realmax;
}
int differenceAverage(map<int, double>picks){
	float count1=0, count2=0;
	for(map<int, double>::iterator itr=picks.begin(); itr!=picks.end(); itr++){
		float temp1=(*itr).second/16;
		int temp=int(temp1+.5);
		count1+=temp;
	}
	count1/=5;
	for(map<int, double>::iterator it=picks.begin(); it!=picks.end(); it++){
		float temp2=(*it).second/18;
		int temp3=int(temp2+.5);
		count2+=temp3;
	}
	count2/=5;
	return count1-count2;
}
int main() {
	ifstream kevinstupid;
	ofstream kevinverystupid;
	kevinstupid.open("draft.in");
	kevinverystupid.open("draft.out");
	map<int, double> picks;
	for(int i=0; i<5; i++){
		int years;
		double money;
		kevinstupid>>years>>money;
		money*=1000000;
		money/=years;
		picks.insert(pair<int, double>(i, money));
	}
	kevinverystupid<<over10Mil(picks)<<endl;
	kevinverystupid<<averageSalary(picks)<<endl;
	kevinverystupid<<sixteenSalary(picks)<<endl;
	kevinverystupid<<eighteenSalary(picks)<<endl;
	kevinverystupid<<differenceAverage(picks)<<endl;
}
