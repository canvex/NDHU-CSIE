// #include <stdio.h>
// #include <string.h>

// char s1[1000], s2[1000];

// void init(){
//     scanf("%s %s", s1, s2);
// }
//

int main() {
    init();
    char* str = s1;
    char* key = s2;
    int count;

    // add your code here
    int str_len = strlen(str), key_len = strlen(key);

    for (int i = 0; i < str_len - key_len; i++) {
        int flag = 0;
        for (int j = 0; j < key_len; j++) {
            if (str[i + j] == key[j])
                flag = 1;
        }
        if (!flag)
            count++;
    }
    printf("%d", count);
    return 0;
}
