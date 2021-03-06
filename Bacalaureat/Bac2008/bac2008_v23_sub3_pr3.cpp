// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_023.pdf

#include <iostream>
#include <fstream>

using namespace std;

/*
1 2 3 4
=======
2 3 4 1
3 4 1 2
4 1 2 3
=======
2 3 1
3 1 2
======
2 1

n = 4
3 seturi de permutari
primul set: 3 permutari
al doilea set: 2 permutari
al treilea set: 1 permutare

regula generala:
n - 1 seturi de permutari fiecare cu n - 1, n - 2, ... 1 permutari
*/

void shift(int inceput, int n, int x[100])
{
    int pe = x[inceput];
    for (int i = inceput; i < n - 1; ++i)
        x[i] = x[i + 1];

    x[n - 1] = pe;
}

int main()
{
    int n, x[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    for (int i = 0; i < n - 1; ++i)
    {
        for (int perm = n - 1 - i; perm >= 1; --perm)
            shift(i, n, x);
    }

    for (int i = 0; i < n; ++i)
        cout << x[i] << ' ';

    return 0;
}

