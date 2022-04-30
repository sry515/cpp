//
// Created by sry on 22-4-30.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

const int kBufSize = 100;

void error_handling(const char *message);

int main() {
  int fd;
  char buf[kBufSize];

  fd = open("data.txt", O_RDONLY);
  if (fd == -1)
    error_handling("open() error");
  printf("file descriptor: %d\n", fd);

  if (read(fd, buf, sizeof buf) == -1)
    error_handling("read() error");
  close(fd);
  printf("file data: %s", buf);

  return 0;
}

void error_handling(const char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}