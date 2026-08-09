#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

// 将一个字符串复制到另一个字符串中。
char* my_strcpy(char* dest, const char* source) {
    char *tmp = dest; // 保存头指针
    while((*dest++ = *source++) != '\0') {}
    return tmp;
}

// 将一个字符串追加到另一个字符串的末尾
char* my_strcat(char* dest, const char* source) {
    char *tmp = dest; // 保存头指针
    while(*dest != '\0') {
        *dest++;
    }
    while((*dest++ = *source++) != '\0'){}
    return tmp;
}

// 用于比较两个字符串的大小。 大于等于相等
int my_strcmp(const char* s1, const char* s2) {
    //
    while(*s1 != '\0' && *s2 != '\0') {
        // if(*s1 > *s2) {
        //     return 1;
        // } else if(*s1 < *s2) {
        //     return -1;
        // }
        if(*s1 == *s2) {
            *s1++;
            *s2++;
        } else {
            break;
        }
    }
    // return *(unsigned char *)s1 - *(unsigned char *)s2;  // 返回差值
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// 用于复制指定长度的字符串。
char *my_strncpy(char *dest, const char *src, size_t n) {
    if(dest == NULL || src == NULL) return NULL;
    char *res = dest;
    while(n > 0 && *src != '\0') {
        n--;
        *dest++ = *src++;
    }
    while(n > 0) {
        *dest++ = '\0';// 如果n未用完，填充'\0'
        n--;
    }
    return res; 
}

// 比较两个字符串的前n个字符是否相等-> 要注意超出边界问题(*(unsigned char *)s1) - (*(unsigned char *)s2);
// 全部转到0~255 这个区间进行比较
int my_strncmp(const char *s1, const char *s2, size_t n) {
    if(n == 0) {
        return 0;
    }
    while(n > 0 && *s1 != '\0' && *s2 != '\0') {
        // if(*s1 > *s2) {
        //     return 1;
        // } else if(*s1 < *s2) {
        //     return -1;
        // }
        if(*s1 == *s2) {
            *s1++;
            *s2++;
            n--;
        } else {
            break;
        }
    }

    if(n == 0) { // 看看比完了没有
        return 0; // 相等
    } else {
        return (*(unsigned char *)s1) - (*(unsigned char *)s2);
    }
}

//  内存拷贝，实现 将一个 内存块 的内容复制到另一个 内存块这一功能
void *my_memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while(n > 0) {
        *d++ = *s++;
        n--;
    }
    return dest;
}

// 对s1和s2两块存储区的前n个字节进行比较
int my_memcmp(const void *s1, const void *s2, size_t n) {
    const char *x = s1;
    const char *y = s2;
    while(n > 0) {
        if(*x > *y) {
            return 1;
        } else if(*x < *y) {
            return -1;
        }
        n--;
        *x++;
        *y++;
    }
    return 0; // 相等
}




int main() {
    // char a[] = "abcde";
    // char b[6] = "";
    // char *d = malloc(6);
    // // my_strcpy();
    // char *c = strcpy(b, a);
    // char *e = strcpy(d, a);
    // printf("%s\n%s\n", c, e);

    // char a[] = "abcde";
    // char b[6] = "";
    // char *c = my_strcpy(b, a);
    // printf("%s %s\n", c, b);

    // char a[10] = "abcde";
    // char b[4] = "fff";
    // char *c = my_strcat(a, b);
    // printf("%s %s\n", c, a);

    
    // char a[10] = "z";
    // char b[10] = "a";
    // strcmp(a, b);
    // printf("%d %d\n", strcmp(b, a), my_strcmp(b, a));

    // memcpy(dst, src, size);
    // char a[10] = "hello";
    // char b[10] = "";
    // char c[10] = "";
    // memcpy(b, a+1, 3);
    // my_memcpy(c, a+2, 3);
    // printf("%s %s\n", b, c);

    // char a[10] = "hellx";
    // char b[10] = "helloccc";
    // printf("%d %d\n", memcmp(a, b, 5), my_memcmp(a, b, 5));

    // char a[10] = "hellx";
    // char b[10] = "";
    // char c[10] = "";
    // char *x = strncpy(b, a, 8);
    // char *y = my_strncpy(c, a, 8);
    // // x[3] = '\0';
    // // y[3] = '\0';
    // printf("%s %s\n", x, y);

    // char a[10] = "hellxa";
    // char b[10] = "hellxazzzz";
    // printf("%d \n", strncmp(a, b, 7));
    // printf("%d \n", my_strncmp(a, b, 7));
    // char c = 'A';
    // if(isalnum(c)) {
    //     char d = tolower(c);
    //     printf("%c %c\n", c, d);
    // }
    // char s[100];
    // // scanf("%s", &s);
    // // printf("%s\n", s);
    // fgets(s, sizeof(s), stdin);
    // printf("%s\n", s);

    // FILE *file = fopen("a.txt", "w");
    // fprintf(file,"1234567\n");
    // fclose(file);

    // int a[5] = {1,2,3,4,5};
	// int *ptr = (int*)(&a+1); // 直接移动到数组后面的第一个地址了
	// printf("%d\n",*(a+1));
	// printf ("%d\n",*(ptr-1));

    // const char* s1 = "\x21";    // 1 字节
    // const char* s2 = "\test";   // 4 字节
    // const char* combined = "\x21, \test";  // 7 字节
    // printf("%d", strlen(s1));      // 1
    // printf("Length of \"\\test\": %zu\n", strlen(s2));     // 4
    // printf("Length of \"\\x21, \\test\": %zu\n", strlen(combined));  // 7

    short a = 32767;
    int b = a;
    a = a + 1;
    b = b + 1;
    printf ("%d %d\n", a, b);



    return 0;
}

