#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int& e : h) {
        cin >> e;
    }

    vector<int> ans(n, 0);

    stack<int> stc = {};
    for(int i = n - 2; i >=0; i--) {
        while (! stc.empty()) {
            int j = stc.top();
            if (h[j] < h[i+1])
                stc.pop();
            else 
                break;
        }
        stc.push(i + 1);
        ans[i] = stc.size();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
