//
// Created by sry on 22-4-30.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
  int fd_1, fd_2, fd_3;
  fd_1 = socket(PF_INET, SOCK_STREAM, 0);
  fd_2 = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
  fd_3 = socket(PF_INET, SOCK_DGRAM, 0);

  printf("descriptor: %d\n", fd_1);
  printf("descriptor: %d\n", fd_2);
  printf("descriptor: %d\n", fd_3);

  close(fd_1);
  close(fd_2);
  close(fd_3);

  return 0;
}