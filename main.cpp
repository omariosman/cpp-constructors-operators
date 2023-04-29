#include "SortedArray.h"
#include <stdexcept>
using namespace std;

//A function that gets a SortedArray object as an argument to test copy constructor
void TestCopyConstructor(SortedArray sa){
    cout << "Testing copy constructor\n";
}

//A function that gets a SortedArray object as an argument to test copy constructor
void TestMoveConstructor(SortedArray *sa){
    cout << "Testing move constructor\n";
}

int main(){
    //Test default constructor
    SortedArray *sa3 = new SortedArray();

    //Test int parameterized constructor
    SortedArray sa(10);

    //Test copy constructor - send SortedArray object by value to test copy constructor
    TestCopyConstructor(sa);

    //Test move constructor
    TestMoveConstructor(new SortedArray(10));

    //Test setAt method

    sa.setAt(0, 1);
    cout << sa;

    
    //Test Sort Array method
    //I created a new Sorted Array objects and populated it with unsorted numbers then printed to check that the numbers are sorted just fine
    SortedArray sa2(10);
    sa2.setAt(0, 3);
    sa2.setAt(1, 2);
    sa2.setAt(2, 5);
    cout << sa2;

    //Test getAt method
    cout << sa2.getAt(1) << "\n";

    //Test copy assignment operator
    SortedArray sa4;
    sa4 = sa2;

    //Test move assignment operator
    SortedArray sa5;
    sa5 = SortedArray(10);

    //Test index operator const version
    SortedArray sa6(10);
    sa6.setAt(0, 30);
    cout << sa6[0] << "\n";

    //Test index operator non-const version
    SortedArray const sa7(10);
    cout << sa7[0] << "\n";

    //Test equality operator - return true
    SortedArray sa8(1); 
    SortedArray sa9(1);
    sa8.setAt(0, 5);
    sa9.setAt(0, 5);
    bool flag = sa8 == sa9;
    cout << flag << "\n";

    //Test equality operator - return false
    SortedArray sa10(1); 
    SortedArray sa11(1);
    sa10.setAt(0, 6);
    sa11.setAt(0, 5);
    bool flag2 = sa10 == sa11;
    cout << flag2 << "\n";

    //Test stream output operator
    SortedArray sa12(3);
    sa12.setAt(0, 6); sa12.setAt(1, 8); sa12.setAt(2, 12); 
    cout << sa12 << "\n";

    //Test error reporting
    //Index out of range - setAt wrong index
    try{
        SortedArray sa13(1);
        sa13.setAt(2,8);
    } catch(out_of_range& e) {
        cout << e.what();
    }

    //Index out of range - getAt wrong index
    try{
        SortedArray sa13(1);
        sa13.setAt(0,8);
        sa13.getAt(1);
    } catch(out_of_range& e) {
        cout << e.what();
    }

    //Test destructor - It should be called on its own when the program terminates for any objects left in the scope of this main function

    return 0;
}