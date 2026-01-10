# C-PLU

Funky little extra features to C to make it even more fun.

*`c-plu` is based on the [`cproc`](https://git.sr.ht/~mcf/cproc/) compiler by [Michael Forney](https://git.sr.ht/~mcf/). See [cproc-README.md](cproc-README.md) for more details.*

Currently added features:
 - [auto dereferencing](#auto-dereferencing)
 - [dot syntax function call with auto lifting](#dotcall)
 - [auto union wrapping](#union-wrapping)

If any features break backwards compatibility, please let me know by opening an issue.

## Auto dereferencing

Given a pointer to a `struct`/`union`, using the `.` operator with an identifier will automatically dereference the pointer.

```C
struct location {
    int x;
    int y;
};

int main(void) {
    struct location *loc = malloc(sizeof(struct location));

    // works just fine
    loc.x = 0;
    loc.y = 0;

    return 0;
}
```

## DotCall

Dot syntax function call with auto lifting (DotCall for short) allows to locate the first parameter of a function call before the function.
Auto lifting refers to automatically taking the addres of that argument, if possible.

```C
int add(int x, int y) {
    return x + y;
}

int* inc(int *x) {
    ++*x;
    return x;
}

int main(void) {
    int x = 0;

    // works just fine
    x = x.add(34).add(35);

    // works just fine because of auto lifting
    x.inc().inc();

    // would not work, as cannot take address of literal
    //(0).inc();

    // auto dereferencing makes this possible
    int *y = malloc(sizeof(int));
    *y = y.add(10);

    return 0;
}
```

## Union wrapping

When an expression is used where a union is expected, and the union has a member of the type of the expression, the expression is automatically wrapped into a union.

```C
union u {
    int x;
    double y;
}

union u a = 2.5; // instead of {.y = 2.5}

void f(union u a) { }

void main() {
    union u a = 5; // instead of {.x = 5}
    f(10.0); // instead of (union u){.y = 10.0}
}
```
