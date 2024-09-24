#include <bits/stdc++.h>

#define rep(i, m, n) for (int i = (m); i < (int)n; i++)

#ifdef DEBUG
#include "../debug.hpp"
#else
#define DWRITE(x)
#define DARRWRITE(x)
#endif

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int& e : h) {
        cin >> e;
    }

    vector<int> ans(n, 0);

    vector<int> stc = {};
    for(int i = n - 2; i >=0; i--) {
        while (! stc.empty()) {
            int j = stc[stc.size() - 1];
            if (h[j] < h[i+1])
                stc.pop_back();
            else 
                break;
        }
        stc.push_back(i + 1);
        ans[i] = stc.size();
    }

    rep(i, 0, n) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0; //
}
