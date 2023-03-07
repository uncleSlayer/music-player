#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20

char command[100];

// size_t max_len
void get_command(char *command) {
  do {
    printf("Enter a command (open, pause, stop): \n");
    scanf("%s", command);
  } while ((strcmp(command, "open") != 0) && (strcmp(command, "close") != 0) &&
           (strcmp(command, "pause") != 0));
  return;
}

void play_audio(char *file_name) {
  char command[MAX_COMMAND_LENGTH + strlen(file_name) + 1];
  sprintf(command, "nohup mpg123 %s & \n", file_name);
  system(command);
  printf("Playing");
  char val[100];
  scanf("%s", val);
  if(strcmp(val, "stop") == 0){
	  system("pkill mpg123");
  };
  return;
}

int main(void) {
  printf("Program starts \n");
  // get_command(command);
  play_audio("audio.mp3");
  return 0;
}

