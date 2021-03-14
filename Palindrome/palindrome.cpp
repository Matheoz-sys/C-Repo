#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main(void)
{
    int check = 0;
    string z;
    cout << "Give a word:";
    cin >> z;
    int t = z.length();
    char word[t];
    t--;
    strcpy(word, z.c_str());
    for (int i = 0; i <=t; i++){
        if (word[i] == word[t-i])
        {
            check++;
        }
    }
    if (check == t+1){
        cout << "Word is a palindrome";
    }else{
        cout << "Word isn't a palindrome";
    }
}