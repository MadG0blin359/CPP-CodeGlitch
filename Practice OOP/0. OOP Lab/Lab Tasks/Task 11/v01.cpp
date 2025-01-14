#include <iostream>
#include <string>
using namespace std;

// Grand Parent
class Shapes {
    
    public:
    void area();
};

// Parent
class TwoDShapes : protected Shapes {

    public:
    void area();
};

// Parent
class ThreeDShapes : protected Shapes {
    
    public:
    void area ();
    void volume();
};

// 2d-Child
class Circle : protected TwoDShapes {
    public:

};

// 2d-Child
class Square : protected TwoDShapes {

};

// 3d-Child
class Cube : protected ThreeDShapes {

} ;

// 3d-Child
class Pyramid : protected ThreeDShapes {

};

int main() {

    

    return 0;
}