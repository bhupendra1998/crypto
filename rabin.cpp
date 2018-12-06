#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int eef(int,int);
int modular_pow(int base, int exponent, int modulus);
int main()
{
      int e=2,p,q,n,P1;
      cout<<"enter plain text"<<endl;
      cin>>P1;
      cout<<"enter two large prime numbers"<<endl;
      cin>>p>>q;
      n = p*q;
      cout<<"bobs public key is"<<" "<<n<<endl;
      cout<<"bobs private key is "<<p<<" "<<q<<endl;
//encryption
      int C = modular_pow(P1, e, n);
      cout<<"chiphertext"<<" "<<C<<endl;
//decryption
      int x1 = (p+1)/4;
      int x2 = (q+1)/4;
      int a1,a2,b1,b2,q1,q2,q3,q4;
      a1 = modular_pow(C, x1, p);
      a2 = -(modular_pow(C, x1, p));
      a2 = p+a2;
      b1 = modular_pow(C, x2, q);
      b2 = -(modular_pow(C, x2, q));
      b2 = q+b2;
      cout<<"a1="<<a1<<" "<<"a2="<<a2<<endl;
      cout<<"b1="<<b1<<" "<<"b2="<<b2<<endl;
      int iA = eef(q,p);
      int iB = eef(p,q);
      cout<<"iA="<<iA<<" "<<"iB="<<iB<<endl;
      q1 = (a1*q*iA) + (b1*p*iB);
      q2 = (a1*q*iA) + (b2*p*iB);
      q3 = (a2*q*iA) + (b1*p*iB);
      q4 = (a2*q*iA) + (b2*p*iB);
//after doing  MOD by n of q1,q2,q3,q4     
      int p1,p2,p3,p4;
      p1 = modular_pow(q1,1,n);
      p2 = modular_pow(q2,1,n);
      p3 = modular_pow(q3,1,n);
      p4 = modular_pow(q4,1,n);
      cout<<"Possible plaintext"<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
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

