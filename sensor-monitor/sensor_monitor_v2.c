#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int classify_temperature(long temp) {
    if(temp >= 32 && temp <= 75) {
        return 0;
    } else if((temp > 75 && temp <= 90) || (temp < 32 && temp > 0)) {
        return 1;
    }
    return 2;
}

int main() {
    char input[20]; // up to 19 char in buff mem + '\0'
    char *endptr; // end pointer traverses user input - we can tell if the input is valid based on where it stops
    long curr_temp; // long > int

    // newvals
    int num_readings = 0;
    long sum = 0;
    long max = LONG_MIN;
    long min = LONG_MAX;
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
        }
        num_readings += 1;

        int category = classify_temperature(curr_temp);
        if(category == 0) {
            printf("NORMAL\n\n");
            num_norm += 1;
        } else if(category == 1) {
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
    if(num_readings == 0) {
        printf("No readings recorded.");
    } else {
        double avg = (double)sum / num_readings;
        printf("--- SESSION SUMMARY ---\n\n");
        printf("Readings: %d\n", num_readings);
        printf("Minimum: %ld\n", min);
        printf("Maximum: %ld\n", max);
        printf("Average: %.1f\n", avg);
        printf("Normal: %d\n", num_norm);
        printf("Warning: %d\n", num_warn);
        printf("Critical: %d\n", num_crit);
    }

    return 0;
}