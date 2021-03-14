#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main(void)
{
    int check = 1;
    string z;
    cout << "Give a word:";
    cin >> z;
    int t = z.length();
    char first[t], second[t];
    t--;
    strcpy(first, z.c_str());
    for (int i = 0; i <=t; i++)
    {
        second[i] = first[t-i];
    }
    for (int i = 0; i <=t; i++)
    {
        if (second[i] == first[i])
        {
            check++;
        }
    }
    if (check == t)
    {
        cout << "Word is a palindrome";
    }else
    {
        cout << "Word isn't a palindrome";
    }
}