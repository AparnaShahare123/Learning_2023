#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

// Define a structure to store log data
typedef struct {
    int entry_no;
    char sensor_no[MAX_LENGTH];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_LENGTH];
} LogEntry;

// Function to extract log entries from a CSV file
int read_log_file(const char* file_path, LogEntry* log_entries) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 0;
    }

    char line[MAX_LENGTH];
    fgets(line, sizeof(line), file); // Skip the header row

    int entry_count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token;
        token = strtok(line, ",");
        
        log_entries[entry_count].entry_no = atoi(token);
        token = strtok(NULL, ",");
        strcpy(log_entries[entry_count].sensor_no, token);
        token = strtok(NULL, ",");
        log_entries[entry_count].temperature = atof(token);
        token = strtok(NULL, ",");
        log_entries[entry_count].humidity = atoi(token);
        token = strtok(NULL, ",");
        log_entries[entry_count].light = atoi(token);
        token = strtok(NULL, ",");
        token[strcspn(token, "\r\n")] = '\0'; // Remove newline character
        strcpy(log_entries[entry_count].timestamp, token);

        entry_count++;
    }

    fclose(file);
    return entry_count;
}

// Function to display log entries
void display_log_entries(const LogEntry* log_entries, int entry_count) {
    for (int i = 0; i < entry_count; i++) {
        printf("EntryNo: %d\n", log_entries[i].entry_no);
        printf("SensorNo: %s\n", log_entries[i].sensor_no);
        printf("Temperature: %.1f\n", log_entries[i].temperature);
        printf("Humidity: %d\n", log_entries[i].humidity);
        printf("Light: %d\n", log_entries[i].light);
        printf("Timestamp: %s\n\n", log_entries[i].timestamp);
    }
}

int main() {
    LogEntry log_entries[MAX_ENTRIES];
    const char* log_file_path = "data.csv";

    int entry_count = read_log_file(log_file_path, log_entries);
    if (entry_count > 0) {
        display_log_entries(log_entries, entry_count);
    } else {
        printf("No log entries found.\n");
    }

    return 0;
}
