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

bool rectangleSort(int i, int j) {
	int iarea1 = i / 10;
	int iarea2 = i - iarea1 * 10;
	int iarea = iarea1 * iarea2;
	int jarea1 = j / 10;
	int jarea2 = j - jarea1 * 10;
	int jarea = jarea1 * jarea2;
	if (iarea > jarea) {
		return true;
	} else if (iarea < jarea) {
		return false;
	} else {
		if (i / 10 > j / 10) {
			return true;
		} else {
			return false;
		}
	}
}
bool allSort(int i, int j) {
	string inum;
	string jnum;
	stringstream ss;
	ss << i;
	inum = ss.str();
	stringstream convert;
	convert << j;
	jnum = convert.str();
	int iarea = 1, jarea = 1;
	if (inum.length() == 2) {
		for (int i = 0; i < 2; i++) {
			int result;
			stringstream s(inum.substr(i, 1));
			s >> result;
			iarea *= result;
		}
	}
	if (jnum.length() == 2) {
		for (int i = 0; i < 2; i++) {
			int result1;
			stringstream s(jnum.substr(i, 1));
			s >> result1;
			jarea *= result1;
		}
	}
	if (inum.length() == 3) {
		int result, result2, result3;
		stringstream s(inum.substr(0, 1));
		s >> result;
		stringstream sb(inum.substr(1, 1));
		sb >> result2;
		stringstream sc(inum.substr(2, 1));
		sc >> result3;
		iarea = result * result3 + (result2 - result3);
	}
	if (jnum.length() == 3) {
		int result4, result5, result6;
		stringstream s(jnum.substr(0, 1));
		s >> result4;
		stringstream sb(jnum.substr(1, 1));
		sb >> result5;
		stringstream sc(jnum.substr(2, 1));
		sc >> result6;
		jarea = result4 * result6 + (result5 - result6);
	}
	if (iarea > jarea) {
		return true;
	} else if (iarea < jarea) {
		return false;
	} else {
		if (i > 99) {
			if (i / 100 > j / 100) {
				return true;
			} else {
				return false;
			}
		} else {
			if (i / 10 > j / 10) {
				return true;
			} else {
				return false;
			}
		}
	}
}
vector<int> fillRectangles(vector<int> rectangles, int boardWidth,
		int boardHight) {
	vector<int> result;
	bool notFilled = true;
	int hightLeft = boardHight, widthLeft = boardWidth, nextSpotWidth,
			nextSpotHight;
	vector<int> used;
	while (hightLeft > 0 && widthLeft > 0) {
		int nextpiece;
		for (vector<int>::iterator itr = rectangles.begin();
				itr != rectangles.end(); itr++) {
			if (*itr / 10 <= widthLeft
					&& *itr - (*itr / 10) * 10 <= hightLeft) {
				if (find(used.begin(), used.end(), *itr) == used.end()) {

					nextpiece = *itr;
					notFilled = false;
					used.push_back(*itr);
					break;

				}
			}
		}
		if (notFilled) {
			result.clear();
			return result;
		}
		if (widthLeft - nextpiece / 10 == 0) {
			nextSpotWidth = widthLeft;
			nextSpotHight = hightLeft - (nextpiece - (nextpiece / 10) * 10);
			hightLeft = nextSpotHight;
			widthLeft = nextSpotWidth;
		} else {
			nextSpotWidth = widthLeft - nextpiece / 10;
			nextSpotHight = hightLeft;
			widthLeft = nextSpotWidth;
			hightLeft = nextSpotHight;
		}
		result.push_back(nextpiece);
	}
	return result;
}
vector<int> fillAll(vector<int> allPieces, int boardWidth, int boardHight) {
	vector<int> result;
	bool notFilled = true;
	int hightLeft = boardHight, widthLeft = boardWidth, nextSpotWidth,
			nextSpotHight;
	vector<int> used;
	while (hightLeft > 0 && widthLeft > 0) {
		int nextpiece;
		for (vector<int>::iterator itr = allPieces.begin();
				itr != allPieces.end(); itr++) {
			int temp = *itr / 10;
			if (*itr > 99) {
				if (*itr / 100 <= widthLeft
						&& (*itr - (*itr / 100) * 100) / 10 <= hightLeft) {
					if (find(used.begin(), used.end(), *itr) == used.end()) {
						nextpiece = *itr;
						notFilled = false;
						used.push_back(*itr);
						break;
					}
				}
			}
			if (temp <= widthLeft && *itr - (*itr / 10) * 10 <= hightLeft) {
				if (find(used.begin(), used.end(), *itr) == used.end()) {
					nextpiece = *itr;
					notFilled = false;
					used.push_back(*itr);
					break;
				}
			}
		}
		if (notFilled) {
			result.clear();
			return result;
		}
		if (nextpiece < 99) {
			if (widthLeft - nextpiece / 10 == 0) {
				nextSpotWidth = widthLeft;
				nextSpotHight = hightLeft - (nextpiece - (nextpiece / 10) * 10);
				hightLeft = nextSpotHight;
				widthLeft = nextSpotWidth;
			} else {
				nextSpotWidth = widthLeft - nextpiece / 10;
				nextSpotHight = hightLeft;
				widthLeft = nextSpotWidth;
				hightLeft = nextSpotHight;
			}
		} else {
			int firstDigit = nextpiece / 100, secondDigit = (nextpiece
					- firstDigit * 100) / 10, thirdDigit = nextpiece
					- (firstDigit * 100 + secondDigit * 10);
			if (hightLeft - firstDigit == 0) {
				if (widthLeft == secondDigit) {
					nextSpotWidth = widthLeft - thirdDigit;
					nextSpotHight = hightLeft - 1;
					hightLeft = nextSpotHight;
					widthLeft = nextSpotWidth;
				} else {
					nextSpotWidth = widthLeft - secondDigit;
					nextSpotHight = hightLeft;
					widthLeft = nextSpotWidth;
					hightLeft = nextSpotHight;
				}
			} else {
				nextSpotWidth = widthLeft - thirdDigit;
				nextSpotHight = hightLeft;
				widthLeft = nextSpotWidth;
				hightLeft = nextSpotHight;
			}
		}
		result.push_back(nextpiece);
	}
	return result;
}
int main() {
	vector<int> rectangles;
	vector<int> allpieces;
	for (int i = 0; i < 10; i++) {
		string temp;
		cin >> temp;
		if (temp.length() == 2) {
			int result;
			stringstream convert(temp);
			convert >> result;
			rectangles.push_back(result);
		}
		int inttostring;
		stringstream convt(temp);
		convt >> inttostring;
		allpieces.push_back(inttostring);
	}
	sort(rectangles.begin(), rectangles.end(), rectangleSort);
	sort(allpieces.begin(), allpieces.end(), allSort);

	for (int j = 0; j < 10; j++) {
		int x, y;
		cin >> x >> y;
		if (j < 6) {
			vector<int> answer = fillRectangles(rectangles, x, y);
			if (answer.empty()) {
				cout << "NONE";
			}
			for (vector<int>::iterator itr = answer.begin();
					itr != answer.end(); itr++) {
				cout << *itr << " ";
			}
			cout << endl;
		} else {
			vector<int> answers = fillAll(allpieces, x, y);
			if (answers.empty()) {
				cout << "NONE";
			}
			for (vector<int>::iterator it = answers.begin();
					it != answers.end(); it++) {
				cout << *it << " ";
			}
			cout << endl;
		}
	}
	vector<int> answers = fillAll(allpieces, 8, 4);
}
