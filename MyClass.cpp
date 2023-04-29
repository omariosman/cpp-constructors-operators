#include "MyClass.h"
using namespace std;

void MyClass::setAt(int index, int value) {
    data[index] = value;
    quickSort(0, size);
}
 int MyClass::getAt(int index) const {
    return data[index];
}

void MyClass::quickSort(int left, int right)
{
    if (left < right)
    {
        int pivot = data[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j++)
        {
            if (data[j] <= pivot)
            {
                i++;
                swap(data[i], data[j]);
            }
        }
        swap(data[i + 1], data[right]);
        int partitionIndex = i + 1;
        quickSort(left, partitionIndex - 1);
        quickSort(partitionIndex + 1, right);
    }
}

MyClass::MyClass() {
    data = nullptr;
    size = 0;
}

MyClass::MyClass(int size) {
    size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 4294967295;
    }
}

MyClass::MyClass(const MyClass& arr) 
      {
        size = arr.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr.data[i];
        }
}

MyClass::MyClass(MyClass&& arr) {
        data = arr.data;
        size = arr.size; 
        arr.data = nullptr;
        arr.size = 0;
}

MyClass& MyClass::operator=(const MyClass& arr) {
    delete[] data;
    size = arr.size;
    data = new  int[size];
    for (int i = 0; i < size; i++) {
        data[i] = arr.data[i];
    }
    return *this;
}

MyClass& MyClass::operator=(MyClass&& arr)  {
    delete[] data;
    size = arr.size;
    data = arr.data;
    arr.data = nullptr;
    arr.size = 0;
    return *this;
}

bool MyClass::operator==(const MyClass& arr) const {
    if (size != arr.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != arr.data[i]) {
            return false;
        }
    }
    return true;
}

const  int& MyClass::operator[](int index) const {
    return data[index];
}

 int& MyClass::operator[](int index) {
    return data[index];
}

std::ostream& operator<<(std::ostream& os, const MyClass& arr) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.data[i] != 4294967295){
            os << arr.data[i] << '\t';
        }
    }
    return os;
}

MyClass::~MyClass() {delete[] data;}

