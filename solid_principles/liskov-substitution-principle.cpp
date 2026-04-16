#include<bits/stdc++.h>
using namespace std;


// using excetion throw
class Account{
public:
virtual void deposite(int amount) = 0;
virtual void withdraw(int amount) = 0;
};

class SavingsAccount:public Account{
 private:
 int savingAmount;
 public:
SavingsAccount(){
    savingAmount = 0;
}

 void deposite(int amount){
    savingAmount +=amount;
    cout<<"After deposited: "<<amount<<" amount."<<"Saving account have "<<savingAmount<<" INR!"<<endl;
 }
 void withdraw(int amount){
    if(savingAmount>=amount){
savingAmount -=amount;
    cout<<"Withdrawn: "<<amount<<" amount."<<"New amount after withdrawn to saving account is "<<savingAmount<<" INR!"<<endl;
    }else{
        cout<<"Insufficient Amount!"<<endl;
    }
    
 }
};

class CurrentAccount:public Account{
private:
 int currentAmount;
 public:
CurrentAccount(){
    currentAmount = 0;
}

 void deposite(int amount){
    currentAmount +=amount;
    cout<<"After deposited: "<<amount<<" amount."<<"Current account have "<<currentAmount<<" INR!"<<endl;
 }
 void withdraw(int amount){
    if(currentAmount>=amount){
currentAmount -=amount;
    cout<<"Withdrawn: "<<amount<<" amount."<<"New amount after withdrawn to Current account is "<<currentAmount<<" INR!"<<endl;
    }else{
        cout<<"Insufficient Amount!"<<endl;
    }
    
 }
};
class FixedDepositeAccount:public Account{
private:
 int fixedAmount;
 public:
FixedDepositeAccount(){
    fixedAmount = 0;
}

 void deposite(int amount){
    fixedAmount +=amount;
    cout<<"After deposited: "<<amount<<" amount."<<"Fixed account have "<<fixedAmount<<" INR!"<<endl;
 }
 void withdraw(int amount){
    throw logic_error("Withdrawal not allowed in fixed account!");
 }
};


class Client{
private:
vector<Account*>accounts;
public:
Client(vector<Account*>accounts){
this->accounts = accounts;
}
void processTransaction(){
    for(Account* acc:accounts){
        acc->deposite(1500);  // all accounts allow deposite
        try
        {
            acc->withdraw(1000);
        }
        catch(const logic_error& e)
        {
            std::cerr << e.what() << '\n';
        }
          
    }
}
};
int main(){
   vector<Account*>accounts;
   accounts.push_back(new SavingsAccount());
   accounts.push_back(new CurrentAccount());
   accounts.push_back(new FixedDepositeAccount());
   Client* bankClient = new Client(accounts);
   bankClient->processTransaction();
    return 0;
}