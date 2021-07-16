/*********************************************
* 标题：			二叉树
* 
* 实现：二叉树的增、删、改、查
* 
* 备注：情况假设
* 1,假设二叉树只有left节点
* 2,假设二叉树只有right节点
* 3,假设二叉树没有节点
* 4,假设二叉树只有一个根节点
* 5,假设是一个空二叉树
* 6,假设找不到值
* 7,如果删除第一个节点树 则地址变为随机值  传二级指针解决
*********************************************/
#include <iostream>
using namespace std;

typedef struct node
{
	int value;
	struct node* left = NULL;
	struct node* right = NULL;
}Node;

//查找right最小节点，并将最小节点的right给top节点的left
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

//查找left最大节点 并将最大节点的left给top节点的right
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

//添加节点
Node* nodeAdd(Node* p_tree,const int number)
{
	//如果参数为空指针 则创建新节点作为起始节点
	if (p_tree == NULL)
	{
		p_tree = new Node;
		p_tree->value = number;
		return p_tree;
	}
	if (p_tree->value >= number)//如果新值小于或等于当前最后节点值，即将新节点放到left，并把指针向后移
	{
		p_tree->left = nodeAdd(p_tree->left,number);
		return p_tree;
	}
	else//如果新值严格大于当前最后节点值，即将新节点放到right，并把指针向后移
	{
		p_tree->right = nodeAdd(p_tree->right,number);
		return p_tree;
	}
}

//查找节点
Node* findNode(Node* p_tree, const int number)
{
	if (p_tree == NULL)//如果二叉树指针为空返回空
		return NULL;
	if (p_tree->value == number)//如果节点值等于number返回节点值
		return p_tree;
	if (p_tree->value >= number)//如果节点值大于等于number 继续向左查找
		return findNode(p_tree->left, number);
	else//否则就向右查找
		return findNode(p_tree->right,number);
}

//修改节点
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

//删除节点  从left中找最大节点替代
bool deleteNode(Node* p_tree,int number)
{
	//指针为空返回零
	if (p_tree == NULL)
		return 0;
	//节点的值等于要删除的数
	if (p_tree->value == number)
	{
		if (p_tree->left != NULL)//左节点不为空
		{
			Node* p_Max_node = find_leftMax(p_tree->left, p_tree);//最大值的地址
			//将最大值给要删除的节点 并释放掉最大值的空间
			p_tree->value = p_Max_node->value;
			delete p_Max_node;
			return 1;
		}
		else if (p_tree->right != NULL)//右节点不为空
		{
			Node* p_Min_node = find_rightMin(p_tree->right,p_tree);
			p_tree->value = p_Min_node->value;
			delete p_Min_node;
			return 1;
		}
		else//左右节点都为空
		{
			delete p_tree;
			p_tree = NULL;
			return 1;
		}

	}
	else if (p_tree->value >= number)//如果节点值大于等于该值 则在left中继续查找
	{
		return deleteNode(p_tree->left,number);
	}
	else//否则 则在right中继续查找
	{
		return deleteNode(p_tree->right,number);
	}
}

//删除树中所有节点
void delete_Tree_Node(Node** pp_tree)
{
	//如果左边节点不为空则从左边开始删
	if ((*pp_tree)->left != NULL)
	{
		delete_Tree_Node(&((*pp_tree)->left));
	}
	//左边删完以后 右边不为空则删除右边
	if ((*pp_tree)->right != NULL)
	{
		delete_Tree_Node(&((*pp_tree)->right));
	}
	//两边都为空则删除自己 并将指针重置为零
	delete *pp_tree;
	*pp_tree = NULL;
}

//删除树    传二级指针是为了能够方便的修改指针地址
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
	{//如果大于则去右边查找
		
		return deleteTree(&((*pp_tree)->right),node_val);
	}
	else
	{//否则都去左边查找
		return deleteTree(&((*pp_tree)->left),node_val);
	}

}

int main()
{	
	//增加
	Node* p_tree = NULL;
	for (int i = 5; i > 1; i--)
	{
		p_tree = nodeAdd(p_tree,i);//添加节点
	}
	for (int i = 6; i < 9; i++)
	{
		p_tree = nodeAdd(p_tree,i);//添加节点
	}

	//查找
	Node* p = findNode(p_tree,2);//查找节点   相同节点只能查找最近的节点
	if (p == NULL)
		cout << "未找到" << endl;
	else
		cout << "找到了：" << p->value << endl;

	//修改
	if(editNode(p_tree,2,5))
		cout<<"修改成功"<<endl;//修改节点值

	//删除节点
	if (deleteNode(p_tree, 4))
		cout << "删除成功" << endl;
	else
		cout << "删除失败" << endl;

	//删除树
	if (deleteTree(&p_tree, 3))
		cout << "删除成功" << endl;
	else
		cout << "删除失败" << endl;
	return 0;
}