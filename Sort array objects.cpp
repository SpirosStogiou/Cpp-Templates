
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

class Circle {
    int RGB_1,RGB_2,RGB_3;
    double radius;
    double area;
public:
    int sum_of_RGB;

    Circle() { }

    Circle(int RGB_1,int RGB_2,int RGB_3,double radius) {
        this->RGB_1=RGB_1;
        this->RGB_2=RGB_2;
        this->RGB_3=RGB_3;
        this->radius=radius;
        this->area=3.14*radius*radius;
        sum_of_RGB=RGB_1+RGB_2+RGB_3;
    }

    void print() {
        cout <<"Area->"<<this->area<<" , Sum of RGB("<<RGB_1<<","<<RGB_2<<","<<RGB_3<<")->"<<sum_of_RGB<<endl;
    }


    bool operator> (Circle c) {
        bool boolean=false;
        if(this->area>c.area) {
            boolean=true;
        } else if(this->area==c.area) {

            if(this->sum_of_RGB<c.sum_of_RGB) {
                boolean=true;
            }


        }
        return boolean;
    }

    bool operator< (Circle c) {
        bool boolean=false;
        if(this->area<c.area) {
            boolean=true;
        } else if(this->area==c.area) {
            if(this->sum_of_RGB>c.sum_of_RGB) {
                boolean=true;
            }


        }
        return boolean;
    }


};


class Rectangle {
    int RGB_1,RGB_2,RGB_3;
    double radius;
    double side_1;
    double side_2;
    double area;
public:
    int sum_of_RGB;

    Rectangle() {}
    Rectangle(int RGB_1,int RGB_2,int RGB_3,double side_1,double side_2) {
        this->RGB_1=RGB_1;
        this->RGB_2=RGB_2;
        this->RGB_3=RGB_3;
        this->side_1=side_1;
        this->side_2=side_2;
        this->area=side_1*side_2;
        this->sum_of_RGB=RGB_1+RGB_2+RGB_3;
    }

    void print() {
        cout <<"Area->"<<this->area<<" , Sum of RGB("<<RGB_1<<","<<RGB_2<<","<<RGB_3<<")->"<<sum_of_RGB<<endl;
    }


    bool operator> (Rectangle r) {
        bool boolean=false;
        if(this->area>r.area) {
            boolean=true;
        } else if(this->area==r.area) {
            if(this->sum_of_RGB<r.sum_of_RGB) {
                boolean=true;
            }


        }
        return boolean;
    }


    bool operator< (Rectangle r) {
        bool boolean=false;
        if(this->area<r.area) {
            boolean=true;
        } else if(this->area==r.area) {
            if(this->sum_of_RGB>r.sum_of_RGB) {
                boolean=true;
            }


        }
        return boolean;
    }


};

template <typename T>
T mySort(T a[],int n, char ch) {

    if(ch == '<') {
        cout<<"Ascending";
        for (int i = 0; i < n - 1; i++)
            for (int j = n - 1; i < j; j--)
                if (a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);

    } else if(ch == '>') {
        cout<<"Descending";
        for (int i = 0; i <n-1; i++)
            for (int j =n - 1; i < j; j--)
                if (a[j] > a[j - 1])
                    swap(a[j],a[j - 1] );

    }


}




int main() {


    srand(time(0));
    float randFloatArray[10];


    for(int i=0; i<10; i++)
        randFloatArray[i]=(1+float(rand())/float((RAND_MAX)) * 100.0);
    cout<<"\nElements of the unsort float array::"<<endl;
    for(int i=0; i<10; i++)
        cout<<"Elements no "<<i+1<<"::"<<randFloatArray[i]<<endl;

    mySort<float>(randFloatArray, 10, '<');
    cout << " Sorted array : "<< endl;
    for (int i = 0; i <10; i++)
        cout<<randFloatArray[i]<<endl;
    cout << endl;

    mySort<float>(randFloatArray, 10, '>');

    cout << " Sorted array : "<< endl;
    for (int i = 0; i <10; i++)
        cout<<randFloatArray[i]<<endl;
    cout << endl;

     cout << "---------------------------------------------------"<< endl;


    cout << "Circle objects unsort array: "<< endl;
    Circle* randCircleArray=new Circle[10];

    for(int i=0; i<8; i++) {
        double a=(1+double(rand())/double((RAND_MAX)) * 10.0);
        Circle c(rand()%256,rand()%256,rand()%256,a);
        randCircleArray[i]=c;
    }

    Circle c1(rand()%256,rand()%256,rand()%256,3.13);
    Circle c2(rand()%256,rand()%256,rand()%256,3.13);

    randCircleArray[8]=c1;
    randCircleArray[9]=c2;

    for (int i = 0; i <10; i++)
        randCircleArray[i].print();

    cout << endl;

    mySort<Circle>(randCircleArray, 10,'<');


    cout << " Sorted array : "<< endl;
    for (int i = 0; i <10; i++)
        randCircleArray[i].print();
    cout << endl;

    mySort<Circle>(randCircleArray, 10,'>');
    cout << " Sorted array : "<< endl;
    for (int i = 0; i <10; i++)
        randCircleArray[i].print();
    cout << endl;
    cout << "---------------------------------------------------"<< endl;

    cout << "Rectangle objects unsort array: "<< endl;
    Rectangle* randRectangleArray=new Rectangle[10];

    for(int i=0; i<8; i++) {

        double a=(1+double(rand())/double((RAND_MAX)) * 10.0);
        double b=(1+double(rand())/double((RAND_MAX)) * 10.0);
        Rectangle r(rand()%256,rand()%256,rand()%256,a,b);
        randRectangleArray[i]=r;
    }

    Rectangle r1(rand()%256,rand()%256,rand()%256,5.13,6.7);
    Rectangle r2(rand()%256,rand()%256,rand()%256,5.13,6.7);

    randRectangleArray[8]=r1;
    randRectangleArray[9]=r2;


    for (int i = 0; i <10; i++)
        randRectangleArray[i].print();

    cout << endl;

    mySort<Rectangle>(randRectangleArray, 10,'<');

    cout << " Sorted array : "<< endl;
    for (int i = 0; i <10; i++)
        randRectangleArray[i].print();
    cout << endl;

    mySort<Rectangle>(randRectangleArray, 10,'>');

    cout << " Sorted array : "<< endl;
    for (int i = 0; i <10; i++)
        randRectangleArray[i].print();
    cout << endl;

}
