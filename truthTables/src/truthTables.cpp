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

int **truthTable;

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
vs printLabels(string Statement) {
	vs answer;
	vector<char> Statement_fragments;
	vector<char> var;
    bool parenthesis = false;
   for (unsigned int x=0; x < Statement.length(); x++) {
	   if (Statement.at(x) != ' ') {
		   Statement_fragments.push_back(Statement.at(x));
	   }
   }
   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
	   if ((int)Statement_fragments[x] >= 65 && (int)Statement_fragments[x] <= 90) {
		   bool check = true;
		   for (unsigned int q = 0; q < var.size(); q++) {
			   if (Statement_fragments[x] == var[q]) {
				   check = false;
			   }
		   }
		   if (check) {
			   var.push_back(Statement_fragments[x]);
			   answer.push_back(charToString(Statement_fragments[x]));
		   }
	   }
   }
   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
	   if (Statement_fragments[x] == '(') {
		   int q = x;
		   parenthesis = true;
		   string temp;
		   while (Statement_fragments[q + 1] != ')') {
			   q++;
			   temp.append(charToString(Statement_fragments[q]));
		   }
		   answer.push_back(temp);
	   }
   }
   if (parenthesis) {
	   parenthesis = false;
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '(') {
			   parenthesis = true;
		   } else if (Statement_fragments[x] == ')') {
			   parenthesis = false;
		   }
		   if ((Statement_fragments[x] == '@') && !parenthesis) {
			   answer.push_back(charToString(Statement_fragments[x]));
		   }
	   }
	   parenthesis = false;
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '(') {
			   parenthesis = true;
		   } else if (Statement_fragments[x] == ')') {
			   parenthesis = false;
		   }
		   if (Statement_fragments[x] == '*' && !parenthesis) {
			   answer.push_back(charToString(Statement_fragments[x]));
		   }
	   }
	   parenthesis = false;
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '(') {
			   parenthesis = true;
		   } else if (Statement_fragments[x] == ')') {
			   parenthesis = false;
		   }
		   if ((Statement_fragments[x] == '+') && !parenthesis) {
			   answer.push_back(charToString(Statement_fragments[x]));
		   }
	   }
	   parenthesis = false;
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '(') {
			   parenthesis = true;
		   } else if (Statement_fragments[x] == ')') {
			   parenthesis = false;
		   }
		   if ((Statement_fragments[x] == '#') && !parenthesis) {
			   answer.push_back(charToString(Statement_fragments[x]));
		   }
	   }
   } else {
	   bool *checks = new bool[Statement_fragments.size()];
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '@') {
			   answer.push_back("@"+charToString(Statement_fragments[x+1]));
			   checks[x + 1] = true;
		   }
	   }
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '*') {
			   if (!checks[x - 1] && !checks[x + 1]) {
				   checks[x - 1] = true;
				   checks[x + 1] = true;
				   answer.push_back(charToString(Statement_fragments[x-1])+"*"+charToString(Statement_fragments[x+1]));
			   } else {
				   string temp;
				   temp.append(charToString(Statement_fragments[x]));
				   if (!checks[x - 1]) {
					   temp.append(charToString(Statement_fragments[x-1]));
					   checks[x - 1] = true;
				   } else if (!checks[x + 1]) {
					   temp.append(charToString(Statement_fragments[x+1]));
					   checks[x + 1] = true;
				   }
				   answer.push_back(temp);
			   }
		   }
	   }
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '+') {
			   if (!checks[x - 1] && !checks[x + 1]) {
				   checks[x - 1] = true;
				   checks[x + 1] = true;
				   answer.push_back(charToString(Statement_fragments[x-1])+"+"+charToString(Statement_fragments[x+1]));
			   } else {
				   string temp;
				   temp.append(charToString(Statement_fragments[x]));
				   if (!checks[x - 1]) {
					   temp.append(charToString(Statement_fragments[x-1]));
					   checks[x - 1] = true;
				   } else if (!checks[x + 1]) {
					   temp.append(charToString(Statement_fragments[x+1]));
					   checks[x + 1] = true;
				   }
				   answer.push_back(temp);
			   }
		   }
	   }
	   for (unsigned int x=0; x < Statement_fragments.size(); x++) {
		   if (Statement_fragments[x] == '#') {
			   if (!checks[x - 1] && !checks[x + 1]) {
				   checks[x - 1] = true;
				   checks[x + 1] = true;
				   answer.push_back(charToString(Statement_fragments[x-1])+"#"+charToString(Statement_fragments[x+1]));
			   } else {
				   string temp;
				   temp.append(charToString(Statement_fragments[x]));
				   if (!checks[x - 1]) {
					   temp.append(charToString(Statement_fragments[x-1]));
					   checks[x - 1] = true;
				   } else if (!checks[x + 1]) {
					   temp.append(charToString(Statement_fragments[x+1]));
					   checks[x + 1] = true;
				   }
				   answer.push_back(temp);
			   }
		   }
	   }
   }
   return answer;
 }

