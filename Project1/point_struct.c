#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

void move_point(Point* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    Point* myPoint = malloc(sizeof(Point));  // ���� �Ҵ�
    myPoint->x = 5;
    myPoint->y = 10;

    printf("Original position: (%d, %d)\n", myPoint->x, myPoint->y);
    move_point(myPoint, 3, -2);
    printf("Moved position: (%d, %d)\n", myPoint->x, myPoint->y);

    free(myPoint);  // �Ҵ� ����
    return 0;
}