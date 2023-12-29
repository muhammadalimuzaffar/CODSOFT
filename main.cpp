#include <iostream>

using namespace std;

int main()
{
    int a, b, c, sum, sub, mul, div;
    cout << "Enter first number:\t";
    cin >> a;
    cout << "Enter second number:\t";
    cin >> b;

    cout << "Enter your choice:\n\n";

    cout <<"1.  Addition\n";
    cout <<"2.  Subtraction\n";
    cout <<"3.  Multiplication\n";
    cout <<"4.  Division\n";

    cin >> c;

    if (c==1){
        sum = a+b;
        cout <<"Addition is:\t" << a << " + " << b << " = " << sum << endl;
    }
    else if (c==2){
        sub = a-b;
        cout <<"Subtraction is:\t" << a << " - " << b << " = " << sub << endl;
    }
    else if (c==3){
        mul = a*b;
        cout <<"Multiplication is:\t" << a << " x " << b << " = " << mul << endl;
    }
    else if (c==4){
        div = a/b;
        cout <<"Division is:\t" << a << " / " << b << " = " << div << endl;
    }
    return 0;
}