void evaluateExpression(string expression, int row, int column, int variableAmount){
	if(expression.length()==1){
		if(expression=="@"){
			int firstValue=truthTable[row][column-1];
			if(firstValue==0){
				truthTable[row][column]=1;
				return;
			}else{
				truthTable[row][column]=0;
				return;
			}
		}else{
			int firstValue=truthTable[row][column-2], secondValue=truthTable[row][column-1];
			int first=firstValue, second=secondValue;
			if(expression=="+"){
				if(first==0 && second==0){
					truthTable[row][column]=0;
					return;
				}
				truthTable[row][column]=1;
				return;
			}else if(expression=="*"){
				if(first==1 && second==1){
					truthTable[row][column]=1;
					return;
				}
				truthTable[row][column]=0;
				return;
			}else if(expression=="#"){
				if(first==second){
					truthTable[row][column]=0;
					return;
				}
				truthTable[row][column]=1;
				return;
			}
		}
	}else if(expression.length()==2){
		if(expression.at(0)=='@'){
			char value=expression.at(1)-65;
			if(truthTable[row][int(value)]==0){
				truthTable[row][column]=1;
				return;
			}else{
				truthTable[row][column]=0;
				return;
			}
		}else if(expression.at(0)=='+'){
			char value=expression.at(1)-65;
			if(truthTable[row][int(value)]==0 && truthTable[row][column-1]==0){
				truthTable[row][column]=0;
				return;
			}else{
				truthTable[row][column]=1;
				return;
			}
		}else if(expression.at(0)=='*'){
			char value=expression.at(1)-65;
			if(truthTable[row][int(value)]==1 && truthTable[row][column-1]==0){
				truthTable[row][column]=1;
				return;
			}else{
				truthTable[row][column]=0;
				return;
			}
		}else if(expression.at(0)=='#'){
			char value=expression.at(1)-65;
			if(truthTable[row][int(value)]==truthTable[row][column-1]){
				truthTable[row][column]=0;
				return;
			}else{
				truthTable[row][column]=1;
				return;
			}
		}
	}else{
		vector<char> terms;
		for(unsigned int i=0; i<expression.length(); i++){
			if(expression.at(i)>=65 && expression.at(i)<=90){
				int test2=expression.at(i)-65;
				int test=truthTable[row][test2];
				terms.push_back(test+48);
			}else{
				terms.push_back(expression.at(i));
			}
		}
		unsigned int size=terms.size();
		for(unsigned int j=0; j<size; j++){
			if(terms[j]=='@'){
				if(terms[j+1]=='0'){
					terms[j]='1';
				}else{
					terms[j]='0';
				}
				terms.erase(terms.begin()+(j+1));
				size--;
			}
		}
		size=terms.size();
		for(unsigned int j=0; j<size; j++){
			if(terms[j]=='*'){
				if(terms[j-1]=='1' && terms[j+1]=='1'){
					terms[j+1]='1';
				}else{
					terms[j+1]='0';
				}
				terms.erase(terms.begin()+(j-1), terms.begin()+(j+1));
				size-=2;
			}
		}
		size=terms.size();
		for(unsigned int j=0; j<size; j++){
			if(terms[j]=='+'){
				if(terms[j-1]=='0' && terms[j+1]=='0'){
					terms[j+1]='0';
				}else{
					terms[j+1]='1';
				}
				terms.erase(terms.begin()+(j-1), terms.begin()+(j+1));
				size-=2;
			}
		}
		size=terms.size();
		for(unsigned int j=0; j<size; j++){
			if(terms[j]=='#'){
				if(terms[j-1]==terms[j+1]){
					terms[j+1]='0';
				}else{
					terms[j+1]='1';
				}
				terms.erase(terms.begin()+(j-1), terms.begin()+(j+1));
				size-=2;
			}
		}
		if(terms.front()=='0'){
			truthTable[row][column]=0;
		}else{
			truthTable[row][column]=1;
		}
	}
}
int main() {
	string expressiong;
	getline(cin, expressiong);
	vs labelsg;
	labelsg=printLabels(expressiong);
	for(vs::iterator itr=labelsg.begin(); itr!=labelsg.end(); itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
	int variableAmount=0;
	for(unsigned int i=0; i<labelsg.size(); i++){
		if(labelsg[i].length()==1){
			if(labelsg[i].at(0)>=65 && labelsg[i].at(0)<=90){
				variableAmount++;
			}
		}
	}
	int temp=pow(2, variableAmount);
	truthTable=new int*[temp];
	for(int j=0; j<pow(2, variableAmount); j++){
		truthTable[j]=new int[labelsg.size()];
		string binaryJ=bitset< 64 >( j ).to_string();
		binaryJ.erase(0, 64-variableAmount);
		for(unsigned int k=0; k<binaryJ.length(); k++){
			truthTable[j][k]=stringToInt(binaryJ.substr(k, 1));
		}
	}
	for(int i=0; i<pow(2, variableAmount); i++){
		for(unsigned int j=variableAmount; j<variableAmount+labelsg.size(); j++){
			evaluateExpression(labelsg[j-variableAmount], i, j-variableAmount, variableAmount);
		}
	}
	for(int i=0; i<pow(2, variableAmount); i++){
		for(unsigned int j=0; j<labelsg.size(); j++){
			cout<<truthTable[i][j]<<" ";
		}
		cout<<endl;
	}
}
