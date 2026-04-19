#include<bits/stdc++.h>
using namespace std;

class MySQLDb{
  public:
  void saveToSQL(string data){
    cout<<"Executing SQL queries:INSERT INTO users VALUES { "<<data<<" }"<<endl;
  }
};

class MyMongoDB{
  public:
  void saveToMongo(string data){
    cout<<"Executing mongo db function: db.users.insert({ name "<<data<<" )}"<<endl;
  }
};

// client - titly couple, if we want to add one more storage class we need to change client code also, breaking open close principle
class userServices{
private:
MySQLDb sql;
MyMongoDB mongo;
public:
void storeUserSQL(string user){
    sql.saveToSQL(user);
}
void storeUserMongo(string user){
    mongo.saveToMongo(user);
}
};


int main(){
userServices service;
service.storeUserMongo("Ambika");
service.storeUserSQL("Tanu");
    return 0;
}