#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int m;
vector<int> v;

pair<int, int> kadane() {
    m = -9999999;
    int curr = 0, a = 0, b = 0, aa = 1;
    for (int bb = 0; bb < v.size(); bb++) {
        curr += v[bb];
        if (curr >= m) {
            m = curr;
            a = aa + 1;
            b = bb + 1;
        }
        if (curr < 0) {
            curr = 0;
            aa = bb + 1;
        }
    }
    return make_pair(a,b);
}

int main() {
    int n, teste=1;
    while (cin >> n) {
        if (!n) break;
        while (n--) {
            int x, y;
            cin >> x >> y;
            v.push_back(x-y);
        }
        pair<int, int> p = kadane();
        cout << "Teste " << teste << endl;
        if (m > 0) cout << p.first << " " << p.second << endl << endl;
        else cout << "nenhum" << endl << endl;
        v.clear();
        teste++;
    }
    return 0;
}

