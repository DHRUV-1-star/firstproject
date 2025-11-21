#include<iostream>
using namespace std;
int main(){
    int i,j,n=5;
    char ch='A';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<ch;
            ch++;
        }
        cout<<endl;
        
    }
    return 0;
}