#include <iostream>

using namespace std;

void swap(int *a , int * b){
int temp = *a;
*a = *b;
*b = temp;
}

void DisplayArray(int A[], int length){
    for (size_t i = 0; i < length; i++)
    {
        cout<< A[i] << " ";
    }
    cout << endl;
    
}


void SelectionSort(int A[] , int length){
    int j , k;

    for (int i = 0; i < (length-1); i++)
    {
        for (j = k = i; j < length; j++)
        {
            if (A[j] < A[k])
                k = j; 
        }
        swap(&A[i] , &A[k]);
        
    }
    

}



int main(){

 int A []{1,4,2,3,7,6};

    DisplayArray(A ,6 );
    SelectionSort(A ,6);
    DisplayArray(A,6);

}