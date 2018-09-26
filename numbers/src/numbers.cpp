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


vector<string> separateDigits(string number){
	int temp=number.length();
	vector<string> answers;
	for(int i=0; i<temp; i++){
		string s=number.substr(i, 1);
		answers.push_back(s);
	}
	return answers;
}
vector<int> convertToInt(vector<string> number){
	vector<int> results;
	for(vector<string>::iterator itr=number.begin(); itr!=number.end(); itr++){
		int temp;
		stringstream convert(*itr);
		convert>>temp;
		results.push_back(temp);
	}
	return results;
}

long long findSmallest(vector<int> allNums){
	sort(allNums.begin(), allNums.end());
	string num;
	for(vector<int>::iterator itr=allNums.begin(); itr!=allNums.end(); itr++){
		stringstream ss;
		ss<<*itr;
		string temp=ss.str();
		num.append(temp);
	}
	long long result;
	stringstream covt(num);
	covt>>result;
	return result;
}
bool largestSort(int i, int j){
	return (i>j);
}
long long findLargest(vector<int> allNums){
	sort(allNums.begin(), allNums.end(), largestSort);
	string num;
	for(vector<int>::iterator itr=allNums.begin(); itr!=allNums.end(); itr++){
		stringstream ss;
		ss<<*itr;
		string temp=ss.str();
		num.append(temp);
	}
	long long result;
	stringstream covt(num);
	covt>>result;
	return result;
}
string convertToString(int num){
	stringstream ss;
	ss<<num;
	string result=ss.str();
	return result;
}
string convertToStringLong(long long num){
	stringstream ss;
	ss<<num;
	string result=ss.str();
	return result;
}
int convertToInt(string num){
	stringstream convert(num);
	int result;
	convert>>result;
	return result;
}
long long convertToLongLong(string num){
	stringstream convert(num);
	long long result;
	convert>>result;
	return result;
}
int* findNextNum(int num[], int size){
	vector<int> willchange;
	int changeat;
	bool found=false;
	for(int i=size-2; i>0; i--){
		int numon=num[i];
		int min=10;
		for(int j=i+1; j<size; j++){
			if(num[j]>numon&&num[j]<min){
				min=num[j];
				changeat=j;
				found=true;
			}
		}
		if(found){
			int saved=num[i];
			num[i]=min;
			num[changeat]=saved;
			changeat=i+1;
			for(int l=changeat; l<size; l++){
				willchange.push_back(num[l]);
			}
			break;
		}
	}
	long long smallest=findSmallest(willchange);
	string smallestNum=convertToStringLong(smallest);
	int count=0;
	for(int k=changeat; k<size; k++){
		string temp=smallestNum.substr(count, 1);
		int place=convertToInt(temp);
		num[k]=place;
		count++;
	}
	return num;
}
int * findNextSmallestNum(int num[], int size){
	vector<int> willchange;
	int changeat;
	bool found=false;
	for(int i=size-2; i>0; i--){
		int numon=num[i];
		int min=-1;
		for(int j=i+1; j<size; j++){
			if(num[j]<numon&&num[j]>min){
				min=num[j];
				changeat=j;
				found=true;
			}
		}
		if(found){
			int saved=num[i];
			num[i]=min;
			num[changeat]=saved;
			changeat=i+1;
			for(int k=changeat; k<size; k++){
				willchange.push_back(num[k]);
			}
			break;
		}
	}
	long long largest=findLargest(willchange);
	string largestNum=convertToStringLong(largest);
	int count=0;
	for(int l=changeat; l<size; l++){
		string temp=largestNum.substr(count, 1);
		int place=convertToInt(temp);
		num[l]=place;
		count++;
	}
	return num;

}
int * changeToArray(vector<int> num, int size, int array[]){
	int count=0;
	for(vector<int>::iterator itr=num.begin(); itr!=num.end(); itr++){
		array[count]=*itr;
		count++;
	}
	return array;
}
void printWithoutLeading0(int array[], int size){
	string temp;
	for(int i=0; i<size; i++){
		string temporary=convertToString(array[i]);
		temp.append(temporary);
	}
	cout<<convertToLongLong(temp);
}
long long getWithoutLeading0(int array[], int size){
	string temp;
	for(int i=0; i<size; i++){
		string temporary=convertToString(array[i]);
		temp.append(temporary);
	}
	return convertToLongLong(temp);
}
int * longLongToArray(long long num, int size){
	int *result;
	result=new int[size];
	string number=convertToStringLong(num);
	for(int i=0; i<size; i++){
		result[i]=convertToInt(number.substr(i, 1));
	}
	return result;
}
long long closestTo(long long num, int numbs[], int size){
	string number=convertToStringLong(num);
	int *numarr;
	numarr=new int[size];
	int *resultarr;
	resultarr=new int[size];
	vector<int> willsort;
	for(int i=0; i<size; i++){
		string temp=number.substr(i, 1);
		numarr[i]=convertToInt(temp);
	}
	for(int j=0; j<size; j++){
		if(find(numbs, numbs+size, numarr[j])==numbs+size){
			int min=10, at;
			for(int k=0; k<size; k++){
				if(abs(numarr[j]-numbs[k])<min&&numbs[k]!=0){
					min=abs(numarr[j]-numbs[k]);
					at=k;
				}
			}
			resultarr[j]=numbs[at];
			for(int l=0; l<size; l++){
				if(l!=at){
					willsort.push_back(numbs[l]);
				}
			}
			if(abs(min)<numbs[j]){
				sort(willsort.begin(), willsort.end());
			}else{
				sort(willsort.begin(), willsort.end(), largestSort);
			}
			int count=j+1;
			for(vector<int>::iterator itr=willsort.begin(); itr!=willsort.end(); itr++){
				resultarr[count]=*itr;
				count++;
			}
			break;
		}else{
			resultarr[j]=numarr[j];
			numarr[j]=100;
		}
	}
	string resultstr;
	for(int z=0; z<size; z++){
		string temporary=convertToString(resultarr[z]);
		resultstr.append(temporary);
	}
	return convertToLongLong(resultstr);
}
int main() {
	ifstream fin;
	fin.open("in.txt");
	string number; int k;
	cin>>number>>k;
	vector<string> separateNum=separateDigits(number);
	vector<int> num=convertToInt(separateNum);
	int numsize=num.size();
	cout<<findSmallest(num)<<" "<<findLargest(num)<<" ";
	int *sortednum;
	sortednum=new int[numsize];
	long long tempnum=findSmallest(num);
	string sortedNum=convertToStringLong(tempnum);
	sort(num.begin(), num.end());
	long long tempo=findLargest(num);
	sortednum=longLongToArray(tempo, numsize);
	for(int b=0; b<49; b++){
		sortednum=findNextSmallestNum(sortednum, numsize);
	}
	printWithoutLeading0(sortednum, numsize);
	cout<<" ";
	int count=0;
	for(vector<int>::iterator itr=num.begin(); itr!=num.end(); itr++){
		sortednum[count]=*itr;
		count++;
	}
	for(int y=0; y<k-1; y++){
		sortednum=findNextNum(sortednum, numsize);
	}
	printWithoutLeading0(sortednum, numsize);
	cout<<" ";
	long long dude=(findSmallest(num)+findLargest(num))/2;
	cout<<closestTo(dude, sortednum, numsize);
	fin.close();
}
