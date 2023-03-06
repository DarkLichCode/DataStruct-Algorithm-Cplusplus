/**
 * 链表栈
 * @author 黑暗巫妖
 */
#include <iostream>
#define MaxSize 100
using namespace std;

typedef int DataType;

typedef struct LinkedNode {
	DataType data;
	LinkedNode* next;
	LinkedNode(DataType x) : data(x), next(NULL){}
}LinkNode;

class LinkedStack{

private:
	LinkNode* top;
	LinkNode* base;
	int size;

public:

	LinkedStack() {
		this->top = NULL;
		this->base = NULL;
		this->size = 0;
	}

	//判断栈是否为空
	bool isEmpty() {
		return this->top == this->base;
	}

	//判断栈是否已满
	bool isFull() {
		return this->size == MaxSize;
	}

	//入栈操作
	void push(DataType value) {

		if (isFull()) {
			cout<< "栈已满！！！无法再压入数据！！！！"<< endl;
			return;
		}

		LinkNode* node = new LinkNode(value);
		node->next = this->top;
		this->top = node;
		this->size++;
		cout<< "入栈成功！！！！"<< endl;
	}

	//出栈操作
	void pop() {

		if (isEmpty()) {
			cout<< "栈已空！！！无法再继续出栈！！！！"<< endl;
			return;
		}

		LinkNode* node = this->top;
		this->top = node->next;
		free(node);

		this->size--;
		cout<< "出栈成功！！！！"<< endl;
	}

	//获取栈顶元素
	DataType getTopValue() {
		if (isEmpty()) {
			cout<< "栈已空！！！无法栈顶元素可取！！！！"<< endl;
			return -1;
		}

		return this->top->data;
	}

	//清空栈
	void clear() {
		if (isEmpty()) {
			cout<< "栈已空！！！无需清空！！！！"<< endl;
			return;
		}

		while (this->top != this->base) {
			LinkNode* node = this->top;
			this->top = node->next;
			free(node);
		}

		this->top = this->base;
		this->size = 0;
		cout<< "栈清空完毕！！！！"<< endl;
	}

	//从栈顶到栈底输出栈
	void print() {
		if (isEmpty()) {
			cout<< "栈已空！！！无需打印！！！！"<< endl;
			return;
		}

		LinkNode* link = this->top;

		while (link != this->base) {
			cout<< link->data<< "  ";
			link = link->next;
		}
		cout<<endl;
	}

};
