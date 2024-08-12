#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    // Command to be executed
    char *command = "/bin/ls";  // Full path to the command (e.g., /bin/ls)
    
    // Arguments to pass to the command
    char *args[] = {"ls", "-la", NULL};  // First argument is the command name, followed by options
    
    // Environment variables (in this case, we're passing the current environment)
    extern char **environ;

    printf("Executing command: %s\n", command);
    
    // Execute the command using execve
    if (execve(command, args, environ) == -1) {
        perror("Error executing execve");
        exit(EXIT_FAILURE);
    }

    // This part of the code will not be reached unless execve fails
    printf("This line will only be printed if execve fails\n");

    return 0;
}

