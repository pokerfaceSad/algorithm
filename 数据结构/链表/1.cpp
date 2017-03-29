/*
	����һ��������Ϊ1��10�Ĵ�ͷ��������
	��������͵���ת 

*/ 

#include<stdio.h>
#include<stdlib.h>
#define maxn 10 
typedef struct node{
	int value;
	node* next; 

}node;

node* head; 
//��ʼ������ 
void init(){
	
	head = (node*)malloc(sizeof(node)); 
	 
	//ֱ�Ӵ������������ֵ 
	int linkListValue[maxn] = {0,1,2,3,4,5,6,7,8,9}; 	
	node* lastNode = head; 
	for(int i=0;i<maxn;i++) 
	{
		node* n = (node*)malloc(sizeof(node));
		n->next = NULL; 
		n->value = linkListValue[i];
		lastNode->next = n;
		lastNode = n; 
	} 
} 

//��������ת 
void inverse(){

	node *tail = head->next;//�������β�ڵ�
	node *temp = NULL;
	
	while(tail->next != NULL)
	{
		temp = head->next; 
		head->next = tail->next; //���������ͷ�ڵ� 
		tail->next = head->next->next; //β����nextָ��ʣ�������ͷ�ڵ� 
		head->next->next = temp; //��ת 
	}
} 
//��ӡ����
void print(){
	node *p = head->next;
	while(p != NULL)
	{
		printf("%d ",p->value);
		p = p->next;
	}
	printf("\n");
} 
int main(){
	init();
	printf("��ʼ����")
	print();
	inverse();
	printf("��ת��") 
	print();
	return 0; 
} 
