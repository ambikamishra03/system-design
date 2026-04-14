#include<bits/stdc++.h>
using namespace std;

class Product{
public:
 string name;
 double price;

   Product(string name,double price){
     this->name = name;
     this->price = price;
   }
};
class ShoppingCart{
    private:
    vector<Product*> products;
    public:
    void addProduct(Product* p){
     products.push_back(p);
    }
 const vector<Product*> & getProducts(){
    return products;
 }
 double calculateTotal(){
    double total=0;
    for(auto p:products){
        total +=p->price;
    }
    return total;
 }
};
class cartInvoicePrinter{
   private:
   ShoppingCart* cart;
public:
 cartInvoicePrinter(ShoppingCart* cart){
   this->cart=cart;
 }

 void printInvoice(){
    cout<<"Shopping Cart Invoiice:"<<endl;
    for(auto p:cart->getProducts()){
        cout<<p->name<<" - $"<<p->price<<endl;
    }
    cout<<"Total: $"<<cart->calculateTotal()<<endl;
 }
};

class shoppingCartStorage{
   private:
   ShoppingCart* cart;
   public:
   shoppingCartStorage(ShoppingCart* cart){
    this->cart = cart;
   }
   void saveToDB(){
    cout<<"Saving shopping cart to database..."<<endl;
   }
};


int main(){
 ShoppingCart* cart = new ShoppingCart();

 cart->addProduct(new Product("laptop",50000));
 cart->addProduct(new Product("mouse",3000));

 shoppingCartStorage* storage = new shoppingCartStorage(cart);
 storage->saveToDB();
 cartInvoicePrinter* printer = new cartInvoicePrinter(cart);
 printer->printInvoice();
 return 0;
}