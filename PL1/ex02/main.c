#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {

  printf("I'm..\n");

  pid_t filho1 = fork();

  wait(NULL);

  if (filho1 > 0){
    printf("the..\n");
    pid_t filho2 = fork();
    wait(NULL);
    if (filho2 == 0) {
      printf("filho2\n");
    } else {
      printf("father\n");
      pid_t filho3 = fork();
      wait(NULL);
      if(filho3 == 0) {
        printf("filho3\n");
      }
    }
  } else {
    printf("filho1\n");
  }
}
