#include<iostream> 
#include<cstring>
using namespace std;

const int maxn = 200;
int sum[maxn]; //ĳһ�е�Ȩֵ֮�� 
/*
	�ݹ��ȡһ������Ȩֵ��������sum��posλ�� 
*/
void build(int pos){ 
//	cout << "new Thread pos:" << pos << endl;
	int v; 
	cin >> v;
//	cout << "Input:" << v << endl; 
	if(v==-1) 
	{
//		cout << "return" << endl;
		return;//����ȡ����ֵΪ-1��������� 
	}
	//����Ӧ������ȡ������������������
	sum[pos] += v;
	build(pos-1);
	build(pos+1);
	
	return;
} 
/*
	����һ���� 
*/
bool init(){
	//��ʼ��sum
	memset(sum,0,sizeof(sum));
	//������ڵ�
	int v;
	int pos = maxn/2; //���ڵ�ĳ�ʼλ�� 
	cin >> v;
//	cout << "Input:" << v << endl; 
	if(v==-1) return false; 
	sum[pos] = v;
	//��ȡ
	build(pos-1); //��ȡ���ڵ��������
	build(pos+1); //��ȡ���ڵ�������� 
	return true;
}
int main(){
	int no = 0; 
	while(init())
	{
		no++;
		//���sum
		int p = 0;
		while(sum[p] == 0) p++; //�ҳ������Ҷ�ӵ�λ��
		cout <<  "Case " << no << ":\n" << sum[p];
		while(sum[++p] != 0)
		{
			cout << " " << sum[p]; 
		}
		cout << endl << endl;
		
	}

	return 0;

} 
