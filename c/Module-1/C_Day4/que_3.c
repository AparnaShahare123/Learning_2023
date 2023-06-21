#include <stdio.h>


struct TimePeriod {
    int hours;
    int minutes;
    int seconds;
};


struct TimePeriod getTimeDifference(struct TimePeriod t1, struct TimePeriod t2) {
    struct TimePeriod diff;
    int totalSeconds1, totalSeconds2, diffSeconds;

    
    totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    
    diffSeconds = totalSeconds2 - totalSeconds1;

   
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct TimePeriod t1, t2, diff;

    
    printf("------Aparna Bhaskar Shahare-------\n");
    printf("Enter the first time period (hh mm ss): ");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

    
    printf("Enter the second time period (hh mm ss): ");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

    
    diff = getTimeDifference(t1, t2);

    
    printf("The difference is: %02d:%02d:%02d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}