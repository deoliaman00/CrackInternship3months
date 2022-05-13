#include <iostream>

using namespace std;


void RKAP(string txt,string pttrn,int p)
{
    int d=256;
    // step1
    // calculating the hashcode of pattern
    int hpattrn=0,tpattrn=0,r=1;
    // calculating the size
    int stxt=txt.length();
    int spttrn=pttrn.length(),j;
    
    
    // note this r will be used when we want to change the window size 
    for(int i=0;i<spttrn-1;i++)
    {
        r= (r*d)%p;
    }
    // eg-> hpattrn=700
    
    for(int i=0;i<spttrn;i++)
    {
        // hashvalue= (totalSize*hashvalue+ ascii val of no)%greatestPrimeNo
        
        hpattrn=(d*hpattrn+pttrn[i])%p;
        tpattrn=(d*tpattrn+txt[i])%p; // p->prime
    }
    
    
    // exaple hpattrn=20 and tpattrn=20
    // then we get the first window that is equal
    
    for(int i=0;i<=stxt-spttrn;i++)
    {
        bool flag=true;
        if(hpattrn==tpattrn)
        {
            for(j=0;j<spttrn;j++)
            {
                if(txt[i+j]!=pttrn[j])
                {
                    flag=false;
                    break;
                }
                if(flag!=false)
                  cout<<i<<" ";
            }
            
            if(j==spttrn)
            {
                cout<<"The indexes are "<<i<<endl;
            }
        }
        //      i i i 
        // from A A A B A B A B A
        
       // to 
        
        //        i i i
        // from A A A B A B A B A
        
        if(i<stxt-spttrn) // 0<15-3=> 0<12 true;
        {
            tpattrn=(d*(tpattrn-txt[i]*r)+(txt[i+spttrn]))%p;
            
            // newhashval = (size*(old hash- removedVal*GeneralHash)+ (newtext))%primeno
        
            if(tpattrn<0)
            {
                tpattrn+=p; // t= t(hashValue)+ primeno
            }
        }
    }
    
}
int main()
{
    string txt="aman am deoli";
    string pt="am";
    int prim=3691;
    RKAP(txt,pt,prim);
    return 0;
}