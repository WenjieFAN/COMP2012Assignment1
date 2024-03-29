//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must be implemented here
//NOTE: recursion is a requirement - NO loops of any kind is allowed in this file
//a checking needs to be done by you after you finish your code, please refer to the 4th item in "Additional notes" on the webpage

Node* Mall::duplicateShopLinkedList(Node* node) {
	if(node == nullptr)
		return nullptr;
	Shop* s = new Shop(*node->getShop());

	Node* noob = new Node(s, duplicateShopLinkedList(node->getNext()));
	s = nullptr;
	return noob;
}
