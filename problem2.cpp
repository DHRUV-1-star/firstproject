#include <iostream>
#include <cmath>

using namespace std;
void printprime(int n)
{
    int i;
    cout << "prime numbers upto " << n << " are:" << endl;
    for (int j = 1; j <= n; j++)
    {
        if (j == 1)
            ;
        else if (j == 2)
        {
            cout << j << endl;
        }
        else
        {
            for (i = 2; i <= sqrt(j); i++)
            {
                if (j % i == 0)
                {
                    goto end;
                }
            }
            cout << j << endl;
        }
    end:;
    }
}
int main()
{
    int n;
    cout << "enter a number" << endl;
    cin >> n;
    printprime(n);
    return 0;
}