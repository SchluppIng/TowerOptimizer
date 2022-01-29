#include <iostream>
#include "InputData/Input.h"

using namespace std;

int main()
{
    double d{500};
    InputData ipData(d);

    ipData.ToString();

    cout << "Hello World\n";
    return 0;
}