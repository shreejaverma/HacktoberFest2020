//WAP to add, multiply two polynomial using classes and objects.
#include<iostream>
#include<string.h>
using namespace std;
 
int* add(int A[], int B[], int m, int n) 
{ 
   int size = (m > n)? m: n; 
   int *sum = new int[size]; 
  
   for (int i = 0; i<m; i++) 
    sum[i] = A[i]; 
   
   for (int i=0; i<n; i++) 
    sum[i] += B[i]; 
  
   return sum; 
} 

int* multiply(int A[], int B[], int m, int n) 
{ 
   int *product = new int[m+n-1]; 
  
    for (int i = 0; i<m+n-1; i++) 
        product[i] = 0; 
  
    for (int i=0; i<m; i++) { 
        for (int j=0; j<n; j++) 
            product[i+j] += A[i]*B[j]; 
    } 
  
    return product; 
} 

void printPoly(int poly[], int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
       cout << poly[i]; 
       if (i != 0) 
        cout << "x^" << i ; 
       if (i != n-1) 
       cout << " + "; 
    } 
}

int main(){
    int n,m,*a,*b;
    cout<<"Enter the maximum exponent of polynomial 1";
    cin>>n;
    cout<<"Enter the maximum exponent of polynomial 2";
    cin>>m;
    a=new int[n];
    b=new int[m];
    cout<<"Enter the polynomial 1 cofficient of all the exponents in sequence";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the polynomial 2 cofficient of all the exponents in sequence";
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    cout<<"Sum of polynomials:";
    int size = (m > n)? m: n; 
    int *sum = new int[size];
    sum=add(a,b,n,m);
    printPoly(sum,size);
    cout<<endl;
    cout<<"Product of polynomials:";
    int *product = new int[m+n-1];
    product=multiply(a,b,n,m);
    printPoly(product,m+n-1); 
}