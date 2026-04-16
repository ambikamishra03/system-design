#include<bits/stdc++.h>
using namespace std;

class Product{
 public:
 string name;
 double price;
 Product(string name,double price){
    this->name=name;
    this->price=price;
 }
};

class ShoppingCart{
private:
vector<Product*>products;
public:
void addProduct(Product* p){
 products.push_back(p);
}
const vector<Product*>& getProducts(){
    return products;
}
double calculateTotal(){
    double total;
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

class DBPersistent{
   private:
   ShoppingCart* cart;
   public:
   virtual void save(ShoppingCart* cart) = 0;
};

class SQLPersistence: public DBPersistent{
public:
void save(ShoppingCart* cart) override {
    cout<<"Saving to SQL"<<endl;
}
};

class MongoPersistence: public DBPersistent{
public:
void save(ShoppingCart* cart) override {
    cout<<"Saving to MongoDB"<<endl;
}
};

class filePersistence: public DBPersistent{
public:
void save(ShoppingCart* cart) override {
    cout<<"Saving to file"<<endl;
}
};

int main(){

ShoppingCart* cart = new ShoppingCart();

 cart->addProduct(new Product("laptop",50000));
 cart->addProduct(new Product("mouse",3000));
 SQLPersistence* sql = new SQLPersistence();
 sql->save(cart);
 MongoPersistence* mongo = new MongoPersistence();
 mongo->save(cart);
  filePersistence* file = new filePersistence();
 file->save(cart);
 cartInvoicePrinter* printer = new cartInvoicePrinter(cart);
 printer->printInvoice();
 return 0;
}