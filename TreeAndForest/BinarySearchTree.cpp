/**
 * 二叉搜索树
 * @author 黑暗巫妖
 */
#include <iostream>
#include <queue>
using namespace std;
typedef int DataType;

typedef struct BinTree {
	DataType data;
	struct BinTree* Left;
	struct BinTree* Right;
	BinTree(DataType x) : data(x), Left(NULL), Right(NULL){}
}BinTreeNode;

class BinarySearchTree {

private:

	BinTreeNode* root;

	void preOrder(BinTreeNode* node) {
		if (node == NULL)
			return;
		cout<< node->data<< "  ";
		preOrder(node->Left);
		preOrder(node->Right);
	}

	void inOrder(BinTreeNode* node) {
		if (node == NULL)
			return;
		inOrder(node->Left);
		cout<< node->data<< "  ";
		inOrder(node->Right);
	}

	void postOrder(BinTreeNode* node) {
		if (node == NULL)
			return;
		postOrder(node->Left);
		postOrder(node->Right);
		cout<< node->data<< "  ";
	}

	int getNodeNum(BinTreeNode* node) {
		if (node == NULL)
			return 0;

		return 1 + getNodeNum(node->Left) + getNodeNum(node->Right);
	}

	int getDepth(BinTreeNode* node) {
		if (node == NULL)
			return 0;

		return max(1 + getDepth(node->Left), 1 + getDepth(node->Right));
	}

	int getLeafNum(BinTreeNode* node) {
		if (node == NULL)
			return 0;

		if (node->Left == NULL && node->Right == NULL)
			return 1;

		return getLeafNum(node->Left) + getLeafNum(node->Right);
	}

	void insertToTree(BinTreeNode* node, DataType value) {
		if (value > node->data && node->Right == NULL) {
			node->Right = new BinTreeNode(value);
			return;
		}
		if (value > node->data && node->Right != NULL) {
			insertToTree(node->Right, value);
			return;
		}

		if (value <= node->data && node->Left == NULL) {
			node->Left = new BinTreeNode(value);
			return;
		}
		if (value <= node->data && node->Left != NULL) {
			insertToTree(node->Left, value);
			return;
		}

	}

	BinTreeNode* getMax(BinTreeNode* node) {
		if (node->Right != NULL)
			return getMax(node->Right);
		else
			return node;
	}

	BinTreeNode* getMin(BinTreeNode* node) {
		if (node->Left != NULL)
			return getMin(node->Left);
		else
			return node;
	}

	BinTreeNode* findValue(BinTreeNode* node, DataType value) {
		if (node == NULL)
			return NULL;

		if (value < node->data)
			findValue(node->Left, value);
		else if (value > node->data)
			findValue(node->Right, value);
		else
			return node;
	}

	bool deleteNode(BinTreeNode*& node, DataType value) {
		if (node == NULL)
			return false;

		if (node->data > value) {
			return deleteNode(node->Left, value);
		} else if (node->data < value) {
			return deleteNode(node->Right, value);
		} else {
			if (node->Left == NULL && node->Right == NULL) {
				free(node);
				node = NULL;
				return true;
			} else if (node->Left != NULL && node->Right == NULL) {
				BinTreeNode* tmp = node->Left;
				free(node);
				node = tmp;
				return true;
			} else if (node->Left == NULL && node->Right != NULL) {
				BinTreeNode* tmp = node->Right;
				free(node);
				node = tmp;
				return true;
			} else {
				DataType tmp = getMin(node->Right)->data;
				node->data = tmp;
				return deleteNode(node->Right, tmp);
			}
		}


	}

public:

	BinarySearchTree() {
		this->root = NULL;
	}

	//根据数组初始化二叉搜索树
	void initTree(vector<DataType> initArray) {
		if (!isEmpty()) {
			cout<< "不需要初始化！！！！"<< endl;
			return;
		}

		if (initArray.size() == 0) {
			cout<< "数组无数据！！！无法初始化！！！！"<< endl;
			return;
		}

		this->root = new BinTreeNode(initArray[0]);

		for (int i = 1; i < initArray.size(); ++i) {
			insertToTree(this->root, initArray[i]);
		}
		cout<< "二叉搜索树初始化完成！！！！"<< endl;
	}

	//判断二叉搜索树是否为空
	bool isEmpty() {
		return this->root == NULL;
	}

	//递归先序遍历二叉搜索树
	void preOrder() {

		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		this->preOrder(this->root);
		cout<< endl;
	}

	//递归中序遍历二叉搜索树
	void inOrder() {

		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		this->inOrder(this->root);
		cout<< endl;
	}

	//递归后序遍历二叉搜索树
	void postOrder() {

		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		this->postOrder(this->root);
		cout<< endl;
	}

	//层序遍历二叉搜索树
	void levelOrder() {
		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		BinTreeNode* node = this->root;
		queue<BinTreeNode*> nodes;
		nodes.push(node);
		while (!nodes.empty()) {
			node = nodes.front();
			nodes.pop();
			cout<< node->data<< "  ";
			if (node->Left != NULL)
				nodes.push(node->Left);
			if (node->Right != NULL)
				nodes.push(node->Right);
		}

		cout<<endl;
	}

	//获取节点数
	int getNodeNum() {
		if (isEmpty()) {
			return 0;
		}

		return getNodeNum(this->root);
	}

	//获取树的深度
	int getDepth() {
		if (isEmpty())
			return 0;

		return getDepth(this->root);
	}

	//获取叶子节点数
	int getLeafNum() {
		if (isEmpty())
			return 0;

		return getLeafNum(this->root);
	}

	//向二叉搜索树插入数据
	void insertToTree(DataType value) {
		if (isEmpty()) {
			cout<< "二叉树为空！！！无法插入数据！！！！"<< endl;
			return;
		}

		insertToTree(this->root, value);
	}

	//查找元素
	bool findValue(DataType value) {
		return findValue(this->root, value) != NULL;
	}

	//查找最大值
	int getMax() {
		return getMax(this->root)->data;
	}

	//查找最小值
	int getMin() {
		return getMin(this->root)->data;
	}

	//删除节点
	bool deleteNode(DataType value) {
		return deleteNode(this->root, value);
	}
};