//Submit this file
#include "product.h"
//You are NOT allowed to include any additional library
Product::Product(string name, ProductType type, float price) {
	this->quantity = 0;
	this->name = name;
	this->price = price;
	this->type = type;
}

string Product::getName() {
	return name;
}

ProductType Product::getType() {
	return type;
}

float Product::getPrice() {
	return price;
}

int Product::getQuantity() {
	return quantity;
}

bool Product::setPrice(float price) {
	if(price > 0){
		this->price = price;
		return true;
	}else{
		return false;
	}
}

bool Product::setQuantity(int quantity) {
	if(quantity >= 0){
		this->quantity = quantity;
		return true;
	}else{
		return false;
	}
}

int Product::compare(Product* other) {
	if((other->getPrice() - price) > 0.01)
		return -1;

	if((other->getPrice() - price) < -0.01)
		return 1;

	int i = 0;
	while(true){
		if(other->name[i] > name[i])
			return -1;

		if(other->name[i] < name[i])
			return 1;

		i++;
	}

	return 0;
}
