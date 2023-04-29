#include "SortedArray.h"
#include <stdexcept>
using namespace std;


// Default constructor
SortedArray::SortedArray() 
    : data(nullptr), size(0) {
    cout << "Inside default constructor\n";
}

//parametrized int constructor
SortedArray::SortedArray(unsigned int size) 
    : data(new unsigned int[size]), size(size), current_size(0) {
    fill_n(data, size, UINT_MAX);
    cout << "Inside parametrized constructor\n";
}

// Copy constructor
SortedArray::SortedArray(const SortedArray& other) 
    : size(other.size), current_size(other.current_size) {
        data = new unsigned int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Inside copy constructor\n";
}

// Move constructor
SortedArray::SortedArray(SortedArray&& other)  
    : data(other.data), size(other.size), current_size(other.current_size) {
        other.data = nullptr;
        other.size = 0;
        other.current_size = 0;
        cout << "Inside move constructor\n";

}

// Copy assignment operator
SortedArray& SortedArray::operator=(const SortedArray& other) {
    if (this != &other) {
        //delete data already there to clean up the mem before assigning new data to it
        delete[] data;
        size = other.size;
        current_size = other.current_size;
        data = new unsigned int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    cout << "Copy assignment operator\n";
    return *this;
}

// Move assignment operator
SortedArray& SortedArray::operator=(SortedArray&& other)  {
    if (this != &other) {
        delete[] data;
        size = other.size;
        current_size = other.current_size;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        other.current_size = 0;
    }
    cout << "Move assignment operator\n";
    return *this;
}

// Equality operator
//Do a comparison to make sure that the data members values (size and data) are identical .. if so return true .. otherwise return faslse
bool SortedArray::operator==(const SortedArray& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

// Index operator (const version)
const unsigned int& SortedArray::operator[](unsigned int index) const {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    cout << "const operator []\n";
    return data[index];
}

// Index operator (non-const version)
unsigned int& SortedArray::operator[](unsigned int index) {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    cout << "non-const operator []\n";
    return data[index];
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const SortedArray& obj) {
    os << "Total Capacity: " << obj.size << "\n";
    os << "Current Size: " << obj.current_size << "\n";
    os << "Data: ";
    for (int i = 0; i < obj.size; i++) {
        if (obj.data[i] != UINT_MAX){
            os << obj.data[i] << ' ';
        }
        
    }
    os << '\n';
    return os;
}

// Get the value at a specific index
unsigned int SortedArray::getAt(unsigned int index) const {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

// Set the value at a specific index
void SortedArray::setAt(unsigned int index, unsigned int value) {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    data[index] = value;
    current_size++;
    // Sort the array
    sortArray();
}

//Sort Array 
//This method will be called whenever a new element is inserted in the array
void SortedArray::sortArray()
{
    // Bubble sort
    bool swapped = true;
    int j = 0;
    unsigned int temp;
    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < size - j; i++)
        {
            if (data[i] > data[i + 1])
            {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                swapped = true;
            }
        }
    }
}



// Destructor
SortedArray::~SortedArray() {
    delete[] data;
    cout << "Destructor\n";
}
