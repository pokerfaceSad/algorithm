/*
	�����Ŀ����� 
	��������a^n%m
*/
#include<iostream>
using namespace std;


int _pow(int a,long long n,int m)
{
	if(n==0) return 1%m; //a^0 % m
	long long temp = _pow(a,n/2,m);
	if(n%2 == 1) return (temp*temp*a)%m;//��n����������ƽ�����ٳ���һ��a�õ�a^n 
	else return temp*temp%m; 
}

int main(){
	int i = _pow(2,16,10000);
	cout << i;
	return 0;
}
