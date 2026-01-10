union u {
  int i;
  double f;
};

union u a = 2.5;

void g(union u x) { }

void f() {
  g(2);
}
