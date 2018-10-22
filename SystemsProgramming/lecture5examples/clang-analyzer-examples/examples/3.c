// find the out-of-bounds error

int main(int i){
	int a[5] = {1,2,3,4,5};
	a[i];  // cannot find potential out-of-bounds error
	return a[5];  // Undefined or garbage value returned to caller
}
