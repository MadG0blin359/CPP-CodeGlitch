#include <iostream>
using namespace std;

class Heart
{
    int a;

public:
    Heart(int num) : a(num)
    {
        cout << "Heart Object is created " << a << endl;
    }

    ~Heart()
    {
        cout << "Heart object is destroyed" << endl;
    }
};

class Body
{
private:
    Heart heart;

public:
    Body(int num) : heart(num)
    {
        cout << "Body Object is created" << endl;
    }
    ~Body()
    {
        cout << "Body object is destroyed" << endl;
    }
};

int main()
{
    Body myBody(5);
    return 0;
}