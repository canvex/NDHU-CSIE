#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char studentID[20];
    int programming, programmingLab, calculus, totalScore;
} Student;

int cmp(const void* a, const void* b) {
    return ((Student*)b)->totalScore - ((Student*)a)->totalScore;
}

int main() {
    int n;

    scanf("%d", &n);
    Student s[n];
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", s[i].studentID, &s[i].programming,
              &s[i].programmingLab, &s[i].calculus);
        s[i].totalScore =
            s[i].programming + s[i].programmingLab + s[i].calculus;
    }
    qsort(s, n, sizeof(Student), cmp);
    for (int i = 0; i < 6; i++) {
        printf("StdID: %s score is %d\n", s[i].studentID, s[i].totalScore);
        // printf("%s\n", s[i].studentID);
    }

    return 0;
}
