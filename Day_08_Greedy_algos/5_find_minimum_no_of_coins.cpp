#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    int count = 0;
    for(int i=n-1; i>= 0; i--){
        while(amount >= deno[i]){
            amount -= deno[i];
            count++;
        }
    }
    return count;
}
// TC: O(amount) (worst case) | SC: O(1) ~ O(9) is almost constant