#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int classify_temperature(long temp) {
    if(temp >= 32 && temp <= 75) {
        return 0;
    } else if((temp > 0 && temp < 32) || (temp > 75 && temp <= 90)) {
        return 1;
    }
    return 2;
}

int main() {
    char input[20];
    char *endptr;
    long curr_temp;

    int num_readings = 0;
    int num_norm = 0;
    int num_warn = 0;
    int num_crit = 0;
    int above_avg = 0;
    long sum = 0;
    long max = LONG_MIN;
    long min = LONG_MAX;
    long temperatures[10];

    while(num_readings < 10) {
        printf("(You can enter up to %d more temperatures). Temperature: ", 10 - num_readings);

        if(scanf("%19s", input) != 1) {
            break;
        }

        if(strcmp(input, "q") == 0) {
            printf("Sensor monitor stopped.\n\n");
            break;
        }

        curr_temp = strtol(input, &endptr, 10);

        if(endptr == input || *endptr != '\0') {
            printf("invalid input - enter a number or q to quit:\n");
            continue;
        }
        
        temperatures[num_readings] = curr_temp;
        num_readings += 1;
    }
    int count = 0;

    printf("--READINGS--\n");
    while(count < num_readings) {
        printf("%ld\n", temperatures[count]);
        sum += temperatures[count];
        if(temperatures[count] > max) {
            max = temperatures[count];
        }
        if(temperatures[count] < min) {
            min = temperatures[count];
        }

        int class = classify_temperature(temperatures[count]);
        if(class == 0) {
            num_norm += 1;
        } else if(class == 1) {
            num_warn += 1;
        } else {
            num_crit += 1;
        }
        
        count += 1;
    }
    if(num_readings == 0) {
        printf("No readings recorded.");
        return 0;
    }

    double avg = (double)sum / num_readings;

    for(int c = 0; c < num_readings; c++) {
        if(temperatures[c] > avg) {
            above_avg += 1;
        }
    }

    printf("\nHighest: %ld\n", max);
    printf("Lowest: %ld\n", min);
    printf("Average: %.1f\n", avg);
    printf("Readings above average: %d\n", above_avg);
    printf("Normal readings: %d\n", num_norm);
    printf("Warning readings: %d\n", num_warn);
    printf("Critical readings: %d\n", num_crit);

    return 0;
}