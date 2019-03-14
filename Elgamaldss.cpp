#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int eef(int,int);
int modular_pow(int base, int exponent, int modulus);
int main()
{
      int p,n,P1,d,e1,e2,r,C1,C2,C0,P,r1,M,m,c1,c2;
      cout<<"enter plain text"<<endl;
      cin>>P1;
      cout<<"enter a large prime numbers"<<endl;
      cin>>p;
      cout<<"select the value of d"<<endl;
      cin>>d;
      cout<<"Select the value of e1 as premetive root in the group G"<<endl;
      cin>>e1;
      e2= modular_pow(e1,d,p);
      cout<<"Alice's public keys are"<<"e1 = "<<e1<<" "<<"e2 ="<<e2<<" "<<"p ="<<p<<endl;
      cout<<"Alice's private key is "<<" "<<d<<endl;
//signing algo
      int PP = p-1;
       l:
      cout<<"choose the value of r "<<endl;
      cin>>r;
      C1 = modular_pow(e1, r, p);//first signature
      M = P1 - (d*C1);
      r1 = eef(r,PP);
      cout<<r1<<endl;
      m = M*r1;
      C2 = modular_pow(m, 1, PP);//secong signature
      if(C2<0)
      {
        C2 = C2+PP;
      }
      cout<<"signature1 = "<<" "<<C1<<" "<<"and"<<" "<<"signature2 = "<<C2<<" "<<endl;
//verification algo
    

      int V1 = modular_pow(e1,P1,p);
      int v  = modular_pow(e2,C1,p);
      int v2 = modular_pow(C1,C2,p);
      int V = v*v2;
      int V2 = modular_pow(V,1,p);
      cout<<" "<<"V1 = "<<V1<<" "<<"V2 = "<<V2<<endl;
      if (V1==V2)
      {
        cout<<"Sience V1 = V2 hence The signature is verified"<<endl;
      }
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

