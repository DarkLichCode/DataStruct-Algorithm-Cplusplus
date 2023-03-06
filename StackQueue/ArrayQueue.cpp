/**
 * 数组循环队列
 * @author 黑暗巫妖
 */
#include <iostream>
#define MaxSize 100
using namespace std;
typedef int DataType;

class ArrayQueue {

private:
	DataType data[MaxSize];
	int front;
	int rear;

public:
	ArrayQueue() {
		this->front = 0;
		this->rear = 0;
	}

	//判断队列是否为空
	bool isEmpty() {
		return this->front == this->rear;
	}

	//判断队列是否已满
	bool isFull() {
		return (this->rear + 1) % MaxSize == this->front;
	}

	//入队操作
	void push(DataType value) {
		if (isFull()) {
			cout<< "队列已满！！！无法入队！！！！"<< endl;
			return;
		}

		this->data[this->rear] = value;
		this->rear = (this->rear + 1) % MaxSize;
		cout<< "入队成功！！！！"<< endl;
	}

	//出队操作
	void pop() {
		if (isEmpty()) {
			cout<< "队列已空！！！无法出队！！！！"<< endl;
			return;
		}

		this->front = (this->front + 1) % MaxSize;
		cout<< "出队成功！！！！"<< endl;
	}

	//获取队首元素
	DataType getFront() {
		if (isEmpty()) {
			cout<< "队列已空！！！无队头元素！！！！"<< endl;
			return -1;
		}

		return this->data[this->front];
	}

	//获取队尾元素
	DataType getBack() {
		if (isEmpty()) {
			cout<< "队列已空！！！无队尾元素！！！！"<< endl;
			return -1;
		}

		return this->data[(this->rear + MaxSize - 1) % MaxSize];
	}

	//清空队列
	void clear() {

		if (isEmpty()) {
			cout<< "队列已空！！！无需清理！！！！"<< endl;
			return;
		}

		this->front = 0;
		this->rear = 0;
		cout<< "队列已清空！！！！"<< endl;
	}

	//从队首到队尾打印
	void print() {
		if (isEmpty()) {
			cout<< "队列已空！！！无法打印队列！！！！"<< endl;
			return;
		}
		int end = 0;
		if (this->front < this->rear)
			end = this->rear;
		else
			end = this->rear + MaxSize;
		for (int i = this->front; i < end; ++i) {
			cout<< this->data[i % MaxSize]<< "  ";
		}
		cout<< endl;
	}

};
