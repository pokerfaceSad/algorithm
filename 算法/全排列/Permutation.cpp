#include<iostream>
#include<list>
#define dataType int
using namespace std;

const int maxn = 100;
dataType output[maxn];

int num = 0; 

void permutation(int prefixIndex,list<dataType> l,dataType output[],int location) 
{
	if(prefixIndex!=-1) 
	{
		list<dataType>::iterator it = l.begin();
		advance(it,prefixIndex);
		output[location] = *it;
		l.erase(it);
	}
	if(l.empty())
	{
		for(int i=0;i<=location;i++)
		{
			cout << output[i] << " "; 
		}
		cout << endl;
		num++;
	}else{
		for(int i=0;i<l.size();i++)
		{
			permutation(i,l,output,location+1);
		}
		
	}
}
int main(){
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	permutation(-1,l,output,-1);
	cout << "NUM : " << num << endl; 
	return 0;
} 
