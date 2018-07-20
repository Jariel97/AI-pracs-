#include <iostream>
using namespace std;

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    char u, v;
    int c, x, y;
    cin >> n >> m;
    cout << n << " "<< m << endl;
    cin >> u >> v;
    cout << u << " " << v << endl;
   
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        cout << u << " " << v << " " << c << endl;
    }
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        cout << u << " " << v << " " << endl;
    }
    fclose(stdin);
    return 0;
}
