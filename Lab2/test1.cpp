#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string>
using namespace std;

#define MAX_LENGTH_COMMAND 300

#define MAX_NO_TASKS 100

#define MAX_LENGTH_TITLE 100
#define MAX_LENGTH_DESCRIPTION 200
#define MAX_LENGTH_TIME 33

#define WEEK_CELL_FIRST_COL_WIDTH 10
#define WEEK_CELL_OTHER_COL_WIDTH 20

enum Status
{
    IN_PROGRESS,
    DONE,
    ARCHIVED
};
char *status_name[] = {"In Progress", "Done", "Archived"};
enum CommandType
{
    ADD,
    EDIT,
    SHOW,
    DELETE,
    QUIT,
    INVALID
};
char *command_name[] = {"ADD", "EDIT", "SHOW", "DELETE", "QUIT", "INVALID"};

struct Task
{
    int num;
    char title[MAX_LENGTH_TITLE + 1];
    char description[MAX_LENGTH_DESCRIPTION + 1];
    char time[MAX_LENGTH_TIME + 1];
    enum Status status;
};

void printTask(struct Task *task)
{
    printf("--------------------------------------------\n");
    printf("Num: #%d. Title: %s\n", task->num, task->title);
    printf("Description: %s\n", task->description);
    printf("Status: %s\n", status_name[task->status]);
    printf("--------------------------------------------\n");
}

void printUnsupportedTime(struct Task *task)
{
    printf("----- Show week view -----\n");
    printf("Error: Unsupported time with non-zero minutes: %s\n", task->time);
    printf("In Task:\n");
    printTask(task);
}

// ------ Begin: Student Answer ------
enum CommandType getCommandType(char *command)
{
    // Convert the command string to uppercase for case-insensitive comparison
    for (int i = 0; command[i]; i++)
    {
        command[i] = toupper(command[i]);
    }

    for (int i = 0; i < INVALID; i++)
    {
        if (strcmp(command_name[i], command) == 0)
        {
            return (enum CommandType)i;
        }
    }

    return INVALID;
}

// Other functions

// ------ End: Student Answer ------

void runTodoApp()
{
    // Example of command Add
    char command[MAX_LENGTH_COMMAND + 1];

    while (true)
    {
        // Sample input:
        // Add [Course Intro to Programming] [Room 701-H6] [07:00|01/10/2023-12:00|01/10/2023]
        fgets(command, MAX_LENGTH_COMMAND + 1, stdin);
        command[strlen(command) - 1] = '\0';

        enum CommandType commandType = getCommandType(command);
        printf("Command     : %s\n", command);
        printf("Command type: %s\n", command_name[commandType]);

        break; // only one loop for simple test
               // actual app will break when encounter QUIT command
    }
}

int main()
{
    cout << getCommandType("QUIT") << endl;

    return 0;
}