#include <iostream>
using namespace std;
void ton(int n, int A, int B, int C) {
    if(n>0) {
        ton(n-1, A, C, B);
        printf("Move %d to %d\n", A, C);
        ton(n-1, B, A, C);
    }
}

int main(int argc, char const *argv[])
{
    cout<<"enter number\n";
    int n;
    cin>>n;
    ton(n, 1, 2, 3);
    return 0;
}