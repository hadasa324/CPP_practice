#include <iostream>
#include <string>
// #include <algorithm>
// #include <cstring>

using namespace std;


// return reverse of string
void reverse(char s [] , int start , int end){
   
    for (size_t i = 0; i <(end-start)/2; i++)
    {
        char temp {s[i+start]};
        s[i+start] = s[end-1-i];
        s[end-1-i] = temp;

    }
    

}

void reverse_words(char s [],int length , int lfirst){

    reverse(s ,0 ,lfirst);
    reverse(s, lfirst+1, length);
    reverse(s,0,length);
}


void reverse(string *s , int start , int end){
     for (size_t i = 0; i <(end-start)/2; i++)
    {

        char temp = (*s)[i+start];
        (*s)[i+start] = (*s)[end-i-1];
        (*s)[end-i-1] = temp;

    }
    
}

void reverse_words(string *s , int length ,int lfirst){
    reverse(s,0,lfirst);
    cout << *s << endl;
    reverse(s,lfirst+1,length);
    cout << *s << endl;
    reverse(s,0,length);
  
}

int main()
{
    // char s [] = "hey danny";
    // cout << "enter string : " ;
    // cin.getline(s , 50);
    // cout << s << endl;
    // reverse_words(s , strlen(s),5);
    // cout << s << endl;

    string s {};
    cout << "enter a string: " ;
    getline(cin , s);
    cout << s.length() << endl;
    reverse_words(&s,s.length(),5);
    cout << s << endl;

    
    
}