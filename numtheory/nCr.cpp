//computing nCr mod p
// simply use the property nCr = (n-1)C(r-1)+(n-1)C(r)
//implement this using DP with 2D matrix of size n x r
//time complexity O(n*r)

int combination(int n, int r,int p) {
  int C[r+1][n] = {0};
  r = ((n-r) > r)?r:n-r;
   cout<<r;
   // C[i][j] represents (j+1)Ci
  for(int i = 0;i < n;i++) C[0][i] = 1;
  for(int i = 1;i <= r;i++) {
    for(int j = 0;j < n;j++) {
       if(j+1 < i) C[i][j] = 0;
       else if(j+1 == i) C[i][j] = 1;
       else C[i][j] = (C[i-1][j-1] + C[i][j-1])%p;
    }
  }
  return C[r][n-1];
}
