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

int main() {
	map<player, int> playerscopy;
	map<int, player> players;
	for(int i=0; i<10; i++){
		string a, b, c, d;
		double e, f, g;
		cin>>a>>b>>c>>d>>e>>f>>g;
		player guy(a, b, c, d, e, f, g);
		playerscopy.insert(pair<player, int>(guy, i));
	}
	sort(playerscopy.begin(), playerscopy.end());
	for(map<player, int>::iterator itr=playerscopy.begin(); itr!=playerscopy.end(); itr++){
		players.insert(pair<int, player>((*itr).second, (*itr).first));
	}
	player dude("a", "b", "c", "d", 1, 2, 3);
	cout<<dude.range16(players)<<endl<<dude.midrange(players)<<endl<<
			dude.expected16(players)<<endl<<dude.averageExpected18(players)<<endl<<
			dude.median(players);
}



