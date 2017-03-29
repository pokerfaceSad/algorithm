/*
	Name: Problem E: Water Problem
	Copyright: 
	Author: 
	Date: 09/03/17 11:21
	Description: ��������� 
*/

#include<iostream>
#include<cmath> 
#include<cstring> 
using namespace std;

long long matrix[4][4] = {1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0}; //ת�ƾ��� 
long long result[4][4];
long long initValue[4]; 
int mod = (int)(pow(10,9)+7);
const int maxn = 4;
//ȡ�����������
void getColVector(long long a[maxn][maxn],long long colNum,long long colVector[maxn])
{
	for(long long i=0;i<maxn;i++)
		colVector[i] = a[i][colNum];
}
//���������˷�
long long vectorMultiply(long long a[maxn],long long b[maxn])
{
	long long result = 0;
	for(int i=0;i<maxn;i++)	
		result += a[i]*b[i];
	return result;
} 
//������
void copyMatrix(long long from[maxn][maxn],long long to[maxn][maxn])
{
	for(int i=0;i<maxn;i++)	
	{
		for(int j=0;j<maxn;j++) 
		{
			to[i][j] = from[i][j];
		}
	} 
} 
//�������˷�
void matrixMultiply(long long a[maxn][maxn],long long b[maxn][maxn],long long result[maxn][maxn]){
	long long colVector[maxn];
	long long _a[maxn][maxn],_b[maxn][maxn];
	copyMatrix(a,_a);
	copyMatrix(b,_b);
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			getColVector(_b,j,colVector); 
			result[i][j] = vectorMultiply(colVector,_a[i]); 
		}
	}
} 
//������ 
void _pow(long long a[maxn][maxn],long long n,long long result[maxn][maxn])
{	
	if(n==0) 
	{
		memset(result,0,sizeof(result));
		for(int i=0;i<maxn;i++)
			result[i][i] = 1; //����һ����λ�� 
		return; 
	}
	
	_pow(a,n/2,result);
	if(n%2 == 1) 
	{
		matrixMultiply(result,result,result);//��nΪ��������ƽ�����ٳ���a 
		matrixMultiply(result,a,result);//��nΪ��������ƽ�����ٳ���a 
	}
	else{
		matrixMultiply(result,result,result);//��nΪ��������ƽ�����ٳ���a 
	}
	return;
}
int slove(int n)
{
	//��n<=4ֱ����� 
	if(n<=4)
	{	
		for(int i=2;i<n;i++)
        {
            initValue[i] = initValue[i-1]+initValue[i-2]+sin(asin(1)*i);
        }
		return initValue[n-1]%mod;	
	} 
	else{
		for(int i=2;i<maxn;i++)
        {
            initValue[i] = initValue[i-1]+initValue[i-2]+sin(asin(1)*i);
        }
        for(int i=0;i<maxn/2;i++) //����ʼ�������� 
        {	
        	int temp;
        	temp = initValue[i]; 
        	initValue[i] = initValue[maxn-1-i];	
        	initValue[maxn-1-i] = temp; 
		}	
		//��ת�ƾ����n-4���� 
		memset(result,0,sizeof(result));
		_pow(matrix,n-4,result);
		
		return vectorMultiply(result[0],initValue)%mod;
	}
	 
} 

int main(){
	int n;
	while(cin >> initValue[0] >> initValue[1] >> n)
	{
		cout << slove(n) << endl;	 
	}
	return 0;
}
