/**
 * 单向链表
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

class LinkedList {
private:

	int length;
	LinkNode* HeadNode;

public:

	LinkedList() {
		this->length = 0;
		this->HeadNode = new LinkNode(0);
	}

	// 判断链表是否为空
	bool isEmpty() {
		return this->length == 0;
	}

	// 判断链表是否达到上限
	bool isFull() {
		return this->length == MaxSize;
	}

	//获取链表长度
	int getLength() {
		return this->length;
	}

	// 在尾部插入新的节点
	void pushBack(DataType value) {

		if (isFull()) {
			cout<< "链表已满！！！无法再插入新节点！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode;
		while (link->next != NULL) {
			link = link->next;
		}
		link->next = new LinkNode(value);
		this->length++;
		cout<< "在链表尾部插入新节点成功！！！！"<< endl;
	}

	// 删除尾部节点
	void popBack() {

		if (isEmpty()) {
			cout<< "链表为空！！！无法再删除节点！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode;
		while (link->next->next != NULL) {
			link = link->next;
		}
		LinkNode* del = link->next;
		free(del);
		link->next = NULL;
		this->length--;
		cout<< "链表尾部节点删除成功！！！！"<< endl;
	}

	// 在头部插入新的节点
	void pushFront(DataType value) {

		if (isFull()) {
			cout<< "链表已满！！！无法再插入新节点！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode;
		LinkNode* node = new LinkNode(value);
		node->next = link->next;
		link->next = node;
		this->length++;
		cout<< "在链表头部插入新节点成功！！！！"<< endl;

	}

	// 删除头部节点
	void popFront() {

		if (isEmpty()) {
			cout<< "链表为空！！！无法再删除节点！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode;
		LinkNode* node = link->next;
		link->next = node->next;
		free(node);
		this->length--;
		cout<< "链表头部节点删除成功！！！！"<< endl;
	}

	// 在指定位置插入节点
	void insertByIndex(DataType value, int index) {

		if (isFull()) {
			cout<< "链表已满！！！无法再插入新节点！！！！"<< endl;
			return;
		}

		if (index > this->length || index < 0) {
			cout<< "坐标超出范围！！！！无法插入！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode;
		LinkNode* node = new LinkNode(value);

		for (int i = 0; i < index; ++i) {
			link = link->next;
		}

		node->next = link->next;
		link->next = node;
		this->length++;
		cout<< "插入新节点成功！！！！"<< endl;
	}

	// 按位置删除节点
	void deleteByIndex(int index) {

		if (isEmpty()) {
			cout<< "链表为空！！！无法再删除节点！！！！"<< endl;
			return;
		}

		if (index >= this->length || index < 0) {
			cout<< "坐标超出范围！！！！无法删除！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode;

		for (int i = 0; i < index; ++i) {
			link = link->next;
		}
		LinkNode* node = link->next;
		link->next = link->next->next;
		free(node);
		this->length--;
		cout<< "节点删除成功！！！！"<< endl;

	}

	// 根据存储的值搜索节点
	LinkNode* findNodeByValue(DataType value) {
		if (isEmpty()) {
			cout<< "链表为空！！！无法查找！！！！"<< endl;
			return NULL;
		}

		LinkNode* link = this->HeadNode->next;
		while (link != NULL) {
			if (link->data == value)
				return link;
			link = link->next;
		}

		cout<< "节点不存在！！！结束查找！！！！"<< endl;
		return NULL;
	}

	// 根据位置搜索节点
	LinkNode* findNodeByIndex(int index) {

		if (isEmpty()) {
			cout<< "链表为空！！！无法查找！！！！"<< endl;
			return NULL;
		}

		if (index >= this->length || index < 0) {
			cout<< "坐标超出范围！！！！无法搜索！！！！"<< endl;
			return NULL;
		}

		LinkNode* link = this->HeadNode->next;

		for (int i = 0; i < index; ++i) {
			link = link->next;
		}
		return link;
	}

	// 清空链表
	void clearLink() {
		if (isEmpty()) {
			cout<< "链表已为空！！！无需再清空！！！！"<< endl;
			return;
		}
		LinkNode* link = this->HeadNode;
		while (link != NULL) {
			LinkNode* linkPtr = link;
			link = linkPtr;
			free(linkPtr);
		}
		this->length = 0;
		cout<< "链表已清空！！！！"<< endl;
	}

	// 倒序

	// 打印链表
	void printLink() {

		if (isEmpty()) {
			cout<< "链表为空！！！无需打印！！！！"<< endl;
			return;
		}

		LinkNode* link = this->HeadNode->next;
		while (link != NULL) {
			cout<< link->data<< "  ";
			link = link->next;
		}
		cout <<endl;
	}

};
