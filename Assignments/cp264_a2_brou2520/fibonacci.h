/*
 -------------------------------------
 File:    fibonacci.h
 Project: CP264-a2q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-27
 -------------------------------------
 */
extern int *la; // global pointer variable to get local variable address

int iterative_fibonacci(int n) {
	if (&n < la)
		la = &n;

	// your implementation
	int f1 = 0, f2 = 1, f3;
	if (n <= 1)
		return 1;
	else {
		for (int i = 2; i <= n; i++) {
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
	}
	return f2;
}

int recursive_fibonacci(int n) {
	if (&n < la)
		la = &n;
// your implementation
	if (n == 0)
		return n;
	if (n == 1)
		return 1;
	else
		return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

