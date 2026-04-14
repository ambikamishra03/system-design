#include<iostream>
#include<string>

using namespace std;
class Car {
protected:
string brand;
string model;
bool isEngineOn;
int currSpeed;
public:
Car(string b, string m){
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currSpeed = 0;
}
void startEngine(){
   isEngineOn=true;
   cout<<brand<<" "<<model<<" "<<": Engine starts!"<<endl;
  }
  void stopEngine(){
    isEngineOn=false;
    currSpeed=0;
    cout<<brand<<" "<<model<<" "<<": Engine turned off!"<<endl; 

  }
  
  virtual void accelerate() = 0;
  virtual void Break() = 0;
  virtual ~Car() {}
};

class manualCar: public Car {
private:
int currGear = 0;
public:
manualCar(string b, string m):Car(b,m){
    currGear = 0;
}
  void shiftGear(int gear){
    if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't shift gear!"<<endl;
    return;
    }
    currGear=gear;
    cout<<brand<<" "<<model<<" "<<": Shifted to gear : "<<currGear<<endl;

  }
  // method overriding - dynamic polymorphism 
  void accelerate(){
     if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't accelerate!"<<endl;
    return;
    }
    currSpeed +=20;
    cout<<brand<<" "<<model<<" "<<": Accelerating to : "<<currSpeed<<endl;
  }

  // method overloading - static polymorphism
  void accelerate(int speed) {
    if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't accelerate!"<<endl;
    return;
    }
    currSpeed +=speed;
    cout<<brand<<" "<<model<<" "<<": Accelerating to : "<<currSpeed<<endl;
  }

  // dynamic polymorphism
  void Break(){
    currSpeed -=20;
    if(currSpeed < 0) currSpeed=0;
    cout<<brand<<" "<<model<<" "<<": Breaking! Speed is now : "<<currSpeed<<"km/hr"<<endl; 
  }
};

class electricCar: public Car {
    private:
    int batterylevel;

    public:
    electricCar(string b, string m):Car(b,m){
        batterylevel = 100;
    }
    void chargeBattery(){
    batterylevel=100;
    cout<<brand<<" "<<model<<" "<<": Battery fully charged ! "<<endl;
    }

    // dynamic polymorphism 
    void accelerate(){
     if(!isEngineOn){
    cout<<brand<<" "<<model<<" "<<": Engine is off, can't accelerate!"<<endl;
    return;
    }
     if(batterylevel<=0){
    cout<<brand<<" "<<model<<" "<<":Battery dead, can't accelerate!"<<endl;
    return;
    }
    currSpeed +=15;
    batterylevel +=10;
    cout<<brand<<" "<<model<<" "<<": Accelerating to : "<<currSpeed<<" and battery at : "<<batterylevel<<endl;
  }
  void Break(){
    currSpeed -=15;
    if(currSpeed < 0) currSpeed=0;
    cout<<brand<<" "<<model<<" "<<": Breaking! Speed is now : "<<currSpeed<<"km/hr"<<endl; 
  }
};

int main(){
    manualCar* mymanualCar = new manualCar("suzuki","waganR");
    mymanualCar->startEngine();
    mymanualCar->shiftGear(1);
    mymanualCar->accelerate();
     mymanualCar->accelerate(50);
    mymanualCar->Break();
    mymanualCar->stopEngine();

    cout<<"------------------------------------------------------------"<<endl;
    electricCar* myElectricCar= new electricCar("suzuki","waganR");
    myElectricCar->startEngine();
    myElectricCar->chargeBattery();
    myElectricCar->accelerate();
    myElectricCar->Break();
    myElectricCar->stopEngine();

    delete mymanualCar;
    delete myElectricCar;
    return 0;
}