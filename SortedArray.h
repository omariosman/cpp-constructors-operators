#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <iostream>
#include <stdexcept>
#include <limits>
#include <climits>
#include <cstdint>

class SortedArray {
private:
    unsigned int* data;
    unsigned int size;
    unsigned int current_size;

    // helper function for sorting array
    void sortArray();

public:
    // constructors and destructor
    SortedArray();
    SortedArray(unsigned int size);
    SortedArray(const SortedArray& other);
    SortedArray(SortedArray&& other);
    ~SortedArray();

    // methods for updating and accessing array elements
    void setAt(unsigned int index, unsigned int value);
    unsigned int getAt(unsigned int index) const;

    // overloaded operators
    SortedArray& operator=(const SortedArray& other);
    SortedArray& operator=(SortedArray&& other);
    bool operator==(const SortedArray& other) const;
    unsigned int& operator[](unsigned int index);
    const unsigned int& operator[](unsigned int index) const;

    // stream output operator
    friend std::ostream& operator<<(std::ostream& os, const SortedArray& arr);
};

#endif 
