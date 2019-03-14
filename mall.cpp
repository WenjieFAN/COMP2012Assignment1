//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must NOT be implemented here

Mall::Mall(string name, string address) {

	this->name = name;
	this->address = address;

	shopHead = nullptr;
}

Mall::Mall(Mall& another) {

	setName(another.getName());
	setAddress(another.getAddress());
	this->shopHead = duplicateShopLinkedList(another.shopHead);

}

Mall::~Mall() {

	Node* node = shopHead;
	Node* nodeNext = node->getNext();
	while(node != nullptr){
		delete node;
		node = nullptr;
		node = nodeNext;
		if(node != nullptr)
		nodeNext = node->getNext();
	}

	delete node;
	node = nullptr;
	delete nodeNext;
	nodeNext = nullptr;

}

void Mall::setName(string name) {
	this->name = name;
}

void Mall::setAddress(string address) {
	this->address = address;
}

string Mall::getName() {
	return name;
}

string Mall::getAddress() {
	return address;
}

bool Mall::addShop(string name, int shopNumber) {

	if(shopHead == nullptr) {
	Shop* ss = new Shop(name, shopNumber);
	Node* N = new Node(ss, nullptr);
	shopHead = N;
		return true;
	}

	Node* node = shopHead;

	for(; node != nullptr; node = node->getNext()){
		if(node->getShop()->getShopNumber() == shopNumber) {
			return false;
		}
		if(node->getNext() == nullptr) break;
	}

	Shop* ss = new Shop(name, shopNumber);
	Node* N = new Node(ss, nullptr);

	node->setNext(N);

	return true;
}

bool Mall::removeShop(int shopNumber) {
	//cout << "called\n";

	Node* node = shopHead;

	// continue if (not find that number && it's not ass)
	while( node->getShop()->getShopNumber() != shopNumber){
	if(node->getNext() == nullptr){
		return false;
	}
	node = node->getNext();
	}
	//cout << "fuck\n";
	//if it is head
	if(node->getShop()->getShopNumber() == shopHead->getShop()->getShopNumber()) {
		shopHead = shopHead->getNext();
		delete node;
		node = nullptr;
		return true;
	}

	//if not
	node = shopHead;
	//cout << "node->getNext()->getShop()->getShopNumber() = " << node->getNext()->getShop()->getShopNumber() << endl;
	for(; node->getNext()->getShop()->getShopNumber() != shopNumber; node = node->getNext());
	Node *node2 = node->getNext();
	node->setNext(node->getNext()->getNext());

	//delete
	//node2->setNext(nullptr);
	//delete node2->getShop();
	//node2->setShop(nullptr);
	delete node2;
	node2 = nullptr;
	return true;

}

Shop* Mall::getShop(int shopNumber){
	Node* node = shopHead;
	while(node != nullptr){
		if(node->getShop()->getShopNumber() == shopNumber)
			return node->getShop();
		node = node->getNext();
	}
	return nullptr;
}
