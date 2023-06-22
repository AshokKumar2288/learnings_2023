#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to store each entry
typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

// Function to extract data from CSV file
int extractData(const char *filename, LogEntry *logEntries);

// Function to display a single entry
void displayEntry(LogEntry *entry);

// Function to display all entries
void displayAllEntries(LogEntry *logEntries, int count);

int main() {
    const char *filename = "data.csv";
    LogEntry logEntries[MAX_ENTRIES];
    int count;

    // Extract data from CSV file
    count = extractData(filename, logEntries);

    // Display the extracted data
    if (count > 0) {
        displayAllEntries(logEntries, count);
    } else {
        printf("No data available.\n");
    }

    return 0;
}

int extractData(const char *filename, LogEntry *logEntries) {
    FILE *file;
    char line[100];
    char *token;
    int count = 0;

    // Open the CSV file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 0;
    }

    // Read each line in the file and extract the data
    while (fgets(line, sizeof(line), file) != NULL && count < MAX_ENTRIES) {
        // Tokenize the line using comma as the delimiter
        token = strtok(line, ",");

        // Extract and store the data in the structure
        logEntries[count].entryNo = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[count].sensorNo, token);
        token = strtok(NULL, ",");
        logEntries[count].temperature = atof(token);
        token = strtok(NULL, ",");
        logEntries[count].humidity = atoi(token);
        token = strtok(NULL, ",");
        logEntries[count].light = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[count].time, token);

        count++;
    }

    // Close the file
    fclose(file);

    return count;
}

void displayEntry(LogEntry *entry) {
    printf("EntryNo: %d\n", entry->entryNo);
    printf("SensorNo: %s\n", entry->sensorNo);
    printf("Temperature: %.1f\n", entry->temperature);
    printf("Humidity: %d\n", entry->humidity);
    printf("Light: %d\n", entry->light);
    printf("Time: %s\n", entry->time);
    printf("----------------------------------------\n");
}

void displayAllEntries(LogEntry *logEntries, int count) {
    int i;

    for (i = 0; i < count; i++) {
        displayEntry(&logEntries[i]);
    }
}
