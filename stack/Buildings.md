# ABC 372 D - Building

## 問題文

ビル 1, ビル 2, …, ビル $N$ の $N$ 棟のビルがこの順で一列に並んでいます。ビル $i (1≤i≤N)$ の高さは $H_i$ です。

各 $i=1,2,…,N$ について、次を満たす整数 $j (i \lt j \le N)$ の個数 $c_i$ を求めてください。

- ビル $i$ とビル $j$ の間にビル $j$ より高いビルが存在しない。

## 制約

- $1≤N≤2×10^5$
- $1 ≤ H_i ≤ N$
- $H_i \neq H_j (i \neq j)$
- 入力は全て整数

## 解説

以下, $i \in \textbraceleft 1, ..., N-1 \textbraceright$ とする.

常に変わらない出力が $2$ つある. 
それは, $i = N$に対する出力 $0$ と, $i = N-1$ に対する出力 $1$ である.
さらに, $i$ に対して, $i + 1$ は必ず条件を満たす.
そのため, 後ろから走査するのがよさそうだ.

ここで, 数列 $J_i$ を条件を満たす $j (\gt i)$ を昇順に並べた数列とする.
条件よりに対して, 以下が成り立つ:

1. $\forall k \in \textbraceleft 1, ..., c_i - 1 \textbraceright ,\quad H_{J_{i, k}} \lt H_{J_{i, k+1}}$
2. $\forall j \in J_{i + 1} ,\quad H_j \lt H_{i + 1} \Rightarrow j \notin J_i$
3. $\forall j \in J_{i + 1} ,\quad H_j \gt H_{i + 1} \Rightarrow j \in J_i$

これらを用いることで, 以下の方法で解を得られる:

$J_{i + 1}$ をスタックとして保持し, $1.$ より, 常にスタックの先頭と $H_{i + 1}$ 比較すればよい.

```
while stack が空でない         
    j := stackの先頭         
    if (h[j] > h[i + 1])       
        pop stack              
    else                       
        break                  

stack に i + 1 を push

ans[i] = stackのsize         
```

## 解答

```cpp
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
```
