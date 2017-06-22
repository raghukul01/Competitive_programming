// Calculates the exponent in log n time using squares at every step

double fastpow(double x, int n){
	int ret = 1;
	while(n){
		//atleast once in the end n will become 1 or if its odd then we have to multiply by x 
		if(n%2 == 1) ret *= x;
		//now assuming that n is a multiple of 2 lets square x so that n becomes n/2
		x *= x;
		n = n/2;
	}
	return ret;
}