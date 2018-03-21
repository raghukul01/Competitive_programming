// problem code : SNGRAPH codechef

f
using namespace std;
int n = 100000;
vector<int> act[n],changed[n];
int deg[n];

int main() {
  int t,m;
  cin>>t;
  std::fill_n( deg, n, 0);
  while( t--) {
    cin>>n>>m;
    while(m--) {
      cin>>u>>v;
      act[u].push_back(v);
      act[v].push_back(u);
      deg[u]++;deg[v]++;
    }

  }

  return 0;
}
