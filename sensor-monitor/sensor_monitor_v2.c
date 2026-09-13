#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    char input[20]; // up to 20 char in buff mem
    char *endptr; // end pointer traverses user input - we can tell if the input is valid based on where it stops
    long curr_temp; // long > int

    // newvals
    int num_readings = 0;
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    int num_norm = 0;
    int num_warn = 0;
    int num_crit = 0;

    // always true and we explicitly break
    while(1) {
        printf("Temperature: ");

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
        } else {
            num_readings += 1;

            if(curr_temp >= 32 && curr_temp <= 75) {
                printf("NORMAL\n\n");
                num_norm += 1;
            } else if((curr_temp > 75 && curr_temp <= 90) || (curr_temp < 32 && curr_temp > 0)) {
                printf("WARNING\n\n");
                num_warn += 1;
            } else {
                printf("CRITICAL\n\n");
                num_crit += 1;
            }

            if(curr_temp > max) {
                max = curr_temp;
            }
            if(curr_temp < min) {
                min = curr_temp;
            }
            sum += curr_temp;
        }
        
    }
    if(num_readings == 0) {
        printf("No readings recorded.");
    } else {
        float avg = (float)sum / num_readings;
        printf("--- SESSION SUMMARY ---\n\n");
        printf("Readings: %d\n", num_readings);
        printf("Minimum: %d\n", min);
        printf("Maximum: %d\n", max);
        printf("Average: %.1f\n", avg);
        printf("Normal: %d\n", num_norm);
        printf("Warning: %d\n", num_warn);
        printf("Critical: %d\n", num_crit);
    }

    return 0;
}