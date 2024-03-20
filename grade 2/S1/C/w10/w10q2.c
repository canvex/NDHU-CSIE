#include <stdio.h>

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point point[2];
    float slope;
} Line;

int main() {
    Line l;

    // 讀取第一條直線的資訊
    scanf("%f,%f,%f", &l.point[0].x, &l.point[0].y, &l.slope);

    // 讀取第二個點的座標
    scanf("%f,%f", &l.point[1].x, &l.point[1].y);

    // 檢查第二點是否在給定斜率的直線上
    if ((l.point[1].y - l.point[0].y) / (l.point[1].x - l.point[0].x) ==
        l.slope)
        printf("Yes");
    else
        printf("No");

    return 0;
}
