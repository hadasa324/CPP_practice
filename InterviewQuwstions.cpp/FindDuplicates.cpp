#include <iostream>

using namespace std;


void findDuplicates(int A [], int length){

    for (size_t i = 0; i < length; i++)
    {
        A[i] +=1;
    }
    

    for (size_t i = 0; i < length; i++)
    {
       int index = A[i]%length;
       A[index] += length;
    }

    for (size_t i = 0; i < length; i++)
    {
        int value = A[i] - A[i]%length;
        if (A[value]/7 >1)
        cout << i-1 << " ";
        
    }

    cout << endl;
    
    
}

void printArray(int A[] , int length){
    cout << "Array: ";
    for (size_t i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    
    cout << endl;

}


int main(){

    int A []{2,1,2,3,0,0,3};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A , n);
    findDuplicates(A ,7);

}


