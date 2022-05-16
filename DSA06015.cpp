#include <bits/stdc++.h>
using namespace std;
int n, a[1000005];
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = a[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while (i < n1) {
        a[k++] = L[i++];
    }
    while (j < n2) {
        a[k++] = R[j++];
    }
}
void mergeSort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort (l, m);
        mergeSort (m + 1, r);
        merge (l, m, r);
    }
}
void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        mergeSort (0, n - 1);
        print ();
    }
    return 0;
}

