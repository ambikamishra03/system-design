#include<bits/stdc++.h>
using namespace std;


// breaks interface segregation principle 
// class Shape{
// public:
// virtual void area()=0;
// virtual void volume() = 0;
// };

// class Square:public Shape{
// private:
//    int side;
// public:
// Square(int side){
//     this->side = side;
// }
// void area(){
//    if(side >0){
//     cout<<"The area of square is - "<<(side*side)<<"meter-square."<<endl;
//    }
// }
// void volume(){
//     throw logic_error("volume not defined for square.");
// }
// };

// class Rectangle:public Shape{
// private:
//    int length;
//    int breadth;
// public:
// Rectangle(int length,int breadth){
//     this->length = length;
//     this->breadth = breadth;
// }
// void area(){
//    if(length >0 && breadth>0){
//     cout<<"The area of rectangle is - "<<(length*breadth)<<"meter-square."<<endl;
//    }
// }
// void volume(){
//     throw logic_error("volume not defined for rectangle.");
// }
// };

// class Cube:public Shape{
// private:
//    int side;
// public:
// Cube(int side){
//     this->side = side;
// }
// void area(){
//    if(side >0){
//     cout<<"The area of Cube is - "<<(6*side*side)<<"meter-square."<<endl;
//    }
// }
// void volume(){
//    if(side >0){
//     cout<<"The volume of Cube is - "<<(side*side*side)<<"meter-cube."<<endl;
//    }
// }
// };

class TwoDshape{
public:
    virtual void area()=0;
};
class ThreeDshape{
public:
    virtual void area()=0;
    virtual void volume() = 0;
};

class Square:public TwoDshape{
private:
   int side;
public:
Square(int side){
    this->side = side;
}
void area(){
   if(side >0){
    cout<<"The area of square is - "<<(side*side)<<"meter-square."<<endl;
   }
}

};

class Rectangle:public TwoDshape{
private:
   int length;
   int breadth;
public:
Rectangle(int length,int breadth){
    this->length = length;
    this->breadth = breadth;
}
void area(){
   if(length >0 && breadth>0){
    cout<<"The area of rectangle is - "<<(length*breadth)<<"meter-square."<<endl;
   }
}

};

class Cube:public ThreeDshape{
private:
   int side;
public:
Cube(int side){
    this->side = side;
}
void area(){
   if(side >0){
    cout<<"The area of Cube is - "<<(6*side*side)<<"meter-square."<<endl;
   }
}
void volume(){
   if(side >0){
    cout<<"The volume of Cube is - "<<(side*side*side)<<"meter-cube."<<endl;
   }
}
};

int main(){
    Square* sq= new Square(3);
    sq->area();
    Rectangle* rc= new Rectangle(3,2);
    rc->area();
    Cube* cb= new Cube(3);
    cb->area();
    cb->volume();
    return 0;
}
