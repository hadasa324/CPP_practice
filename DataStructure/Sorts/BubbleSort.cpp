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


void BubbleSort(int A[], int length){

for (size_t i = 0; i < (length-1); i++)
{
    int flag = 0;
    for (int j = 0; j < (length -1 -i); j++)
    {
        if (A[j] > A[j+1]){
            flag =1;
            swap(&A[j],&A[j+1]);

        }
        
    }
    if (flag == 0)
    return;
    
    
}

}



int main(){
    int A []{1,4,2,3,7,6};

    DisplayArray(A ,6 );
    BubbleSort(A,6);
    DisplayArray(A,6);


}