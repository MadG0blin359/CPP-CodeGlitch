#include <iostream>
using namespace std;

class Complex {
    private:
    int real;
    int imag;

    public:

    // Default Parameterized Constructor
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Friend function of type Complex
    friend Complex addComplex(Complex &c1, Complex &c2);

    // Function to display the complex number
    void display() {
        cout << "\nComplex number : " << real << " + " << imag << "i" << endl;
    }
};

// Friend function definition
Complex addComplex(Complex &c1, Complex &c2) {
    Complex result;

    result.real = c1.real + c2.real;        // Adding the real part
    result.imag = c1.imag + c2.imag;        // Adding the imaginary part

    return result;      // Returning the result object
}

int main() {

    Complex obj1(5, 8), obj2(3, 4);

    // Getting the result object returning from the function
    Complex result = addComplex(obj1, obj2);
    result.display();   // Displaying the sum

    return 0;
}