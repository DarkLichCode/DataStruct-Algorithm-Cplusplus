/**
 * 顺序栈
 * @author 黑暗巫妖
 */
#include <iostream>
#define MaxSize 100
using namespace std;

typedef int DataType;

class ArrayStack {

private:

	DataType stack[MaxSize];
	int top;
	int base;

public:

	ArrayStack() {
		this->base = 0;
		this->top = 0;
	}

	//判断栈是否为空
	bool isEmpty() {
		return this->top == this->base;
	}

	//判断栈是否已满
	bool isFull() {
		return this->top == MaxSize;
	}

	//入栈操作
	void push(DataType value) {
		if (isFull()) {
			cout<< "栈已满！！！无法再压入数据！！！！"<< endl;
			return;
		}

		this->stack[this->top] = value;
		this->top++;
		cout<< "入栈成功！！！！"<< endl;
	}

	//出栈操作
	void pop() {
		if (isEmpty()) {
			cout<< "栈已空！！！无法再继续出栈！！！！"<< endl;
			return;
		}

		this->top--;
		cout<< "出栈成功！！！！"<< endl;
	}

	//获取栈顶元素
	DataType getTopValue() {
		if (isEmpty()) {
			cout<< "栈已空！！！无法栈顶元素可取！！！！"<< endl;
			return -1;
		}

		return this->stack[this->top-1];
	}

	//清空栈
	void clear() {
		if (isEmpty()) {
			cout<< "栈已空！！！无需清空！！！！"<< endl;
			return;
		}

		this->top = this->base;
		cout<< "栈清空完毕！！！！"<< endl;
	}

	//从栈顶到栈底输出栈
	void print() {
		if (isEmpty()) {
			cout<< "栈已空！！！无需打印！！！！"<< endl;
			return;
		}

		for (int i = this->top-1; i >= this->base; i--) {
			cout<< this->stack[i]<< "  ";
		}
		cout<<endl;
	}
};
