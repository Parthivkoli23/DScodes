#include<iostream>
using namespace std;
int main()
{
    int mat1[2][2], mat2[2][2], i, j;
    cout<<"Enter Elements of Matrix 1: ";
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            cin>>mat1[i][j];
    }
    cout<<"Enter Elements of Matrix 2: ";
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            cin>>mat2[i][j];
    }
    cout<<"\nAdding the Two Given Matrix...\n";
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            mat2[i][j] = mat1[i][j]+mat2[i][j];
    }
    cout<<"The sum of the two matrix is:\n";
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            cout<<mat2[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
