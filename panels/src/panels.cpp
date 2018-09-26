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

int main() {
	double wallWidth, wallHight, panelHight, panelWidth;
	cin>>wallWidth>>wallHight>>panelWidth>>panelHight;
	double wallArea=wallHight*wallWidth;
	double panelArea=panelHight*panelWidth;
	double halfHight=((wallHight/2)-panelHight/2);
	int rowAmt=halfHight/panelHight;
	int middleRowPanels=wallWidth/panelWidth;
	int panelCount=0;
	double tempWallWidth=wallWidth;
	for(int i=0; i<rowAmt; i++){
		tempWallWidth-=panelWidth/2;
		panelCount+=tempWallWidth/panelWidth;
	}
	tempWallWidth=wallWidth;
	for(int j=0; j<rowAmt; j++){
		tempWallWidth-=panelWidth/4;
		panelCount+=tempWallWidth/panelWidth;
	}
	panelCount+=middleRowPanels;
	double result=wallArea-panelCount*panelArea;
	cout<<result<<endl;
}
