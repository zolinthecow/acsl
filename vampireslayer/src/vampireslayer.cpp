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

vector< vector<int> > permutationfail(vector<int> numbers){
	vector< vector<int> > permutes;
	if(numbers.size()==1){
		vector<int> things;
		things.push_back(numbers.front());
		permutes.push_back(things);
		return permutes;
	}else{
		vector< vector<int> >all;
		for(vector<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
			int things;
			vector< vector<int> > temp;
			things=*it;
			vector<int> numberscopy;
			for(vector<int>::iterator bob=numbers.begin(); bob!=numbers.end(); bob++){
				if(*bob!=things){
					numberscopy.push_back(*bob);
				}
			}
			temp=permutationfail(numberscopy);
			for(vector< vector<int> >::iterator itr=temp.begin(); itr!=temp.end(); itr++){
				(*itr).push_back(things);
			}
			for(vector< vector<int> >::iterator aden=temp.begin(); aden!=temp.end(); aden++){
				all.push_back(*aden);
			}
		}
		return all;
	}
}


vii calculateFangs(int vampire){
	string vampiretemp=intToString(vampire);
	vi vampiredigits;
	for(unsigned int i=0; i<vampiretemp.length(); i++){
		string temp=vampiretemp.substr(i, 1);
		vampiredigits.push_back(stringToInt(temp));
	}
	vector< vi > permutations=permutationfail(vampiredigits);
	for(vector< vi >::iterator itr=permutations.begin(); itr!=permutations.end(); itr++){
		string first, second;
		for(int j=0; j<(*itr).size(); j++){

		}
	}
}
int main() {
	int vampire;
	cin>>vampire;
	vii answers=calculateFangs(vampire);
	if(answers.size()==0){
		cout<<"NONE";
		return 0;
	}
	/*int thing=0;
	for(int i=0; i<99999999; i++){
		for(int j=0; j<999999999; j++){
			for(int k=0; k<9999999999; k++){
				thing++;
			}
		}
	}*/
	for(vii::iterator itr=answers.begin(); itr!=answers.end(); itr++){
		cout<<(*itr).first<<","<<(*itr).second;
		if(itr!=answers.begin()+answers.size()-1){
			cout<<" and ";
		}
	}
}
