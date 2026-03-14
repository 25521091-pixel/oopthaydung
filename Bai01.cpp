#include <iostream>
#include <numeric>
using namespace std;

class cPhanSo {
private:
  int Numerator, Denominator;

public:
  cPhanSo() {};
  cPhanSo(int tu, int mau) {
    Numerator = tu;
    Denominator = mau;
  }
  void input(cPhanSo &a, cPhanSo &b);
  cPhanSo sum(cPhanSo a, cPhanSo b);
  cPhanSo difference(cPhanSo a, cPhanSo b);
  cPhanSo product(cPhanSo a, cPhanSo b);
  cPhanSo quotient(cPhanSo a, cPhanSo b);
  void output(cPhanSo a);
};

void cPhanSo::input(cPhanSo &a, cPhanSo &b) {
  cin >> a.Numerator >> a.Denominator;
  cin >> b.Numerator >> b.Denominator;
}

cPhanSo cPhanSo::sum(cPhanSo a, cPhanSo b) {
  return cPhanSo{a.Numerator * b.Denominator + b.Numerator * a.Denominator,
                 a.Denominator * b.Denominator};
}
cPhanSo cPhanSo::difference(cPhanSo a, cPhanSo b) {
  return cPhanSo{a.Numerator * b.Denominator - b.Numerator * a.Denominator,
                 a.Denominator * b.Denominator};
}
cPhanSo cPhanSo::product(cPhanSo a, cPhanSo b) {
  return cPhanSo{a.Numerator * b.Numerator, a.Denominator * b.Denominator};
}
cPhanSo cPhanSo::quotient(cPhanSo a, cPhanSo b) {
  return cPhanSo{a.Numerator * b.Denominator, a.Denominator * b.Numerator};
}

void cPhanSo::output(cPhanSo a) {
  cout << a.Numerator << " " << a.Denominator << endl;
}
int main() {
  cPhanSo phanso1, phanso2, nig;
  nig.input(phanso1, phanso2);
  cPhanSo ressum = nig.sum(phanso1, phanso2);
  cPhanSo resdifference = nig.difference(phanso1, phanso2);
  cPhanSo resproduct = nig.product(phanso1, phanso2);
  cPhanSo resquotient = nig.quotient(phanso1, phanso2);
  cout << "tong: ";
  nig.output(ressum);
  cout << "hieu: ";
  nig.output(resdifference);
  cout << "tich: ";
  nig.output(resproduct);
  cout << "thuong: ";
  nig.output(resquotient);
  return 0;
}
