//indicium 
// only for first test set

#include<bits/stdc++.h>
#include<string>
#define fast std::ios_base::sync_with_stdio(false);
#define ll long long int
#define T vector<int>
#define pb push_back
#define rep(i,n) for (int i = 0; i < n; ++i) 
#define repk(i,q,n) for (int i = q; i <= n; ++i) 
#define repkr(i,q,n) for (ll i = q; i >= n; --i) 

using namespace std;

int a[60][60];   //resultant matrix
int n;           //size of matrix
int k;           //sum of diagonal elements
int t;          //number of testcase
bool row[60][60];    //if row[2][3] is true that means 3 is present in row 2
bool column[60][60];  //if column[2][3] is true that means 3 is present in column 2
bool flag;              //flag for checking we got the result or not

void matrix(int r, int c, int m) {
    if (r == n && c == n + 1 && m == k && !flag) {   //printing result
        flag = true;
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        repk(i,1,n){
            repk(j,1,n) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } 
    else if (r > n) {   //return from n+1 th row
        return;
    } 
    else if (c > n) {    //go to next row
        matrix(r + 1, 1, m);
    }
    for (int i = 1; i <= n && !flag; ++i) {  //checking for every possible natural latin matrix,
                                             //if sum of diagonal value is k then we got the answer
        if (!row[r][i] && !column[c][i]) {
            row[r][i] = column[c][i] = true;
            if (r == c) {    //diagonal value, add it to m
                m += i;
            }
            a[r][c] = i;

            matrix(r, c + 1, m);  //go to next column
            
            // convert matrix to initial state if our condition are not satisfied
            row[r][i] = column[c][i] = false;
            if (r == c) {
                m -= i;   //decreasing value of m
            }
            a[r][c] = 0;
        }
    }
}

int main() {
    fast
    cin.tie(0);
    cout.tie(0);
    int p;     //number of test case
    cin >> p;
    for (t = 1; t <= p; ++t) {
        cin >> n >> k;
        matrix(1, 1, 0);
        if (!flag) {                                //checking for impossible matrix
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
        flag = false;
    }
    return 0;
}
