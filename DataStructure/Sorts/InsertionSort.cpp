#include <iostream>

using namespace std;



void DisplayArray(int A[], int length){
    for (size_t i = 0; i < length; i++)
    {
        cout<< A[i] << " ";
    }
    cout << endl;
    
}


void InsertionSort(int A [] , int length){
    for (int i =1; i < length; i++)
    {
        int temp = A[i];
        int j = i-1;
        while (j>-1 && temp < A[j])
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] =temp;
        
        
    }
    
}



int main(){
    int A []{5,4,5,3,7,6};

    DisplayArray(A ,6);
    InsertionSort(A,6);
     DisplayArray(A ,6);
}