#ifndef PLAYER_H_
#define PLAYER_H_
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

class player{
public:
	string name, bday, city, gender;
	double contractyears, contractamount, guaranteedamount;

	player(string a, string b, string c, string d, double e, double f, double g);

	int range16(map<int, player> players);

	int midrange(map<int, player> players);

	string expected16(map<int, player> players);

	int averageExpected18(map<int, player> players);

	int median(map<int, player> players);


};


#endif /* PLAYER_H_ */
