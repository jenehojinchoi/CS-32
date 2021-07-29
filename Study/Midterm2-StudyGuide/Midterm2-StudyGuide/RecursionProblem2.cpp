//
//  RecursionProblem2.cpp
//  Midterm2-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/29.
//

#include <iostream>
using namespace std;

int mystery(int n)
{
     if (n == 0)
     return 1;
     else
     return 3 * mystery(n - 1);
}

int recur(int n)
{
    if (n <= 10)
        return n * 2;
    else
        return recur(recur(n / 3));
}

//x0 = 1.0
//xn = x * xn-1
//for n >= 1
double Power(double x, unsigned int n)
{
    if (n==0) return 1;
    else return x * Power(x, n-1);
}

//works by breaking n down into halves, squaring Power(x, n/2), and
//multiplying by x again if n was odd.
//For example: x11 = x5 * x5 * x
// x10 = x5 * x5
double Power2(double x, unsigned int n)
{
    if (n==0) return 1;
    if (n%2 == 1) return Power(x, n/2) * Power(x, n/2);
    else return Power(x, n/2) * Power(x, n/2) * x;
}

// gives the product of the integers in the range m:n (m <= n)
int Product(int m, int n)
{
    if (m==n) return m;
    else return n * Product(m, n-1);
}

// find the smallest integer in the integer array A. n is the number of elements in A.
//HINT: you could define an auxiliary function Min2(A,k,j) that finds the smallest integer in A[k:j] and let Min(A,n) = Min2(A,0,n-1)

int Min2(int A[],int k, int j)
{
    if (j == k+1) {
        if (A[k] > A[j]) return A[j];
        else return A[k];
    }
    if (Min2(A, 0, j-1) > A[j]) return A[j];
    else return Min2(A, 0, j-1);
}

int Min(int A[], int n)
{
    return Min2(A, 0, n-1);
}

//int main()
//{
//    int mysteryResult = mystery(5);
//    cout << "mystery(5): " << mysteryResult << "\n";
//
//    int recurResult = recur(27);
//    cout << "recur(27): " << recurResult << "\n";
//
//    int powerResult = Power(5, 3);
//    cout << "Power(5, 3): " << powerResult << "\n";
//
//    int power2Result = Power2(5, 3);
//    cout << "Power2(5, 3): " << power2Result << "\n";
//
//    int productResult = Product(2, 5);
//    cout << "Product(2, 4): " << productResult << "\n";
//
//    int A[7] = {3,5,7,2,4,6,9};
//    int minResult = Min(A, 7);
//    cout << "Min(A, 7): " << minResult << "\n";
//
//    return 0;
//}
