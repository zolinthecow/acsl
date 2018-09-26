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
#ifndef SKELETON_H_
#define SKELETON_H_

class Player{
private:
	string name;
	string city;
	double bday, contractYears, contractAmount;
public:
	Player(string a, double b, string c, double d, double e);

	string getName();

	int getAge();

	double getAnnualSalary();

	vector<Player> sortByName(vector<Player> players);
};



#endif /* SKELETON_H_ */
