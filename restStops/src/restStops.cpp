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

bool tastinessSort(ii first, ii second){
	if(first.second>second.second){
		return true;
	}
	return false;
}
int calculateRestStops(int length, int restStopsAmount, int fjSpeed, int bessieSpeed, vii restStops){
	int fjStartingPlace=0, bessieStartingPlace=0, result=0, i=0;
	while(i!=length){
		vii restCopy=restStops;
		restCopy.erase(restCopy.begin(), restCopy.begin()+i);
		sort(restCopy.begin(), restCopy.end(), tastinessSort);
		int restPlace=restCopy.front().first, restTastiness=restCopy.front().second;
		int timeAtStop=(restPlace*fjSpeed-fjStartingPlace*fjSpeed)-(restPlace*bessieSpeed-bessieStartingPlace*bessieSpeed);
		result+=restTastiness*timeAtStop;
		i=restPlace;
		fjStartingPlace=restPlace, bessieStartingPlace=restPlace;
	}
	return result;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("reststops.in");
	fout.open("reststops.out");
	int length, restStopsAmount, fjSpeed, bessieSpeed;
	fin>>length>>restStopsAmount>>fjSpeed>>bessieSpeed;
	vii restStops;
	for(int j=1; j<=length; j++){
		ii thing;
		thing.first=j, thing.second=0;
		restStops.push_back(thing);
	}
	for(int i=0; i<restStopsAmount; i++){
		int position, value;
		fin>>position>>value;
		ii temp;
		temp.first=position, temp.second=value;
		restStops[temp.first-1]=temp;
	}
	fout<<calculateRestStops(length, restStopsAmount, fjSpeed, bessieSpeed, restStops)<<endl;
	fin.close();
	fout.close();
}
