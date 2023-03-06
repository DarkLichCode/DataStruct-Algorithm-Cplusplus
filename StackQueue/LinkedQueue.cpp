/**
 * 链表队列
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

class LinkedQueue {

private:
	LinkNode* front;
	LinkNode* rear;
	int size;

public:

	LinkedQueue() {
		this->front = new LinkNode(0);
		this->rear = this->front;
		this->size = 0;
	}

	//判断队列是否为空
	bool isEmpty() {
		return this->size == 0;
	}

	//判断队列是否已满
	bool isFull() {
		return this->size == MaxSize;
	}

	//入队操作
	void push(DataType value) {
		if (isFull()) {
			cout<< "队列已满！！！无法入队！！！！"<< endl;
			return;
		}

		LinkNode* node = new LinkNode(value);
		node->next = this->rear->next;
		this->rear->next = node;
		this->rear = node;
		this->size++;
		cout<< "入队成功！！！！"<< endl;
	}

	//出队操作
	void pop() {
		if (isEmpty()) {
			cout<< "队列已空！！！无法出队！！！！"<< endl;
			return;
		}

		LinkNode* node = this->front;
		this->front = node->next;
		free(node);
		this->size--;
		cout<< "出队成功！！！！"<< endl;
	}

	//获取队首元素
	DataType getFront() {
		if (isEmpty()) {
			cout<< "队列已空！！！无队头元素！！！！"<< endl;
			return -1;
		}

		return this->front->next->data;
	}

	//获取队尾元素
	DataType getBack() {
		if (isEmpty()) {
			cout<< "队列已空！！！无队尾元素！！！！"<< endl;
			return -1;
		}

		return this->rear->data;
	}

	//清空队列
	void clear() {

		if (isEmpty()) {
			cout<< "队列已空！！！无需清理！！！！"<< endl;
			return;
		}

		LinkNode* link = this->front->next;
		while (link != NULL) {
			LinkNode* node = link;
			link = link->next;
			free(node);
		}
		this->front->next = NULL;
		this->rear = NULL;
		this->size = 0;
		cout<< "队列已清空！！！！"<< endl;
	}

	//从队首到队尾打印
	void print() {
		if (isEmpty()) {
			cout<< "队列已空！！！无法打印队列！！！！"<< endl;
			return;
		}
		LinkNode* link = this->front->next;

		while (link != NULL) {
			cout<< link->data<< "  ";
			link = link->next;
		}

		cout<< endl;
	}

};
