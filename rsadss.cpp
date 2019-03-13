#include<iostream>
#include<algorithm>
#include<cmath>


using namespace std;
int eef(int,int);
int modular_pow(int base, int exponent, int modulus);
int main()
{
      
      int e,d,p,q,n,P1;
      cout<<"enter plain text"<<endl;
      cin>>P1;
      cout<<"enter two large prime numbers"<<endl;
      cin>>p>>q;
      n = p*q;
      int fn = (p-1)*(q-1);
      l:
      cout<<"choose the value of e "<<endl;
      cin>>e;
      if(e>1&&e<fn&&__gcd(e,fn)==1)
      {
      int t = e;
      }
      else
      { 
         cout<<"the value of e is incorrect"<<endl;
         e=0;
         goto l;
         }
         
      d = eef(e,fn);
      cout<<"alice's public key are "<<e<<" "<<n<<endl;
      cout<<"alice's private key is "<<d<<" "<<endl;
//encryption      
      int Y = modular_pow(P1, d, n);
      cout<<"signature"<<" "<<Y<<endl;
      
//decryption   
      int X = modular_pow(Y,e,n);
      cout<<"message"<<" "<<X<<endl;
return 0;
}
//extended euclidian function
int eef(int e,int fn)
{
    e = e%fn; 
    for (int x=1; x<fn; x++) 
       if ((e*x) % fn == 1) 
          return x; 
} 

//fast exponentiation function
int modular_pow(int base, int exponent, int modulus)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


