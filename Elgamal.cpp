#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int eef(int,int);
int modular_pow(int base, int exponent, int modulus);
int main()
{
      int p,n,P1,d,e1,e2,r,C1,C2,C0,P,c2;
      cout<<"enter plain text"<<endl;
      cin>>P1;
      cout<<"enter a large prime numbers"<<endl;
      cin>>p;
      cout<<"select the value of d"<<endl;
      cin>>d;
      cout<<"Select the value of e1 as premetive root in the group G"<<endl;
      cin>>e1;
      e2= modular_pow(e1,d,p);
      cout<<"bobs public key are"<<" "<<e1<<" "<<e2<<" "<<p<<endl;
      cout<<"bobs private key is "<<p<<" "<<d<<endl;
//encryption
      cout<<"Select a random integer r in the group G"<<endl;
      cin>>r;
      C1 = modular_pow(e1, r, p);
      C2 = modular_pow(e2, r, p);
      C0 = modular_pow(P1, 1, p);
      int Q = C2*C0;
      c2 = modular_pow(Q, 1, p);
      cout<<"chiphertext"<<" "<<C1<<" "<<"and"<<" "<<c2<<" "<<endl;
//decryption
      int C11 = pow(C1,d);
      int C111 = eef(C11,p);
      int C22 = c2*C111;
      P = modular_pow(C22,1,p);
      cout<<"plaintext"<<" "<<P<<endl;
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
//fast exponentiation
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

