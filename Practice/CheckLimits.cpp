#include <iostream>
#include <climits>      // Library for integer data types
#include <limits>       // Library for floarting-point data types
using namespace std;

int main() {

    // integer data types
    cout << "\n\t\t********Integer Data Types********\n\n";
    cout << "The minimum limit of (char) data type : " << CHAR_MIN << endl;
    cout << "The maximum limit of (char) data type : " << CHAR_MAX << endl;
    cout << "The maximum limit of (unsigned char) data type : " << UCHAR_MAX << endl << endl;

    cout << "The minimum limit of (short) data type : " << SHRT_MIN << endl;
    cout << "The maximum limit of (short) data type : " << SHRT_MAX << endl;
    cout << "The maximum limit of (unsigned short) data type : " << USHRT_MAX << endl << endl;

    cout << "The minimum limit of (int) data type : " << INT_MIN << endl;
    cout << "The maximum limit of (int) data type : " << INT_MAX << endl;
    cout << "The maximum limit of (unsigned int) data type : " << UINT_MAX << endl << endl;

    cout << "The minimum limit of (long) data type : " << LONG_MIN << endl;
    cout << "The maximum limit of (long) data type : " << LONG_MAX << endl;
    cout << "The maximum limit of (unsigned long) data type : " << ULONG_MAX << endl << endl;

    cout << "The minimum limit of (long long) data type : " << LLONG_MIN << endl;    
    cout << "The maximum limit of (long long) data type : " << LLONG_MAX << endl;
    cout << "The maximum limit of (unsigned long long) data type : " << ULLONG_MAX << endl << endl;

    // floating-point data types
    cout << "\n\t\t********Floating-Point Data Types********\n\n";
    cout << "The minimum limit of (float) data type : " << numeric_limits<float>::min() << endl;
    cout << "The maximum limit of (float) data type : " << numeric_limits<float>::max() << endl << endl;    

    cout << "The minimum limit of (double) data type : " << numeric_limits<double>::min() << endl;
    cout << "The maximum limit of (double) data type : " << numeric_limits<double>::max() << endl << endl;

    cout << "The minimum limit of (long double) data type : " << numeric_limits<long double>::min() << endl;
    cout << "The maximum limit of (long double) data type : " << numeric_limits<long double>::max() << endl << endl;
    
    return 0;
}