#include <iostream>
using namespace std;
void fibonacci(int n)
{
    int first = 0, second = 1, third;
    cout << "Fibonacci series upto " << n << " terms is:" << endl;

    if (n == 1)
    {
        cout << first << endl;
    }
    else if (n == 2)
    {
        cout << first << endl;
        cout << second << endl;
    }
    if (n > 0)
    {
        cout << first << endl;
        cout << second << endl;
        for (int i = 3; i <= n; i++)
        {
            third = first + second;
            cout << third << endl;
            first = second;
            second = third;
        }
    }
}
int main()
{
    int n;
    cout << "enter number of terms" << endl;
    cin >> n;
    fibonacci(n);
    return 0;
}