#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[20];
    int curr_temp;

    while(1) {
        printf("Temperature: ");

        if(scanf("%19s", input) != 1) {
            break;
        }

        if(strcmp(input, "q") == 0) {
            printf("Sensor monitor stopped.\n");
            break;
        }

        curr_temp = atoi(input);

        if(curr_temp > 32 && curr_temp < 75) {
            printf("NORMAL\n");
        } else if((curr_temp > 75 && curr_temp < 90) || (curr_temp < 32 && curr_temp > 0)) {
            printf("WARNING\n");
        } else {
            printf("CRITICAL\n");
        }
    }

    return 0;
}