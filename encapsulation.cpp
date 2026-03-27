#include<iostream>
#include<string>

using namespace std;


// data and methods encapsulated in a class
class SportsCar {
private:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;
  int currentGear;
  string tyre;
  public:
  SportsCar(string a, string b){
    this->brand=a;
    this->model=b;
    isEngineOn=false;
    currentSpeed=0;
    currentGear=0;
    tyre="MRF";
  }


  // getters and setters 
int getCurrentSpeed() {
return this->currentSpeed;
}
int getCurrentGear() {
return this->currentGear;
}
string getTyre(){
  return this->tyre;
}

void setTyre(string tyre){
  this->tyre=tyre;
}
  void startEngine(){
   isEngineOn=true;
   cout<<brand<<" "<<model<<" "<<": Engine starts!"<<endl;
  }
  void shiftGear(int gear){
    if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't shift gear!"<<endl;
    return;
    }
    currentGear=gear;
    cout<<brand<<" "<<model<<" "<<": Shifted to gear - "<<currentGear<<endl;

  }
  void accelerate(){
     if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't accelerate!"<<endl;
    return;
    }
    currentSpeed +=20;
    cout<<brand<<" "<<model<<" "<<": Accelerating to -"<<currentSpeed<<endl;
  }
  void Break(){
    currentSpeed -=20;
    if(currentSpeed < 0) currentSpeed=0;
    cout<<brand<<" "<<model<<" "<<": Breaking! Speed is now -"<<currentSpeed<<"km/hr"<<endl; 
  }
  void stopEngine(){
    isEngineOn=false;
    currentSpeed=0;
    currentGear=0;
    cout<<brand<<" "<<model<<" "<<": Engine turned off!"<<endl; 

  }
};

int main() {

    // object creation
    SportsCar* mycar= new SportsCar("ford", "mustang");
    mycar->startEngine();
    mycar->shiftGear(20);
    mycar->accelerate();
    mycar->shiftGear(30);
    mycar->accelerate();
    mycar->Break();
    mycar->stopEngine();

    // prohibited - we cant change this so make all data to private to ensure data security.
    // mycar->currentSpeed = 400;
    // cout<<"current speed is "<<mycar<<endl;
    cout<<mycar->getCurrentSpeed()<<endl;
    delete mycar;
    return 0;
}