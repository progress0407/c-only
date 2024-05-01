#include "foo.h"
#include "bar.h"

int main() {
    int x = foo(bar());
    printf("result is %d\n", x);
    return 0;
}