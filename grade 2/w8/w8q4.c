#include <stdio.h>

typedef struct {
    int sid, stdid, course;
} course;

typedef struct {
    int sid, score;
} score;

typedef struct {
    int stdid, score, num;
} fail;

int main() {
    int m, n, ans1 = 0, ans2 = 0, num = 0;
    scanf("%d %d", &m, &n);
    course c[m];
    score s[n];
    fail f[1001] = {0};
    int stdid[1001];
    // 輸入course資料
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &c[i].sid, &c[i].stdid, &c[i].course);
        ans1++;  // 計算學生數量
        for (int j = 0; j < i; j++) {
            if (c[i].stdid == c[j].stdid) {  // 如果發現輸入同個學生資料則刪除
                ans1--;
                break;
            }
        }
    }
    // 輸入score資料
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &s[i].sid, &s[i].score);
        f[s[i].sid].score += s[i].score;
        f[s[i].sid].num++;  // 計算學生修課數量
        for (int j = 0; j < m; j++) {
            if (s[i].sid == c[j].sid)
                f[s[i].sid].stdid = c[j].stdid;
        }
    }

    int flag = 0;  // 用來標記是否找到相同的學生學號
    for (int i = 0; i < 1001; i++) {
        if (f[i].num !=
            0) {  // 檢查是否有學生成績，避免對未修課的學生進行不必要的操作
            if (f[i].score / f[i].num < 60) {  // 判斷平均分數是否不及格
                for (int j = 0; j < num; j++) {
                    if (f[i].stdid ==
                        stdid[j]) {  // 檢查是否已經記錄過這個學生的不及格情況
                        flag = 1;  // 找到相同的學生學號，將 flag 設為 1
                        break;
                    }
                }
                if (!flag) {  // 如果沒有找到相同的學生學號
                    ans2++;   // 不及格學生人數加1
                    stdid[num] =
                        f[i].stdid;  // 將不及格學生的學號記錄在 stdid 陣列中
                    num++;  // 增加已記錄的不及格學生數目
                }
                flag =
                    0;  // 重置 flag 為 0，以便下一輪迴圈重新檢查相同學號的情況
            }
        }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}