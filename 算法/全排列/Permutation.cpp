#include<iostream>
#include<list>
#include<vector>
#define dataType int
using namespace std;

int num = 0; 

void permutation(int prefixIndex,list<dataType> l,vector<dataType> output) 
{
	if(prefixIndex!=-1) 
	{
		list<dataType>::iterator it = l.begin();
		advance(it,prefixIndex);
		output.push_back(*it);
		l.erase(it);
	}
	if(l.empty())
	{
		for(vector<dataType>::iterator it = output.begin();it!=output.end();it++)
		{
			cout << *it << " ";
		}
		num++;
		cout << endl;
	}else{
		for(int i=0;i<l.size();i++)
		{
			permutation(i,l,output);
		}
		
	}
}
int main(){
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);
	l.push_back(11);
	l.push_back(12);
	vector<dataType> output;
	permutation(-1,l,output);
	cout << "NUM : " << num << endl; 
	return 0;
} 
