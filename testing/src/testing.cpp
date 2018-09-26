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

int recursion(int x, int y){
	if(x%2==0 && y%2!=0){
		return recursion(x/2, y-1)+3*x;
	}else if(x%2==0 && y%2==0){
		return recursion(y-2, x+1) +x ;
	}else if(x%2!=0 && y%2==0){
		return pow(x, 2) - pow(y, 2);
	}else{
		return recursion(y+1, x-1)-2*y;
	}
}
int recursion2(int x, int y){
	if(x%2==0 && y%2!=0){
		int thing=recursion2(x/2, y-1)+3*x;
		return thing;
	}else if(x%2==0 && y%2==0){
		int otherthing=recursion2(y-2, x+1)+x;
		return recursion2(y-2, x+1)+otherthing;
	}else if(x%2!=0 && y%2==0){
		return pow(x, 2)-pow(y, 2);
	}else{
		return recursion2(y+1, x-1)-2*y;
	}
}
int recursion3(int x, int y){
	if(x>1){
		return recursion3(recursion3(y-3, x-2), recursion3(y-1, x));
	}else{
		return x-y;
	}
}
int main() {
	cout<<recursion3(4,5);
}
