struct i { int x; };
int add(int, int);
int *inc(int *);
void decx(struct i*);
int getx(struct i);

int main(void) {
    int x = (0).add(1);
    int *y;
    *y = x.add(2);
    int z = y.add(3).add(4);
    x = x.inc().add(5);
    struct i a = { .x = 1 };
    a.decx();
    return a.getx();
}
