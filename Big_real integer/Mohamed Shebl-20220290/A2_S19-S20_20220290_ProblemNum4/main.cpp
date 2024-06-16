//File: A2_S19-S20_20220290_ProblemNum4.
//Purpose :A program that uses the sieve of Eratosthenes to generate a list of the primes between 2 and a given number n.
//Author: Mohamed Shebl.
//Section: S19-S20.
//ID: 20220290
//TA: Mohamed Talaat
//Date: 30 Oct 2023
#include <iostream>
using namespace std;

int main() {
    int N;
    cout<<"Please enter the upper limit: ";
    cin>>N;
    int* arr = new int [N-1];
    int x=2;
    for (int i = 0; i < N-1; ++i,++x) {
        arr[i]=x;
        if(i==N-2)cout<<arr[i]<<endl;                     //printing out all numbers from 2 to upper limit
        else cout<<arr[i]<<',';
    }
    for (int j = 2; j < N+1; ++j) {
        for (int k = j; k < N-1; ++k) {
            if (arr[k] % j == 0) {                 //finding and eliminating the multiples by replacing them with the number zero
                arr[k] = 0;
            }
        }
    }
    for (int y = 0; y < N - 1; ++y) {
        if (y == N - 2)cout << arr[y] << endl;      //printing out the final list of prime numbers
        else cout << arr[y] << ',';
    }
    delete[] arr;

    return 0;
}