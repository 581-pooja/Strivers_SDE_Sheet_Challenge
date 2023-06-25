#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/


int findCelebrity(int n) {
 	stack <int> s;
	// Step 1: Push all elements in stack 
	for(int i=0; i<n; i++){
		s.push(i);
	}
	// Step 2: Get 2 elements from arr/mat compare them
	while(s.size() > 1){
		int a = s.top(); s.pop();
		int b = s.top(); s.pop();
		if(knows(a,b)){
			s.push(b);
		}
		else s.push(a);
	}

	int per = s.top();
	for(int i=0; i<n; i++){
		if((per != i) && (knows(per,i) || !knows(i,per))) return -1;
	}
	return per;

	return s.top();
}