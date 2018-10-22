// report two bugs about uninitialized value, currmin.

int minval(int *A, int n) {
  int currmin, i;

  for (i=0; i<n; i++)
    if (A[i] < currmin)
      currmin = A[i];
  return currmin;
}

int main(){
	int a[5] = {1,2,3,2,1};
        return minval(a, 5);
}
