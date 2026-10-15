#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void handle_type(char *command) {
  char *commands[] = {"exit", "echo", "type"};

  for (int i = 0; i < (sizeof(commands) / 8); i++) {
    if (strcmp(command, commands[i]) == 0) {
      printf("%s is a shell builtin\n", command);
      return;
    }
  }

  char *PATH = strdup(getenv("PATH"));
  for (char *p = strtok(PATH, ":"); p != NULL; p = strtok(NULL, ":")) {
    char fp[1028];
    sprintf(fp, "%s/%s", p, command);
    if (access(fp, X_OK) == 0) {
      printf("%s is %s\n", command, fp);
      return;
    }
  }
  printf("%s not found\n", command);
}


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
    
    }else if (strncmp(command, "type ", 5) == 0){
      handle_type(command + 5);

    }else {
      printf("%s: command not found\n", command);
    }
  }

  return 0;
}