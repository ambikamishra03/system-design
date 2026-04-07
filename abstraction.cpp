#include<iostream>
#include<string>

using namespace std;
class Car{
    public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void Break()=0;
    virtual void stopEngine()=0;
    virtual ~Car() {}
};

class SportsCar: public Car {
public:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;
  int currentGear;
  SportsCar(string a, string b){
    this->brand=a;
    this->model=b;
    isEngineOn=false;
    currentSpeed=0;
    currentGear=0;
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
    cout<<brand<<" "<<model<<" "<<": Shifted to gear : "<<currentGear<<endl;

  }
  void accelerate(){
     if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't accelerate!"<<endl;
    return;
    }
    currentSpeed +=20;
    cout<<brand<<" "<<model<<" "<<": Accelerating to : "<<currentSpeed<<endl;
  }
  void Break(){
    currentSpeed -=20;
    if(currentSpeed < 0) currentSpeed=0;
    cout<<brand<<" "<<model<<" "<<": Breaking! Speed is now : "<<currentSpeed<<"km/hr"<<endl; 
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
    Car* mycar= new SportsCar("ford", "mustang");
    mycar->startEngine();
    mycar->shiftGear(20);
    mycar->accelerate();
    mycar->shiftGear(10);
    mycar->accelerate();
    mycar->Break();
    mycar->stopEngine();
    return 0;
}