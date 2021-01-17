#include <bits/stdc++.h>
#define pb push_back

using namespace std;

class BigInt {
private:
  vector<int> bigInt;
public:
  void set(int&& a) {
    bigInt = getInt(a);
  }
  void set(int& a) {
    bigInt = getInt(a);
  }
  void set(long long&& a) {
    bigInt = getInt(a);
  }
  void set(long long& a) {
    bigInt = getInt(a);
  }
  void set(string&& a) {
    bigInt = getInt(a);
  }
  void set(string& a) {
    bigInt = getInt(a);
  }
  void set(char a[]) {
    bigInt = getInt(a);
  }
  void set(vector<int>& a) {
    while (a.size() > 1 && a.back() == 0)
      a.pop_back();
  }
  void print() {
    set(bigInt);
    printf("%d", (bigInt.size() == 0) ? 0 : bigInt.back());
    for (int i = bigInt.size() - 2; i >= 0; i--)
      printf("%09d", bigInt[i]);
  }
  vector<int> getInt(string s) {
    vector<int> ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) {ans.pb(0); return ans;}
    while (s.size() % 9 != 0)
      s = '0' + s;
    for (int i = 0; i < (int) s.size(); i += 9) {
      int v = 0;
      for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
      ans.insert(ans.begin(), v);
    }
    set(ans);
    return ans;
  }
  vector<int> getInt(char c[]) {
    return getInt(string(c));
  }
  vector<int> getInt(long long x) {
    string s = "";
    while (x) {
      s = char('0' + x % 10) + s;
      x /= 10;
    }
    return getInt(s);
  }
  vector<int> getInt(int x) {
    return getInt((long long) x);
  }
  friend istream &operator >> (istream& in, BigInt& a) {
    string s; getline(cin, s);
    a.bigInt = a.getInt(s);
    return in;
  }
  friend ostream &operator << (ostream& out, BigInt& a) {
    a.print();
    return out;
  }
  bool operator < (BigInt a) {
    set(bigInt);
    set(a.bigInt);
    if (bigInt.size() != a.bigInt.size()) return (bigInt.size() < a.bigInt.size());
    for (int i = bigInt.size() - 1; i >= 0; i--)
      if (bigInt[i] != a.bigInt[i]) return (bigInt[i] < a.bigInt[i]);
    return false;
  }
  bool operator > (BigInt a) {
    return (a < *this);
  }
  bool operator == (BigInt a) {
    return !(a < *this) && !(a > *this);
  }
};

int main() {
    BigInt B;  cin >> B;
    BigInt A;
    A.set("123456789");
    BigInt C;
    C.set(123456789ll);
    if (B < A) {
      cout << "B is less than A";
    } else if (B > A) {
      cout << "B is bigger than A";
    } else {
      cout << "Equal";
    }
    /*

    if (B <= A) cout << A - B;
    else {
        cout << "-";
        cout << B - A;
    }

    cout << A + B; Print(A + x);
    cout << A * B; Print(A * x);
    cout << A / B; Print(A / x);
    cout << A % B; printf("%d\n", A % x);

    C = ++A; ++B; C += B + x;
    Print(A); Print(B); Print(C);

    cout << max(A,B);
    cout << min(A,B);

    cout << gcd(A,B);
    cout << lcm(A,B);

    cout << sqrt(A);
    printf("%d %d %d\n", log(2,A), log(10,B), log(5,C));

    A = Integer(16); x = 12;
    cout << pow(A,B);
    cout << pow(A,x);
  */
  return 0;
}
