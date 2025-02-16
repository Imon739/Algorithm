#include<bits/stdc++.h>

using namespace std;


int power(int x, int y) {
    if(y==0) return 1;

    if(y%2==0) return power(x,y/2) * power(x,y/2);
    else return power(x,y/2) * power(x,y/2) * x;
}


int main()
{
    int x,y,result;

    cout << "Enter X: ";
    cin >> x;

    cout << "Enter Y: ";
    cin >> y;

    if(y<0) {
        cout << "Invalid exponent" << endl;
    } else {
        result = power(x,y);
        cout << "Result: " << result << endl;
    }
}
