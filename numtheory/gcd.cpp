Some facts:
– gcd(a, b) = gcd(a, b − a)
– gcd(a, 0) = a
– gcd(a, b) is the smallest positive number in {ax + by | x, y ∈ Z}

Runtime is O(log(A+B))
---------------------

int gcd(a,b){
	while(a){//reverses a and b automatically if a >= b
		int r = b % a; b = a; a = r;
	}
	return b;//when a becomes 0
}