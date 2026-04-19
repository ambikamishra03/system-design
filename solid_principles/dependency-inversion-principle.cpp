#include<bits/stdc++.h>
using namespace std;

// class MySQLDb{
//   public:
//   void saveToSQL(string data){
//     cout<<"Executing SQL queries:INSERT INTO users VALUES { "<<data<<" }"<<endl;
//   }
// };

// class MyMongoDB{
//   public:
//   void saveToMongo(string data){
//     cout<<"Executing mongo db function: db.users.insert({ name "<<data<<" )}"<<endl;
//   }
// };

// // client - titly couple, if we want to add one more storage class we need to change client code also, breaking open close principle
// class userServices{
// private:
// MySQLDb sql;
// MyMongoDB mongo;
// public:
// void storeUserSQL(string user){
//     sql.saveToSQL(user);
// }
// void storeUserMongo(string user){
//     mongo.saveToMongo(user);
// }
// };
class Database{
public:
virtual void save(string data)=0;
};
// sql implementation - low level module
class MySQLDB: public Database {
public:
  void save (string data) override{
    cout<<"Executing SQL queries:INSERT INTO users VALUES { "<<data<<" }"<<endl;
  }
};
// mongo implementation - high level module
class MongoDB: public Database {
public:
  void save (string data) override{
    cout<<"Executing mongo db function: db.users.insert({ name "<<data<<" )}"<<endl;
  }
};

// high level module(loosely coupled)
class userServices{
    private:
    Database* db;  // dependency injection
    public:
    userServices(Database* database){
        db= database;
    }
    void storeUser(string user){
        db->save(user);
    }
};

int main(){
// userServices service;
// service.storeUserMongo("Ambika");
// service.storeUserSQL("Tanu");
MySQLDB sql;
MongoDB mongo;
userServices service1(&sql);
service1.storeUser("Ambika");

userServices service2(&mongo);
service2.storeUser("Tanu");
    return 0;
}