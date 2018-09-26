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

char *variables;
int ** truthTable;

string intToString(int a){
	string result;
	stringstream convert;
	convert<<a;
	result=convert.str();
	return result;
}
int stringToInt(string a){
	int result;
	stringstream convert(a);
	if(!(convert>>result)){
		result=-1;//if cannot be converted;
	}
	return result;
}
string charToString(char a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s;
}

vs splitString(string line){
	stringstream ss(line);
	vs result;
	while(ss.good()){
		string substr;
		getline(ss, substr, ',');
		substr.erase( remove( substr.begin(), substr.end(), ' ' ), substr.end() );
		result.push_back(substr);
	}
	return result;
}

string assembleExpression(map<int, string> rowsExpressions, int part1, int part2, int answer, int variableAmount){
	vi operationsLeft;
	operationsLeft.push_back(1);
	operationsLeft.push_back(2);
	operationsLeft.push_back(3);
	operationsLeft.push_back(4);
	operationsLeft.push_back(5);
	operationsLeft.push_back(6);
	for(int i=0; i<pow(2, variableAmount); i++){
		vi::iterator itr=find(operationsLeft.begin(), operationsLeft.end(), 1);
		int andLogic=0;
		if(truthTable[i][part1]==1 && truthTable[i][part2]==1){
			andLogic=1;
		}
		if(itr!=operationsLeft.end()){
			if(andLogic!=truthTable[i][answer]){
				operationsLeft.erase(itr);
			}
		}
		int orLogic=1;
		if(truthTable[i][part1]==0 && truthTable[i][part2]==0){
			orLogic=0;
		}
		itr=find(operationsLeft.begin(), operationsLeft.end(), 2);
		if(itr!=operationsLeft.end()){
			if(orLogic!=truthTable[i][answer]){
				operationsLeft.erase(itr);
			}
		}
		int xorLogic=1;
		if(truthTable[i][part1]==truthTable[i][part2]){
			xorLogic=0;
		}
		itr=find(operationsLeft.begin(), operationsLeft.end(), 3);
		if(itr!=operationsLeft.end()){
			if(xorLogic != (truthTable[i][answer])){
				operationsLeft.erase(itr);
			}
		}
		int nandLogic=1;
		if(truthTable[i][part1]==1 && truthTable[i][part2]==1){
			nandLogic=0;
		}
		itr=find(operationsLeft.begin(), operationsLeft.end(), 4);
		if(itr!=operationsLeft.end()){
			if(nandLogic!=truthTable[i][answer]){
				operationsLeft.erase(itr);
			}
		}
		int norLogic=0;
		if(truthTable[i][part1]==0 && truthTable[i][part2]==0){
			norLogic=1;
		}
		itr=find(operationsLeft.begin(), operationsLeft.end(), 5);
		if(itr!=operationsLeft.end()){
			if(norLogic!=truthTable[i][answer]){
				operationsLeft.erase(itr);
			}
		}
		itr=find(operationsLeft.begin(), operationsLeft.end(), 6);
		int xnorTrue=0;
		if(truthTable[i][part1]==truthTable[i][part2]){
			xnorTrue=1;
		}
		if(itr!=operationsLeft.end()){
			if(xnorTrue!=truthTable[i][answer]){
				operationsLeft.erase(itr);
			}
		}
	}
	string result;
	result.append("(");
	if(rowsExpressions.find(part1)!=rowsExpressions.end()){
		result.append(rowsExpressions[part1]);
	}else{
		result.append(charToString(variables[part1]));
	}
	result.append(" ");
	if(operationsLeft.front()==1){
		result.append("AND ");
	}else if(operationsLeft.front()==2){
		result.append("OR ");
	}else if(operationsLeft.front()==3){
		result.append("XOR ");
	}else if(operationsLeft.front()==4){
		result.append("NAND ");
	}else if(operationsLeft.front()==5){
		result.append("NOR ");
	}else{
		result.append("XNOR ");
	}
	if(rowsExpressions.find(part2)!=rowsExpressions.end()){
		result.append(rowsExpressions[part2]);
	}else{
		result.append(charToString(variables[part2]));
	}
	result.append(")");
	return result;
}
string evaluateOperations(vs operationOrders, int variableAmount, int operations){
	map<int, string> rowsExpressions;
	string answer;
	for(unsigned int j=0; j<operationOrders.size(); j++){//vs::iterator itr=operationOrders.begin(); itr!=operationOrders.end(); itr++){
		vi lookingFor;
		for(unsigned int i=0; i<(operationOrders[j]).length(); i++){
			string on=(operationOrders[j]).substr(i, 1);
			int realOn=stringToInt(on);
			realOn-=1;
			lookingFor.push_back(realOn);
		}
		string result=assembleExpression(rowsExpressions, lookingFor.front(), lookingFor.back(), j+variableAmount, variableAmount);
		rowsExpressions.insert(pair<int, string>(j+variableAmount, result));
		answer=result;
	}
	return answer;
}
int main() {
	int variableAmount, operations;
	scanf("%i%*[, ]", &variableAmount);
	scanf("%i%*[, ]", &operations);
	variables=new char[variableAmount];
	for(int i=0; i<variableAmount; i++){
		variables[i]=65+i;
	}
	vs binaryString;
	for(int y=0; y<pow(2, variableAmount); y++){
		string bob=bitset< 64 >( y ).to_string();
		bob.erase(bob.begin(), bob.end()-variableAmount);
		binaryString.push_back(bob);
	}
	vs binaryResults;
	for(unsigned int m=0; m<binaryString.size(); m++){
		string temp;
		getline(cin, temp, ',');
		temp.erase( remove( temp.begin(), temp.end(), ' ' ), temp.end() );
		binaryResults.push_back(temp);
	}
	truthTable=new int *[binaryString.size()];
	for(unsigned int j=0; j<binaryString.size(); j++){
		truthTable[j]=new int[variableAmount+operations];
	}
	for(unsigned int k=0; k<binaryString.size(); k++){
		string oneOn=binaryString[k];
		for(int l=0; l<variableAmount; l++){
			string numberOn=oneOn.substr(l, 1);
			int realNumberOn=stringToInt(numberOn);
			truthTable[k][l]=realNumberOn;
		}
		string otherOneOn=binaryResults[k];
		for(int n=variableAmount; n<variableAmount+operations; n++){
			string otherNumberOn=otherOneOn.substr(n-variableAmount, 1);
			int otherRealNumberOn=stringToInt(otherNumberOn);
			truthTable[k][n]=otherRealNumberOn;
		}
	}
	vs operationOrders;
	string thng;
	getline(cin, thng);
	operationOrders=splitString(thng);
	cout<<evaluateOperations(operationOrders, variableAmount, operations)<<endl;
}
