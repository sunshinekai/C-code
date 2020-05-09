#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct student
{
	int num;
	char name[10];
	char sex[3];
	float score;
	struct student* next;
};

typedef struct stulist
{
	struct student data;
	struct stulist* next;
}StuN;

int insertNode(StuN* head, struct student nNode)
{
	StuN* Node = (StuN*)malloc(sizeof(StuN));
	Node->data = nNode;
	Node->next = NULL;
	while (head->next != NULL)
	{
		if (head->data.num < Node->data.num && head->next->data.num > Node->data.num)
		{
			Node->next = head->next;
			head->next = Node;
			return 0;
		}
		head = head->next;
	}
	head->next = Node;
	return 0;
}

void Printlist(StuN* head)
{
	StuN* pMove = head->next;
	printf("ѧ����Ϣ����:\n");
	printf("ѧ��\t����\t�Ա�\t�ɼ�\n");
	while (pMove)
	{
		printf("%d\t%s\t%s\t%.2f\n", pMove->data.num, pMove->data.name, pMove->data.sex, pMove->data.score);
		pMove = pMove->next;
	}
}

int main()
{
	char judge;
	struct student nNode;
	StuN* head = (StuN*)malloc(sizeof(StuN));
	head->next = NULL;
	while (1)
	{
		printf("������ѧ�š��������Ա𡢳ɼ�:\n");
		scanf("%d%s%s%f", &nNode.num, nNode.name, nNode.sex, &nNode.score);
		insertNode(head, nNode);
		Printlist(head);
		setbuf(stdin, NULL);
		printf("�Ƿ��������ѧ����Ϣ?(Y/N)");
		judge = getchar();
		if (judge == 'N' || judge == 'n')
			break;
	}
	free(head);
	head = NULL;
	return 0;
}