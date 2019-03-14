//Submit this file
#include "shop.h"
//You are NOT allowed to include any additional library

Shop::Shop(string name, int shopNumber) {
         this->name = "";
         this->shopNumber = 0;
         productCount = 0;
         products = nullptr;

         this->name = name;
         this->shopNumber = shopNumber;
}

Shop::Shop(Shop& another) {

         name = another.name;
         shopNumber = another.shopNumber;
         productCount = another.productCount;
         products = new Product*[productCount];
         for(int i = 0; i < productCount; i++) {
                   products[i] = new Product(another.products[i]->getName(), another.products[i]->getType(),another.products[i]->getPrice());
                   products[i]->setQuantity(another.products[i]->getQuantity());
         }

}

Shop::~Shop() {
         for (int i = 0; i < productCount; i++) {
                   delete products[i];
                   products[i] = nullptr;
         }
         delete[] products;
         products = nullptr;
}

string Shop::getName() {
         return name;
}

int Shop::getShopNumber() {
         return shopNumber;
}

void Shop::setName(string name) {
         this->name = name;
}

void Shop::setShopNumber(int shopNumber) {
         this->shopNumber = shopNumber;
}


void Shop::addProduct(string name, ProductType type, float price, int quantityToAdd) {
         //check whether it has existed
         for(int i = 0; i < productCount; i++) {
                   if(products[i]->getName() == name){
                            products[i]->setQuantity(products[i]->getQuantity() + quantityToAdd);
                            return;
                   }
         }
         //cout << productCount;
         //first
         if(productCount == 0) {
                   products = new Product *[1];
                   products[0] = new Product(name, type, price);
                   products[0]->setQuantity(quantityToAdd);
                   productCount = 1;
                   return;
         }

         Product** cpyOfproducts = products;
         productCount++;
         products = new Product *[productCount];

         Product* p = new Product(name, type, price);
         p->setQuantity(quantityToAdd);

         //cout << p->compare(cpyOfproducts[0]);

         int i = 0;
         while(i < productCount-1 && p->compare(cpyOfproducts[i]) == 1){
                 products[i] = new Product(cpyOfproducts[i]->getName(), cpyOfproducts[i]->getType(), cpyOfproducts[i]->getPrice());
                   products[i]->setQuantity(cpyOfproducts[i]->getQuantity());
                   i++;
         }
         products[i] = p;
         while(i + 1 < productCount){
                   products[i+1] = new Product(cpyOfproducts[i]->getName(), cpyOfproducts[i]->getType(), cpyOfproducts[i]->getPrice());
                   products[i+1]->setQuantity(cpyOfproducts[i]->getQuantity());
                   i++;
         }

         for (int i = 0; i < productCount-1; i++) {
                   delete cpyOfproducts[i];
                   cpyOfproducts[i] = nullptr;
         }
         delete[] cpyOfproducts;
         cpyOfproducts = nullptr;

         return;
}


bool Shop::removeProduct(string name, int quantityToRemove) {
         if(quantityToRemove <= 0) return false;

         int i = 0;
         for(i; i < productCount; i++) {
                   if(products[i]->getName() != name){
                            if(i + 1 == productCount) return false;
                            continue;
                   }
                   break;
         }

         if(products[i]->getQuantity() < quantityToRemove) return false;

         products[i]->setQuantity(products[i]->getQuantity() - quantityToRemove);
         if(products[i]->getQuantity() != 0) return true;

         //to delete this product
         //fuck you

         Product** noob = products;
         productCount--;
         products = new Product* [productCount];
         for(int j = 0; j < i; j++){
                   products[j] = noob[j];
         }

         delete noob[i];
         noob[i] = nullptr;

         for(int j = i; j < productCount; j++){
                   products[j] = noob[j+1];
         }



         delete [] noob;
         noob = nullptr;
         return true;
}

bool Shop::updatePrice(string name, float price) {
         int i = 0;
         for(i; i < productCount; i++) {
                   if(products[i]->getName() != name){
                            if(i + 1 == productCount) return false;
                            continue;
                   }
                   break;
         }

         if(      !products[i]->setPrice(price)) return false;

         //sort
         //basic idea is to compare it from head to back
         int q = products[i]->getQuantity();
         ProductType t = products[i]->getType();
         removeProduct(name, products[i]->getQuantity());
         addProduct(name, t, price, q);
         return true;

}

Product* Shop::findProduct(string name) {
         int i = 0;
         while( i < productCount) {
                   if(products[i]->getName() == name) {
                            return products[i];
                   }
         }
         return nullptr;
}
