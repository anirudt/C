#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
static int j = 80;


void *tasker(void *arg) {
  pthread_t id = pthread_self();
  j += 10;
  if (pthread_equal(id, tid[0])) printf("First thread: %d\n", j); // Output: 90
  else                           printf("Second thread: %d\n", j); // Output: 100
  return NULL;
}

int main() {
  int i, ret; 
  ret = pthread_create(&(tid[0]), NULL, &tasker, NULL);
  sleep(5);
  ret = pthread_create(&(tid[1]), NULL, &tasker, NULL);
  sleep(5);
  printf("Has it changed? %d\n", j); // Output: 100
  return 0;
}
