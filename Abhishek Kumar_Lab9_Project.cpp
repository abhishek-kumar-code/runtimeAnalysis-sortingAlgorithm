/*  CS2413 Data Structures PROJECT, Abhishek Kumar  */
/*  Project Requirement: RUN-TIME ANALYSIS OF SORTING ALGORITHMS */

#include<iostream>
#include<cstdlib>
#include<ctime>
// sort() in STL.
//#include <bits/stdc++.h>
 
using namespace std;

//void merge(int[],int,int[],int,int[]);
void bubblemethod(int*,int);
void insertionmethod(int[],int);
void merge_sort(int[],int,int);
void merge(int[],int,int,int,int);
void selectionmethod(int[],int,int);
int arrayGenerate(int);

void random_gen();

   int size;
   int*array;

void bubblesort(int array[], int size){
  clock_t start;
  double time_duration;
  start = clock();
  
  int d,swap,c1;
  for (c1 = 0 ; c1 <size; c1++)
  {
    for (d = 0 ; d < size - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap   = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
  cout<< endl << "The sorted list using Bubble Sort method is: " <<endl;
    for ( c1 = 0 ; c1 <size; c1++)
      cout<<array[c1]<<"\n";
  
  time_duration = (clock() - start)/(double) CLOCKS_PER_SEC;
  cout<<endl<<"Execution time for Bubble Sort: "<<time_duration<<" seconds";
}

void insertionmethod(int array[],int size)
{
  clock_t start;
  double time_duration;
  start = clock();
                int d,t,c1;
                 for (c1 = 1 ; c1 <= size - 1; c1++) 
                 {
                   d = c1;

                   while ( d > 0 && array[d] < array[d-1]) 
                   {
                     t = array[d];
                     array[d]  = array[d-1];
                     array[d-1] = t;

                     d--;
                   }
                 }

                cout<< endl << "The sorted list using Insertion Sort method is: " <<endl;
                
                for (c1 = 0; c1 <= size - 1; c1++) 
                    cout<<(array[c1])<<"\n";
  
  time_duration = (clock() - start)/(double) CLOCKS_PER_SEC;
  cout<<endl<<"Execution time for Insertion Sort: "<<time_duration<<" seconds";

            }
            
// Sort arr[] of size n using Selection Sort. 
void selectionmethod(int array[], int size)
{
  clock_t start;
  double time_duration;
  start = clock();
int i, j;
for (i = 0; i < size; ++i)
{
for (j = i+1; j < size; ++j)
{
// Comparing consecutive data and switching values if value at i > j.
if (array[i] > array[j])
{
array[i] = array[i] + array[j];
array[j] = array[i] - array[j];
array[i] = array[i] - array[j];
} 
}
// Value at i will be minimum of all the values above this index.
}
cout<< endl << "The sorted list using Selection Sort method is: " <<endl;
for (i = 0; i < size; i++)
cout<<(array[i])<<"\n";
time_duration = (clock() - start)/(double) CLOCKS_PER_SEC;
  cout<<endl<<"Execution time for Selection Sort: "<<time_duration<<" seconds";
}
            

clock_t start;
double time_duration;           
void merge_sort(int array[], int length) 
{
  
  start = clock();
  
  merge_sort(array, 0, length-1);
}

void merge_sort(int array[], int low, int high) 
{
    if (low >= high)                  //Base case: 1 value to sort->sorted
      return;                         //(0 possible only on initial call)
    else {
      int mid = (low + high)/2;       //Approximate midpoint*
      merge_sort(array, low, mid);        //Sort low to mid part of array
      merge_sort(array, mid+1, high);     //Sort mid+1 to high part of array
      merge(array, low, mid, mid+1, high);//Merge sorted subparts of array
    }
}

void merge(int array[], int left_low, int left_high, int right_low, int right_high) 
{ 
    int length = right_high-left_low+1;
    int temp[length];
    int left = left_low;
    int right = right_low;
    for (int i = 0; i < length; ++i) { 
        if (left > left_high)
            temp[i] = array[right++];
        else if (right > right_high)
            temp[i] = array[left++];
        else if (array[left] <= array[right])
            temp[i] = array[left++];
        else
            temp[i] = array[right++]; 
    }
    
    for (int i=0; i< length; ++i) 
        array[left_low++] = temp[i];
}

int main(){
    
    int choice, choice2;
    
    while(1){
        cout<<"\n\033[1;33m---------------------------------\033[0m\n";
        cout<<"\n\033[1;33m             M E N U             \033[0m\n";
        cout<<"\n\033[1;33m---------------------------------\033[0m\n";
        
        cout<<"\n\033[1;33mRandom array(Small/Large) (1), Sorted large array(2), Partially sorted large array (3)\033[0m";
        cin>>choice2;
        cout<<"\n\033[1;33mBubble Sort (1), Insertion Sort (2), Selection Sort (3), Merge Sort(4)\033[0m";
        cout<<"\n\033[1;33mExit Program (5)\033[0m";
        cout<<"\n\n\033[1;33mChoose? : \033[0m";
        cin>>choice;
        
       
       
     
        
        switch(choice){
            
            case 1:
                size = arrayGenerate(choice2);
                bubblesort(array, size);
                break;
            case 2:
                //size = arrayGenerate();
                //insertionsort(array, size);
                size = arrayGenerate(choice2);
                insertionmethod(array,size);
                break;
            case 3:
                size = arrayGenerate(choice2);
                selectionmethod(array,size);
                break;
            case 4:
                size = arrayGenerate(choice2);
                merge_sort(array,size);
                cout<<endl;
                cout<< endl << "The sorted list using Merge Sort method is: " <<endl;
                for (int c2 = 0; c2 <= size - 1; c2++) 
                    cout<<(array[c2])<<"\n";
                
                time_duration = (clock() - start)/(double) CLOCKS_PER_SEC;
                cout<<endl<<"Execution time for Merge Sort: "<<time_duration<<" seconds";
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

int arrayGenerate(int choice2)
{
    int size;
    
    cout<<endl<<"Smaller Array: 10 to 15 elements";
    cout<<endl<<"Large Arrays: 10000 elements";
    cout<<endl<<endl<<"Enter the size of array to be sorted:";
      cin>>size;
      
    int randomnum, c1, n1;
    
    randomnum=size;
    array=new int[size];
  /*
    int route; 
    
    while(1){
      
      cout<<"\n\033[1;33m---------------------------------\033[0m\n";
      cout<<"\n\033[1;33m         M E N U (2)             \033[0m\n";
      cout<<"\n\033[1;33m---------------------------------\033[0m\n";
      cout<<"\n\033[1;33mRandom Generation (1), Sorted Generation (2), Partially Sorted Generation(3)\033[0m";
      cout<<"\n\033[1;33mExit Program (4)\033[0m";
      cout<<"\n\n\033[1;33mChoose? : \033[0m";
      cin>>route;
      
      switch(route){
            
            case 1:
                random_gen();
                break;
            case 2:
                
                break;
            case 3:
          
                break;
            
            case 4:
                exit(0);
        }
  }
   */ 
    
    cout<< endl <<"The random numbers generated in the array are: " <<endl;

               for (c1 = 1; c1 <= size; c1++) 
                  {
                      n1 = rand()%size + 1;
                      printf("%d\n", n1);
                      array[c1-1]=n1;
                  }
     if(choice2  == 2){
        int m,swap,k;
        for (k = 0 ; k <size; k++)
        {
          for (m = 0 ; m < size - 1; m++)
          {
            if (array[m] > array[m+1]) 
            {
              swap   = array[m];
              array[m]   = array[m+1];
              array[m+1] = swap;
            }
          }
        }
     }         

  cout<<endl;
  
  //for (int p = 0; p < size; p++)
    //cout<<(array[p])<<"\n";

  if(choice2 == 3){
    int m2,swap2,k2;
    int newsize = (5/100)*size;
    
        for (k2 = 0 ; k2 <newsize; k2++)
        {
          for (m2 = 0 ; m2 < newsize - 1; m2++)
          {
            if (array[m2] > array[m2+1]) 
            {
              swap2   = array[m2];
              array[m2]   = array[m2+1];
              array[m2+1] = swap2;
            }
          }
        }
        
        for (k2 = (size - newsize) ; k2 <size; k2++)
        {
          for (m2 = 0 ; m2 < newsize - 1; m2++)
          {
            if (array[m2] > array[m2+1]) 
            {
              swap2   = array[m2];
              array[m2]   = array[m2+1];
              array[m2+1] = swap2;
            }
          }
        }
  }
  
  for (int p = 0; p < size; p++)
    cout<<(array[p])<<"\n";

    return size;    
}