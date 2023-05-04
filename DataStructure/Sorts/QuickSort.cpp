#include <iostream>

using namespace std;


void swap(int *a , int *b){
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


int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
 
    while (true){
        while (i <= j && A[i] <= pivot){
            i++;
        }
        while (A[j] >= pivot && j >= i){
            j--;
        }
        if (j < i){
            break;
        } else {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}
 
void quickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);
        quickSort(A, low, p-1);
        quickSort(A, p+1, high);
    }
}

int main(){

    int A []{1,4,2,3,7,6};

    DisplayArray(A ,6 );

    quickSort(A,0,5);

    DisplayArray(A,6);


}