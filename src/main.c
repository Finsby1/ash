#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);


  while(1){
    printf("$ ");

    char command[1024];
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "exit") == 0){
      break;
    
    }else if (strncmp(command, "echo ", 5) == 0){
      printf("%s\n", command + 5);
    
    }else if (strcmp(command, "type ") == 0){
      char *args = command + 5;

      if (strcmp(arg, "echo") == 0 || strcmp(arg, "exit") == 0 || strcmp(arg, "type") == 0){
        printf("%s: is a shell builtin\n", arg);
      } else{
        printf("type: '%s' not found\n", arg);
      }

    }else {
      printf("%s: command not found\n", command);
    }
  }

  return 0;
}