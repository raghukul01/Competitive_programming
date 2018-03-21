int primeFactors[10000] = {0};
void primeFactorisation(int n) {
  int start = 0;
  for(int i = 0; ;i++) {
    if(prime[i] > n)break;
    else if(n % prime[i] != 0)continue;
    else {
      while(n % prime[i] == 0) n /= prime[i]; 
    }
  }
  return;
}
