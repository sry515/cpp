//
// Created by sry on 22-4-30.
//
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(const char *message);

int main(int argc, const char *argv[]) {
  if (argc != 3) {
    printf("Usage : %s <Ip> <port>", argv[0]);
    exit(1);
  }

  int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock == -1) error_handling("socket() error");

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(strtol(argv[2], NULL, 10));

  if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
    error_handling("connect() error");

  int idx = 0, str_len = 0, read_len;
  char message[30];
  while (read_len = (int) read(sock, &message[idx++], 1)) {
    if (read_len == -1) error_handling("read() error!");
    str_len += read_len;
  }

  printf("Message from serve : %s \n", message);
  printf("Function read call count: %d\n", str_len);
  close(sock);
  return 0;
}

void error_handling(const char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}