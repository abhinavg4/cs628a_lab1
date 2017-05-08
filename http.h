#pragma once

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>

const char *http_request_line(int fd, char *reqpath, size_t reqpath_len, char *env, size_t *env_len);

const char *http_request_headers(int fd);

void http_err(int fd, int code, char *fmt, ...);

void http_serve(int fd, const char *);

void http_serve_none(int fd, const char *);

void http_serve_file(int fd, const char *);

void http_serve_directory(int fd, const char *);

void http_serve_executable(int fd, const char *);

void http_set_executable_uid_gid(int uid, int gid);

void url_decode(char *dst, const char *src, int dst_len);

void env_deserialize(char *env, size_t len);

void fdprintf(int fd, char *fmt, ...);

ssize_t sendfd(int socket, const void *buffer, size_t length, int fd);

ssize_t recvfd(int socket, void *buffer, size_t length, int *fd);
