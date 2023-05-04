#include <iostream>

using namespace std;


void Display(int A []  ,int n){

for (size_t i = 0; i < n; i++)
{
    cout<<A[i] << " ";
}

cout << endl;

}


void merge(int A[] , int l ,int mid ,int h ){
    int i = l;
    int j = mid+1;
    int k = l;
    int B[h+1];

    while (i<=mid && j<=h)
    {
        if (A[i]<A[j])
        {
            B[k++] = A[i++];
        }
        else{
             B[k++] = A[j++];
        }
        
    }

   while (i <= mid)
    {
        B[k++] = A[i++];
    }
    
    while (j<=h)
    {
        B[k++] = A[j++];
    }

    for ( i = l; i <= h; i++)
    {
        A[i] = B[i] ;
    }
    
    
    

}


void mergeSort(int A[] , int n){
size_t p;
    for ( p = 2; p <=n; p=p*2)
    {
       for (size_t i = 0; i+p-1 < n; i=i+p)
       {
         int l =i;
         int h = i+p-1;
         int mid = (l+h)/2;
         merge(A,l,mid ,h);
       }
       
    }
    if (p/2 < n)
    {
        merge(A,0,p/2-1,n-1);
    }
    
    
}


int main(){
    int A[]{4,6,2,7,9,3};
    Display(A , 6);
    mergeSort(A ,6);
    Display(A,6);

}