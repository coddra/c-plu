void main(void) {
    struct { int x; } *x;
    x.x = 1;
    x.x = x.x;
}