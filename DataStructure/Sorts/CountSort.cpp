#include <iostream>

using namespace std;

void DisplayArray(int A[], int length){
    for (size_t i = 0; i < length; i++)
    {
        cout<< A[i] << " ";
    }
    cout << endl;
    
}


int findmax(int A [] , int n){
    int max = INT_MIN;

    for (size_t i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max =A[i];
        }
        
    }
    return max;

}


void countingSort(int A [] , int n){
    int max = findmax(A,n);
    int *count =new int [max+1];
    for (size_t i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (size_t i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    int i =0 ;
    int j =0 ;
    while (i <= max)
    {
        if (count[i]>0)
        {
            A[j++] = i;
            count[i]--;
        }else{
            i++;
        }
        
    }
    delete [] count;
    
    
}

int main(){

    int A []{1,4,2,3,7,6};

    DisplayArray(A ,6 );
    countingSort(A,6);
    DisplayArray(A,6);

}