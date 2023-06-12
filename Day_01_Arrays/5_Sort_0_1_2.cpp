// Brute Force:
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int count0 = 0;
   int count1 = 0;
   int count2 = 0;

   for(int i=0; i<n; i++){
      if(arr[i] == 0) count0++;
      else if(arr[i] == 1) count1++;
      else count2++;
   }

   for(int j=0; j<count0; j++) arr[j] = 0;
   for(int j=count0; j<count0+count1; j++) arr[j] = 1;
   for(int j=count0+count1; j<n; j++) arr[j] = 2;
}
// TC: O(N) + O(N) -> O(2*N) | SC: O(1)


// OPtimal Approach : Dutch National Flag Algorithm

void sort012(int *arr, int n)
{
   int low = 0;
   int high = n-1;
   int mid = 0;

   while(mid <= high){
      switch(arr[mid]){
         case 0:
            swap(arr[low], arr[mid]);
            mid++; low++;
            break;
         case 1:
            mid++; break;
         case 2:
            swap(arr[mid],arr[high]);
            high--;
            break;
      }
   }
}
// Tc: O(N) | SC: O(1)