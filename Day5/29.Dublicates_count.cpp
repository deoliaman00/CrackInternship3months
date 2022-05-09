#include <iostream>

using namespace std;
void printDublicates(string a)
{
    int n=a.length();
    int A[26]={0};
    for(int i=0;i<n;i++)
    {
        A[a[i]-'a']++;
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]>1)
        {
            char w=i+'a';
            cout<<w<<"  "<<A[i]<<endl;
        }
    }
    
}
int main()
{
    string s="stkabeeracademyk";
    printDublicates(s);

    return 0;
}