#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef char BTDataType;

typedef struct BinaryTreeNode 
{ 
	BTDataType _data;   
	struct BinaryTreeNode* _left;    
	struct BinaryTreeNode* _right; }BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
	BTNode* CreateTree(BTDataType* a, int* pindex)
	{
			if (a[*pindex] == '#')
				return NULL;

			BTNode* root = (BTNode*)malloc(sizeof(BTNode));
			root->_data = a[*pindex];

			++(*pindex);
			root->_left = CreateTree(a, pindex);
			++(*pindex);
			root->_right = CreateTree(a, pindex);
			return root;
	}
	BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
	// ���������� 
	
	int BinaryTreeDestory(BTNode* root)
	{
			if (root == NULL)
				return 0;
			return BinaryTreeDestory(root->_left) + BinaryTreeDestory(root->_right) + 1;
	}// �������ڵ���� 
	
	int BinaryTreeLeafSize(BTNode* root)
	{
		if (root == NULL)
			return 0;
		 else if (root->_left == NULL && root->_right == NULL)
			return 1;
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	}// ������Ҷ�ӽڵ����
	
	int BinaryTreeLevelKSize(BTNode* root, int k)
	{
		if (root == NULL)
			return 0;
		if (k == 1)
			return 1;
		return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	}// ��������k��ڵ����

	// ����������ֵΪx�Ľڵ�
	BTNode* BinaryTreeFind(BTNode* root, BTDataType x); 
	// ������ǰ����� 
	void BinaryTreePrevOrder(BTNode* root);
	// �������������
	void BinaryTreeInOrder(BTNode* root);
	// �������������
	void BinaryTreePostOrder(BTNode* root)
	{


	}// ������� 
	void BinaryTreeLevelOrder(BTNode* root); 
	// �ж϶������Ƿ�����ȫ������
	int BinaryTreeComplete(BTNode* root); 
	int main()
	{
		char a[] = "ABD##E#H##CF##G##";
		int index = 0;
		BTNode* tree = CreateTreea(a, &index);
		printf("size:%d\n", );
		return 0;
	}