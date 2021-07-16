/*********************************************
* ���⣺			������
* 
* ʵ�֣�������������ɾ���ġ���
* 
* ��ע���������
* 1,���������ֻ��left�ڵ�
* 2,���������ֻ��right�ڵ�
* 3,���������û�нڵ�
* 4,���������ֻ��һ�����ڵ�
* 5,������һ���ն�����
* 6,�����Ҳ���ֵ
* 7,���ɾ����һ���ڵ��� ���ַ��Ϊ���ֵ  ������ָ����
*********************************************/
#include <iostream>
using namespace std;

typedef struct node
{
	int value;
	struct node* left = NULL;
	struct node* right = NULL;
}Node;

//����right��С�ڵ㣬������С�ڵ��right��top�ڵ��left
Node* find_rightMin(Node* p_tree,Node* top)
{
	if (p_tree == NULL)
		return NULL;
	if (p_tree->left == NULL)
	{
		if (p_tree == top->left)
		{
			top->right = p_tree->right;
			return p_tree;
		}
		top->left = p_tree->right;
		return p_tree;
	}
	else
	{
		return find_rightMin(p_tree->left,p_tree);
	}
}

//����left���ڵ� �������ڵ��left��top�ڵ��right
Node* find_leftMax(Node* p_tree,Node* top)
{
	if (p_tree == NULL)
		return NULL;
	if (p_tree->right == NULL)
	{
		if (p_tree == top->left)
		{
			top->left = p_tree->left;
		}
		else
		{
			top->right = p_tree->left;
		}
		return p_tree;
	}
	else
	{
		return find_leftMax(p_tree->right, p_tree);
	}	
}

//��ӽڵ�
Node* nodeAdd(Node* p_tree,const int number)
{
	//�������Ϊ��ָ�� �򴴽��½ڵ���Ϊ��ʼ�ڵ�
	if (p_tree == NULL)
	{
		p_tree = new Node;
		p_tree->value = number;
		return p_tree;
	}
	if (p_tree->value >= number)//�����ֵС�ڻ���ڵ�ǰ���ڵ�ֵ�������½ڵ�ŵ�left������ָ�������
	{
		p_tree->left = nodeAdd(p_tree->left,number);
		return p_tree;
	}
	else//�����ֵ�ϸ���ڵ�ǰ���ڵ�ֵ�������½ڵ�ŵ�right������ָ�������
	{
		p_tree->right = nodeAdd(p_tree->right,number);
		return p_tree;
	}
}

//���ҽڵ�
Node* findNode(Node* p_tree, const int number)
{
	if (p_tree == NULL)//���������ָ��Ϊ�շ��ؿ�
		return NULL;
	if (p_tree->value == number)//����ڵ�ֵ����number���ؽڵ�ֵ
		return p_tree;
	if (p_tree->value >= number)//����ڵ�ֵ���ڵ���number �����������
		return findNode(p_tree->left, number);
	else//��������Ҳ���
		return findNode(p_tree->right,number);
}

//�޸Ľڵ�
bool editNode(Node* p_tree, int find_number, int edit)
{
	Node* p_edit;
	if (p_edit = findNode(p_tree, find_number))
	{
		p_edit->value = edit;
		return 1;
	}
	return 0;
}

//ɾ���ڵ�  ��left�������ڵ����
bool deleteNode(Node* p_tree,int number)
{
	//ָ��Ϊ�շ�����
	if (p_tree == NULL)
		return 0;
	//�ڵ��ֵ����Ҫɾ������
	if (p_tree->value == number)
	{
		if (p_tree->left != NULL)//��ڵ㲻Ϊ��
		{
			Node* p_Max_node = find_leftMax(p_tree->left, p_tree);//���ֵ�ĵ�ַ
			//�����ֵ��Ҫɾ���Ľڵ� ���ͷŵ����ֵ�Ŀռ�
			p_tree->value = p_Max_node->value;
			delete p_Max_node;
			return 1;
		}
		else if (p_tree->right != NULL)//�ҽڵ㲻Ϊ��
		{
			Node* p_Min_node = find_rightMin(p_tree->right,p_tree);
			p_tree->value = p_Min_node->value;
			delete p_Min_node;
			return 1;
		}
		else//���ҽڵ㶼Ϊ��
		{
			delete p_tree;
			p_tree = NULL;
			return 1;
		}

	}
	else if (p_tree->value >= number)//����ڵ�ֵ���ڵ��ڸ�ֵ ����left�м�������
	{
		return deleteNode(p_tree->left,number);
	}
	else//���� ����right�м�������
	{
		return deleteNode(p_tree->right,number);
	}
}

//ɾ���������нڵ�
void delete_Tree_Node(Node** pp_tree)
{
	//�����߽ڵ㲻Ϊ�������߿�ʼɾ
	if ((*pp_tree)->left != NULL)
	{
		delete_Tree_Node(&((*pp_tree)->left));
	}
	//���ɾ���Ժ� �ұ߲�Ϊ����ɾ���ұ�
	if ((*pp_tree)->right != NULL)
	{
		delete_Tree_Node(&((*pp_tree)->right));
	}
	//���߶�Ϊ����ɾ���Լ� ����ָ������Ϊ��
	delete *pp_tree;
	*pp_tree = NULL;
}

//ɾ����    ������ָ����Ϊ���ܹ�������޸�ָ���ַ
bool deleteTree(Node** pp_tree,int node_val)
{
	
	if (*pp_tree == NULL)
		return 0;
	if ((*pp_tree)->value == node_val)
	{
		delete_Tree_Node(pp_tree);
		return 1;
	}
	else if((*pp_tree)->value < node_val)
	{//���������ȥ�ұ߲���
		
		return deleteTree(&((*pp_tree)->right),node_val);
	}
	else
	{//����ȥ��߲���
		return deleteTree(&((*pp_tree)->left),node_val);
	}

}

int main()
{	
	//����
	Node* p_tree = NULL;
	for (int i = 5; i > 1; i--)
	{
		p_tree = nodeAdd(p_tree,i);//��ӽڵ�
	}
	for (int i = 6; i < 9; i++)
	{
		p_tree = nodeAdd(p_tree,i);//��ӽڵ�
	}

	//����
	Node* p = findNode(p_tree,2);//���ҽڵ�   ��ͬ�ڵ�ֻ�ܲ�������Ľڵ�
	if (p == NULL)
		cout << "δ�ҵ�" << endl;
	else
		cout << "�ҵ��ˣ�" << p->value << endl;

	//�޸�
	if(editNode(p_tree,2,5))
		cout<<"�޸ĳɹ�"<<endl;//�޸Ľڵ�ֵ

	//ɾ���ڵ�
	if (deleteNode(p_tree, 4))
		cout << "ɾ���ɹ�" << endl;
	else
		cout << "ɾ��ʧ��" << endl;

	//ɾ����
	if (deleteTree(&p_tree, 3))
		cout << "ɾ���ɹ�" << endl;
	else
		cout << "ɾ��ʧ��" << endl;
	return 0;
}