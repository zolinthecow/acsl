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

int multiplyBy(char suit) {
	if (suit == 'H' || suit == 'S') {return 30;
	} else if (suit == 'C' || suit == 'D') {return 20;
	} else {return 40;}}
int main() {
	for (int z = 0; z < 5; z++) {
		int bid, won; char suit;
		cin >> bid >> won >> suit;
		int multiple = multiplyBy(suit), under = 0, over = 0;
		if (multiple != 40) {
			under = bid * multiple;
			if (bid + 6 < won) {
				int temp = won - (bid + 6);
				over = temp * multiple;
			}
		} else {
			for (int i = 0; i < bid; i++) {
				if (i == 0) {
					under += 40;
				} else {
					under += 30;
				}
			}
			if (bid + 6 < won) {
				int temp = won - (bid + 6);
				over = temp * 30;
			}
		}
		cout << under << ", " << over << endl;
	}
}
