content
1. calculation of Euler Totient function
2. Binary Exponent
3. GCD and advanced Euclid 



Euler Function:

    phi(p) = p - 1  // if p is prime
    phi(p^a) = p^a - p^(a-1) // where p is prime
    phi(ab) = phi(a).phi(b) // if both a,b are relatively prime

    a^phi(m) = 1 (mod m) // where a,m are relatively prime

    let p = (p1^a1).(p2^a2).(p3^a3).(p4^a4)....
    then phi(p) = n.(1-1/p1).(1-1/p2)....

    // implementation based on above result
    int phi(int n) {
        int result = n;
        for(int i = 2;i*i <= n;i++)
            if(n%i == 0) {
                while(n%i == 0) n /= i;
                result -= result/i;
            }
        if(n > 1) result -= result/n;
        return result;
    } // O(sqrt(n))

Binary Exponent.

    if(n is even) a^n = a^(n/2).a^(n/2)
    else a^n = a.a^(n-1) // n-1 becomes even 

    // implementation used bit operations for optimisation
    int binpow (int a, int n) {
        int res = 1;
        while (n) {
            if (n & 1)
                res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    } 


GCD & advanced Euclid.

    __gcd(a,b) is an build in function that works for all type of no. (ll etc)


    lets find the solution of the (x1, y1)problem for the new pair (b%a, a)
    (b%a)x1 + a.y1 = g
    let ax + by = g
    so b%a = b - (b/a)*a
    using this in above expression we get expression of x,y in terms of x1,y1

    int gcd (int a, int b, int & x, int & y) {
        // ax + by = gcd(a,b)
        if (a == 0) {
            x = 0; y = 1;
            return b;
        }
        int x1, y1;
        int d = gcd (b%a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }


