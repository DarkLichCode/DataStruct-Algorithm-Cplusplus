/**
 * 顺序表
 * @author 黑暗巫妖
 */
#include <iostream>
#define MaxSize 100
using namespace std;

typedef int DataType;

class SequentialList {

private:
	DataType data[MaxSize];
	int length;

public:
	SequentialList() {
		this->length = 0;
	}

	//按值查找坐标
	int findDataIndex(DataType value) {
		for (int i = 0; i < this->length; ++i) {
			if (value == this->data[i])
				return i;
		}

		return -1;
	}

	//查找对应坐标的值
	DataType getDataByIndex(int index) {
		if (index >= this->length || index < 0) {
			cout<< "坐标超出范围！！！！无法搜索！！！！"<< endl;
			return -1;
		}

		return this->data[index];
	}

	//判断是否为空
	bool isEmpty() {
		return this->length == 0;
	}

	//判断顺序表是否已满
	bool isFull() {
		return this->length == MaxSize;
	}

	//查看顺序表长度
	int getLength() {
		return this->length;
	}

	//在指定位置插入节点
	void insertValueToIndex(DataType value, int index) {
		if (isFull()) {
			cout<< "顺序表已满，无法插入！！！！"<< endl;
			return;
		}

		if (index > this->length || index < 0) {
			cout<< "坐标超出范围！！！！无法插入！！！！"<< endl;
			return;
		}

		for (int i = this->length; i > index ; i--) {
			this->data[i] = this->data[i - 1];
		}
		this->data[index] = value;
		this->length++;
		cout<< "插入成功！！！！"<< endl;
	}

	//在指定位置删除节点
	void deleteByIndex(int index) {
		if (isEmpty()) {
			cout<< "顺序表已为空，无法再删除！！！！！！"<< endl;
			return;
		}

		if (index >= this->length || index < 0) {
			cout<< "坐标超出范围！！！！无法删除！！！！"<< endl;
			return;
		}

		for (int i = index; i < this->length; ++i) {
			this->data[i] = this->data[i + 1];
		}
		this->length++;
		cout<< "删除成功！！！！"<< endl;
	}

	//顺序表头部插入新的节点
	void pushFront(DataType value) {
		if (isFull()) {
			cout<< "顺序表已满，无法插入！！！！"<< endl;
			return;
		}

		for (int i = getLength(); i > 0; i--) {
			this->data[i] = this->data[i - 1];
		}
		this->data[0] = value;
		this->length++;
		cout<< "顺序表头部插入成功！！！！"<< endl;
	}

	//顺序表头部节点删除
	void popFront() {
		if (isEmpty()) {
			cout<< "顺序表已为空，无法再删除！！！！！！"<< endl;
			return;
		}

		for (int i = 0; i < this->length; ++i) {
			this->data[i] = this->data[i + 1];
		}
		this->length--;
		cout<< "删除头部节点成功！！！！！"<< endl;
	}

	//顺序表尾部插入新的节点
	void pushBack(DataType value) {
		if (isFull()) {
			cout<< "顺序表已满，无法插入新的节点！！！！"<< endl;
			return;
		}

		this->data[getLength()] = value;
		this->length++;
	}

	//顺序表尾部节点删除
	void popBack() {
		if (isEmpty()) {
			cout<< "顺序表已为空，无法再删除！！！！！！"<< endl;
			return;
		}

		this->length--;
	}

	//清空顺序表
	void clearList() {
		this->length = 0;
	}

	//打印顺序表
	void printList() {
		if (isEmpty()) {
			cout<< "顺序表为空，无数据可打印！！！！"<< endl;
			return;
		}

		for (int i = 0; i < this->length; ++i) {
			cout<< this->data[i]<< "  ";
		}
		cout<<endl;
	}

};
