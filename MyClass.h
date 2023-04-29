#ifndef MyClass_H
#define MyClass_H

#include <iostream>
class MyClass {

public:
    MyClass();
    MyClass( int );
    MyClass(const MyClass& );
    MyClass(MyClass&& );
    void setAt( int ,  int );
    int getAt( int ) const;
    MyClass& operator=(const MyClass& );
    MyClass& operator=(MyClass&& );
    bool operator==(const MyClass& ) const;
     int& operator[]( int );
    const  int& operator[]( int) const;
    friend std::ostream& operator<<(std::ostream&, const MyClass&);
    ~MyClass();
private:
     int* data;
     int size;

    void quickSort(int, int);

};

#endif 
