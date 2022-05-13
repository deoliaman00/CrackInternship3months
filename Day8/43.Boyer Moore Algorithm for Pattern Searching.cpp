#include <stdio.h>
#include <string.h>
# define NO_OF_CHARS 256
#include<bits/stdc++.h>
using namespace std;
void patternAdjuster( string attern,int sizeP,int A[NO_OF_CHARS])
{
    // A[]-> array in which the whole pattern value would be adjusted
    // pattern-> string that is to be used 
    // sizeP -> size of the pattern string
    int i=0;
   // eg-> T E S T ->  T(ASCII): -1  E(ASCII): -1  S(ASCII): -1  T(ASCII): -1
   
    for(;i<NO_OF_CHARS;i++)  //  0 to 256 .... T=-1   E=-1   S=-1 
    {
        A[i]=-1;
    }
    
   for (i = 0; i < sizeP; i++)
   {
		A[(int)attern[i]] = i;  // T=0 E=1 S=2 T=3 
		                        // XX  E=1 S=2 T=3
   }
}




   
void  bm(string text,string pattern)
{
   // eg=> S U R A N A => 6
    int len1=pattern.length();
    int len2=text.length();
    
    int hash_p[NO_OF_CHARS];
    patternAdjuster(pattern,len1,hash_p);
    
    int s=0;// shifts to be done when 
    // case1:- all pattern gets matched with allowed text
    // case2:- the element dont match but is present in the A[]
    // case3:- the element is not present in pattern nor A[]
    
    
    
    // eg- 0<=14-4=>10
    // 0<=10 --- 1<=10  4<=10
    int j=len1-1;
    while(s<=(len2-len1))
    {                          // 0 1 2 3 
     //   J=3  // T E S T   S=0 
        
        while((j>=0)&&(pattern[j]==text[s+j])) // P[3]==T[4]
        {
            j--;
        } 
        
    
        if(j<0)
        {
            cout<<"Ans is at "<< s<<endl;
        
            
            
            s+=((s+len1)<len2)?len1-hash_p[text[s+len1]]:1;  // S=4
        }
        
        
        
        else
        {
        s+=max(1,j-hash_p[text[s+j]]);  // S= 0+(1, 3-HASH_P[S]) => 1 4 
        }
        
        
        
        
    }
    
}

int main()
{
    char text[] = "THIS IS A TEST";
    char pat[] = "TEST";
    bm(text, pat);
    return 0;
}