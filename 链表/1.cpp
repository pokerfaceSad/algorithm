/*
	建立一个数据域为1到10的带头结点的链表
	将此链表就地逆转 

*/ 

#include<stdio.h>
#include<stdlib.h>
#define maxn 10 
typedef struct node{
	int value;
	node* next; 

}node;

node* head; 
//初始化链表 
void init(){
	
	head = (node*)malloc(sizeof(node)); 
	 
	//直接从数组读入链表值 
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

//将链表逆转 
void inverse(){

	node *tail = head->next;//新链表的尾节点
	node *temp = NULL;
	
	while(tail->next != NULL)
	{
		temp = head->next; 
		head->next = tail->next; //更新链表的头节点 
		tail->next = head->next->next; //尾结点的next指向剩余链表的头节点 
		head->next->next = temp; //逆转 
	}
} 
//打印链表
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
	printf("初始化：")
	print();
	inverse();
	printf("逆转后：") 
	print();
	return 0; 
} 
