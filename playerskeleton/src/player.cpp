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
#include "player.h"
using namespace std;


Player::Player(string a, double b, string c, double d, double e){
	name=a;
	bday=b;
	city=c;
	contractYears=e;
	contractAmount=d;
}
string Player::getName(void){
	return name;
}
int Player::getAge(){
	return 2017-bday;
}
double Player::getAnnualSalary(){
	return contractAmount/contractYears;
}


