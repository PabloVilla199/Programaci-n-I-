 /*
 * traza2.cpp
 * C.Catalán 10/2023
 */
 #include <iostream>
 using namespace std;

 int f(int &a, int b);

 int main() {
 int a = 12;
 int b = 9;
cout << a << endl;
cout << b << endl;
cout << endl;
 a = f(a, b * 3);
 cout << endl;
 cout << a << endl;
cout << b << endl;
 cout << endl;
 b = f(b, a);
  cout << endl;
 cout << a << endl;
 cout << b << endl;
  cout << endl;

 }

 int f(int &a, int b) {
 int x = 7;

 x = a - b - x;
 cout << x << endl;
 a = x / b + 2;
 cout << a << endl;
 b = a + b -5 ;
 cout << b << endl;
 return b + x;
 }
