#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

bool findInList(string str, list<string> l) {

    for(auto iter = l.begin(); iter != l.end(); iter++) {
        if( *iter == str ) {
            return 0;
        }
    }

    return 1;
}


long long int PowMod(int x, long long int power, long long int p) {
    long long int result = 1;

    for(int i = 1; i <= power; i++) {
        result = (result * x) % p;
    }
    return result % p;
}


long long int h(string str, int x, int m, long long int p) {

    int l = str.length();
    long long int hash = 0;

    for(int i = 0; i < l; i++) {
        hash = hash + ( ((int) str[i]) * PowMod(x, i, p) );
    }

    return (hash % p) % m;
}


void add(string str, int m, list<string>* H) {

    int hesh = h(str, 263, m, 1000000007);

    if( findInList(str, H[hesh]) ) {
        H[hesh].push_front(str);
    }
    else {
        return;
    }

}

void del(string str, int m, list<string>* H) {

    int hesh = h(str, 263, m, 1000000007);

    if( findInList(str, H[hesh]) ) {
        return;
    }
    else {
        auto iter = find(H[hesh].begin(), H[hesh].end(), str);
        H[hesh].erase(iter);
    }
}

void find(string str, int m, list<string>* H) {

    int hesh = h(str, 263, m, 1000000007);

    if( findInList(str, H[hesh]) ) {
        cout << "no" << endl;
        return;
    }
    else {
        cout << "yes" << endl;
        return;
    }

}

void check(int i, list<string>* H) {

    if( H[i].empty()) {
        cout << endl;
        return;
    }
    else {
        for(auto iter = H[i].begin(); iter != H[i].end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }

}



int main()
{
    int n, m, j;
    string str;
    string cmnd;
    list<string>* H;

    cin >> m;
    cin >> n;

    H = new list<string> [m];

    for(int i = 0; i < n; i++) {

        cin >> cmnd;

        if( cmnd == "add" ) {

            cin >> str;
            add(str, m, H);

        }
        if( cmnd == "del" ) {

            cin >> str;
            del(str, m, H);

        }
        if( cmnd == "find" ) {

            cin >> str;
            find(str, m, H);

        }
        if( cmnd == "check" ) {

            cin >> j;
            check(j, H);

        }

    }

    delete [] H;

    return 0;
}
