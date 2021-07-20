#include <iostream>
using namespace std;


template <typename T>
class ComplexNumber {
private:
    T x;
    T i;

public:
    ComplexNumber(T x,T i) {
        this->x=x;
        this->i=i;
        cout << "Real part: " << this->x<< endl;
        cout << "Imaginary part: " <<  this->i << endl;

    }


    void addComplexNumbers(ComplexNumber<T> cn2) {
        T RealSum;
        T ImaginarySum;

        RealSum=this->x+cn2.x;
        ImaginarySum=this->i+cn2.i;
        if(ImaginarySum<0)
        cout<<"The value after add is: "<<RealSum<<" + ("<<ImaginarySum<<"i) "<< endl;
        else cout<<"The value after add is: "<<RealSum<<" + "<<ImaginarySum<<"i "<< endl;

    }
    void  subComplexNumbers(ComplexNumber<T> cn2) {
        T RealSub;
        T ImaginarySub;

        RealSub = this->x - cn2.x;
        ImaginarySub = this->i - cn2.i;

        if(ImaginarySub<0)
        cout<<"The value after subtract is: "<<RealSub<<" + ("<<ImaginarySub<<"i) "<< endl;
        else cout<<"The value after subtract is: "<<RealSub<<" + ("<<ImaginarySub<<"i) "<< endl;
    }

    void multiComplexNumbers(ComplexNumber<T> cn2) {

        T RealMulti;
        T ImaginaryMulti;

        RealMulti = this->x * cn2.x - this->i * cn2.i;
        ImaginaryMulti = this->x * cn2.i + this->i * cn2.x;

        if(ImaginaryMulti<0)
        cout<<"The value after multiplication is: "<<RealMulti<<" + ("<<ImaginaryMulti<<"i) "<< endl;
        else cout<<"The value after multiplication is: "<<RealMulti<<" + "<<ImaginaryMulti<<"i "<< endl;

    }

};

template<>
class ComplexNumber<char> {
public:
    ComplexNumber(char x,char i) {
        cout<<"\n";
        cout << x <<" and "<<i <<" are characters not a complex number!!!" << endl;
    }
};


int main() {

    cout<<"For z1 , z2 : \n"<<endl;

    cout<<"z1 has: "<<endl;
    ComplexNumber <int> z1(5,2);

    cout<<"z2 has: "<<endl;
    ComplexNumber <int> z2(3,4);

    cout<<endl;
    z1.addComplexNumbers(z2);
    z1.subComplexNumbers(z2);
    z1.multiComplexNumbers(z2);


    cout<<"\nFor z3 , z4 :"<<endl;

    cout<<"z3 has: "<<endl;
    ComplexNumber <double> z3(7.2,-3.1);

    cout<<"z4 has: "<<endl;
    ComplexNumber <double> z4(2.3,1.0);

    z3.addComplexNumbers(z4);
    z3.subComplexNumbers(z4);
    z3.multiComplexNumbers(z4);



    ComplexNumber <char> cN1('d','f');



    return 0;
}
