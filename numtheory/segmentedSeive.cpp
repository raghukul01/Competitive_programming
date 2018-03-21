// this approach is better than normal Seive that it uses only O(sqrt(n)) space
// and with this it is possible to get a large number of prime
// this function returns all primes less than n, stores them in a vector

vector<int> primes;
void generatePrimes(int n) {
  int root = sqrt(n);
  int a[root];
  fill_n(a,1);
  // we use simple seive for the first sqrt(n) numbers
  for(int i = 2;i <= root;i++) {
    if(a[i] == 0)continue;
    else {
      primes.push_back(i);
      for(int j = a[i];j < n;j += a[i]) a[j] = 0;
    }
  }

  for(int j = )
}
