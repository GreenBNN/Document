#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[100];
int num;
int cnt= 0 ;
int state= 0 ;

int main(void) {
 
    scanf("%s", arr);

    num = strlen(arr); 

    for (int i = 0; i < num; i++) {   

        if (arr[i] == 'c' || arr[i] == 's' || arr[i] == 'z') {
            if (arr[i + 1] == '=' || arr[i + 1] == '-') {
                i++;
                cnt++;
            }
            else {
                cnt++;
            }
        }
        else if (arr[i] == 'n' || arr[i] == 'l') {
            if (arr[i + 1] == 'j') {
                i++;
                cnt++;
            }
            else {
                cnt++;
            }
        }
        else if (arr[i] == 'd') {
            if (arr[i + 1] == '-') {
                i++;
                cnt++;
            }
            else if (arr[i + 1] == 'z' && arr[i + 2] == '=') {
                i++;
                i++;
                cnt++;
            }
            else {
                cnt++;
            }
        }
        else 
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}