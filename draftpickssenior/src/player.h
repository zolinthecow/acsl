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

class Player{
private:
	string name, bday, city;
	int genderM;
	int contractYears;
	double contractAmount, guaranteedAmount;
public:
	Player(string a, string b, string c, int d, int e, double f, double g);

	int range16(vector<Player> players);

	int midrange(vector<Player> players);

	string highestExpected(vector<Player> players);

	int averageExpected18(vector<Player> players);

	double median(vector<Player> players);
};
