#include <iostream>
using namespace std;

class cSoPhuc {
private:
  double Real, Imaginary;

public:
  cSoPhuc() {};
  cSoPhuc(double thuc, double ao) {
    Real = thuc;
    Imaginary = ao;
  }

  void input(cSoPhuc &a, cSoPhuc &b);
  cSoPhuc sum(cSoPhuc a, cSoPhuc b);
  cSoPhuc difference(cSoPhuc a, cSoPhuc b);
  cSoPhuc product(cSoPhuc a, cSoPhuc b);
  cSoPhuc quotient(cSoPhuc a, cSoPhuc b);
  void output(cSoPhuc a);
};

void cSoPhuc::input(cSoPhuc &a, cSoPhuc &b) {
  cin >> a.Real >> a.Imaginary;
  cin >> b.Real >> b.Imaginary;
}

cSoPhuc cSoPhuc::sum(cSoPhuc a, cSoPhuc b) {
  return cSoPhuc{a.Real + b.Real, a.Imaginary + b.Imaginary};
}

cSoPhuc cSoPhuc::difference(cSoPhuc a, cSoPhuc b) {
  return cSoPhuc{a.Real - b.Real, a.Imaginary - b.Imaginary};
}

cSoPhuc cSoPhuc::product(cSoPhuc a, cSoPhuc b) {
  return cSoPhuc{a.Real * b.Real - a.Imaginary * b.Imaginary,
                 a.Real * b.Imaginary + a.Imaginary * b.Real};
}

cSoPhuc cSoPhuc::quotient(cSoPhuc a, cSoPhuc b) {
  double mauSo = b.Real * b.Real + b.Imaginary * b.Imaginary;
  return cSoPhuc{(a.Real * b.Real + a.Imaginary * b.Imaginary) / mauSo,
                 (a.Imaginary * b.Real - a.Real * b.Imaginary) / mauSo};
}

void cSoPhuc::output(cSoPhuc a) {

  if (a.Imaginary < 0)
    cout << a.Real << " - " << -a.Imaginary << "i" << endl;
  else
    cout << a.Real << " + " << a.Imaginary << "i" << endl;
}

int main() {
  cSoPhuc sophuc1, sophuc2, nigga;
  nigga.input(sophuc1, sophuc2);

  cSoPhuc ressum = nigga.sum(sophuc1, sophuc2);
  cSoPhuc resdifference = nigga.difference(sophuc1, sophuc2);
  cSoPhuc resproduct = nigga.product(sophuc1, sophuc2);
  cSoPhuc resquotient = nigga.quotient(sophuc1, sophuc2);

  cout << "tong: ";
  nigga.output(ressum);

  cout << "hieu: ";
  nigga.output(resdifference);

  cout << "tich: ";
  nigga.output(resproduct);

  cout << "thuong: ";
  nigga.output(resquotient);

  return 0;
}
