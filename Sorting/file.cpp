#include <iostream>
#include <tuple>

using namespace std;

#define nr 10

void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  

void printArray(int a[], int y)  
{  
    int i;  
    for (i = 0; i < y; i++) 
        cout << a[i] << " ";  
    cout << endl;  
}  

int func_max(int x[], int y, int& pos){
    int max = x[0];
    pos = 0;
    for (int i = 1; i < y; i++){
        if (max < x[i]){
            max = x[i];
            pos = i;
        }}
    return max;
}


int func_min(int x[], int y, int& pos){
    int min = x[0];
    pos = 0;
    for (int i = 1; i < y; i++){
        if (min > x[i]){
            min = x[i];
            pos = i;
        }}
    return min;
}

void bubble_sorting(int a[], int y){
    int s;
    do{
        int i=0, j, check = 0;
        s=0;
    for (i = 0; i < y-1; i++){
    for (j = 0; j < y-1; j++){  
        if (a[i] > a[i+1]){  
            swap(a[i], a[i+1]);
            s++;
                if(s>check){
                    check++;
                    printArray(a, y);
                }}}}
}while(s!=0);
}

void sort_by_replace(int a[], int y){
    int temp, k=0;
    int pos;
    for(int i=y-1;i>0;i--){
        int z = func_max(a,i+1, pos);
        temp = a[i];
        a[i] = z;
        a[pos] = temp;
        printArray(a, y);
    }
            printArray(a, y);
}


void sort_by_counting(int a[], int y){
    int pos, t = 1, k=0;
    int f[y];
    int z = func_max(a, y, pos);
    int Z[z][t];
    for(int i=0;i<=z;i++){ //init Array
            Z[i][t] = 0; 
    }
    for(int i=0;i<=z;i++){  //counting how many same numbers
        for(int j=0;j<y;j++){
            if(i == a[j]){
            Z[i][t]++;
            }}}
    for(int j=0;j<=z;j++){//Initializing to new Array
        if(Z[j][t]>0){
            do{
                f[k] = j;
                Z[j][t]--;
                k++;
                }while(Z[j][t]!=0);
        }}
    printArray(f,y);
}

void sort_by_counting_after_minimalization(int a[], int y){
    int pos, k=0;
    int f[y];
    int z = func_max(a, y, pos);
    for(int i=0;i<=z;i++){
        for(int j=0;j<y;j++){
            if(i == a[j]){
            f[k] = i;
            k++;
        }}}
    printArray(f,y);
}


int main(){
    int min_pos, max_pos, max, min;
    int arr[] = { 4, 8, 9, 1, 1, 7, 9, 2, 5, 14};
    int arrY[] = { 4, 8, 9, 1, 1, 7, 9, 2, 5, 14};
    int arrZ[] = { 4, 8, 9, 1, 1, 7, 9, 2, 5, 14};
    int arrX[] = { 4, 8, 9, 1, 1, 7, 9, 2, 5, 14};
    max = func_max(arr, nr, max_pos); //max
    min = func_min(arr, nr, min_pos); //min
    cout << "Min: " << min << " Pos: " << min_pos+1 << " - a[" << min_pos << "]" << endl;
    cout << "Max: " << max << " Pos: " << max_pos+1 << " - a[" << max_pos << "]" << endl << endl;
    cout << "Bubble sorting, step by step:" << endl;
    bubble_sorting(arr, nr);
    cout << "Sorting by replace, step by step:" << endl;
    sort_by_replace(arrY, nr);
    cout << "Sorting by counting:" << endl;
    sort_by_counting(arrZ, nr);
    cout << "Sorting by counting after small changes:" << endl;
    sort_by_counting_after_minimalization(arrX, nr);
    getchar();
    return 0;
}