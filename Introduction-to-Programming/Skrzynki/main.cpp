//Michał Dudek
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    explicit UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // znalezienie reprezentanta zbioru
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // polaczenie zbiorow
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

int znajdzKlasy(int liczbaSkrzynek, const vector<int>& klucze) {
    UnionFind uf(liczbaSkrzynek);
    int rozbicia = liczbaSkrzynek;

    for (int i = 0; i < liczbaSkrzynek; i++) {
        int klucz = klucze[i];
        if (uf.find(i + 1) != uf.find(klucz)) {
            uf.unionSets(i + 1, klucz);
            rozbicia--;
        }
    }
    return rozbicia;
}

int main() {
    int liczbaSkrzynek;
    cin >> liczbaSkrzynek;

    vector<int> klucze(liczbaSkrzynek);
    for (int i = 0; i < liczbaSkrzynek; i++) {
        cin >> klucze[i];
    }

    int rozbicia = znajdzKlasy(liczbaSkrzynek, klucze);
    cout << rozbicia << endl;

    return 0;
}