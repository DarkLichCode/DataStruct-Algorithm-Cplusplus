/**
 * 二叉树
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

class BinaryTree {

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

	BinTreeNode* makeBinTreeByPreIn(vector<DataType> preorder, vector<DataType> inorder, int preLeft, int preRight, int inLeft, int inRight) {
		if (preLeft > preRight || inLeft > inRight)
			return NULL;

		BinTreeNode* node = new BinTreeNode (preorder[preLeft]);
		int index = findIndex(inorder, inLeft, inRight, node->data);

		node->Left = makeBinTreeByPreIn(preorder, inorder, preLeft+1, preLeft+(index-inLeft), inLeft, index-1);
		node->Right = makeBinTreeByPreIn(preorder, inorder, preLeft+(index-inLeft)+1, preRight, index+1, inRight);
		return node;
	}

	int findIndex(vector<DataType> dataVector, int dataLeft, int dataRight, DataType value) {
		for (int i = dataLeft; i <= dataRight; ++i) {
			if (dataVector[i] == value)
				return i;
		}
		return -1;
	}

public:

	BinaryTree() {
		this->root = NULL;
	}

	//判断二叉树是否为空
	bool isEmpty() {
		return this->root == NULL;
	}

	//递归先序遍历二叉树
	void preOrder() {

		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		this->preOrder(this->root);
		cout<< endl;
	}

	//递归中序遍历二叉树
	void inOrder() {

		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		this->inOrder(this->root);
		cout<< endl;
	}

	//递归后序遍历二叉树
	void postOrder() {

		if (isEmpty()) {
			cout<< "二叉树为空！！！无需遍历！！！！"<< endl;
			return;
		}

		this->postOrder(this->root);
		cout<< endl;
	}

	//层序遍历二叉树
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

	//根据先序和中序的遍历结果生成二叉树
	void makeBinTreeByPreIn(vector<DataType> preorder, vector<DataType> inorder) {
		if (preorder.size() != inorder.size()) {
			cout<< "前序遍历和中序遍历节点数量不一致！！！无法生成二叉树！！！！"<< endl;
			return;
		}

		if (preorder.size() == 0) {
			cout<< "前序遍历和中序遍历节点数量为0！！！无法生成二叉树！！！！"<< endl;
			return;
		}

		if (!isEmpty()) {
			cout<< "二叉树不为空！！！无法生成二叉树！！！！"<< endl;
			return;
		}

		this->root = makeBinTreeByPreIn(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);

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
};