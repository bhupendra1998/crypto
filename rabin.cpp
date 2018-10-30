#include<iostream>
#include<algorithm>
#include<cmath>
#include <tuple>
using namespace std;

tuple<int, int, int> extended_gcd(int a, int b );
 int main()
 {
 int n,f1=0,j1=0,d1;
 	cout<<"enter the plain text"<<endl;
      cin>>n;

 	long long binaryNumber = 0;
  
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    cout<< binaryNumber<<endl;
    int times = 1;
   while (times <= binaryNumber)
      times *= 10;
   long long bb = binaryNumber*times + binaryNumber;
   cout<<bb;
   int decimalNumber = 0, g = 0;
    while (bb!=0)
    {
        remainder = bb%10;
        bb /= 10;
        decimalNumber += remainder*pow(2,g);
        ++g;
    }
    d1=decimalNumber;
    cout<<endl<<d1<<endl;
   int p,q;
   cout<<endl<<"enter two prime numbers p and q"<<endl;
   cin>>p>>q;
   int m = p*q;
   int c = fmod(d1*d1,m);
   cout<<c;

   cout<<endl<<"decryption start"<<endl;
   int a =p;
   int b=q;
tuple<int, int, int> t = extended_gcd(a, b);
int gcd = get<0>(t);
	int x = get<1>(t);
	int y = get<2>(t);
	cout<<endl << "x = " << x << " y = " << y << endl;

	cout <<endl<< p << "*" << x << " + " << q << "*" << y << " = " << gcd<<endl;
	int o=(p+1)/4;
	int o1=(q+1)/4;
    f1 = pow( c,o);
    j1 = pow(c,o1);
	cout<<o<<endl;
	cout<<o1<<endl;
	cout<<f1<<endl;
	cout<<j1<<endl;
	int f,j,k,l;
	f = fmod(c*c*c,p);
	j = fmod(c*c,q);
	k = fmod(x*p*j+y*q*f,m);
	l = fmod(x*p*j-y*q*f,m);
	cout<<endl<<f<<endl<<j<<endl<<k<<endl<<l<<endl;
	int m1,m2,m3,m4;
	m1=k;
	m2=m-k;
	m3=l;
	m4=m-l;
	cout<<endl<<m1<<endl<<m2<<endl<<m3<<endl<<m4<<endl;
	if(d1==m1 )
	{
		d1=m1;
	}
	else if (d1==m2)
	{
		d1=m2;
	}
	else if (d1==m3)
	{
		d1=m3;
	}
	else
		d1=m4;
return 0;
}
tuple<int, int, int> extended_gcd(int a, int b)
{
	if (a == 0)
		return make_tuple(b, 0, 1);
	int gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);
	return make_tuple(gcd, (y - (b/a) * x), x);
}