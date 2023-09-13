/*
 * Filename: write.c
 * Path: assignment-1-Lucasgb7/finder-app
 * Created Date: Friday, August 25th 2023, 11:25:33 am
 * Author: Lucasgb7
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )  {
  openlog("writec", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

  // Check if number of arguments are correct
  if( argc != 3 ) {
    syslog(LOG_ERR, "Usage: writer <path> <string>");
    closelog();
    return 1;
   }

  // Extract arguments
  char *file = argv[1];
  char *str = argv[2];
  // File descriptor: fd
  int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC | S_IRWXU);
  if (fd == -1) {
    syslog(LOG_ERR, "Error! Failed on opening file: %s", strerror(errno));
    closelog();
    return 1;
  }

  // Write str on specified file
  ssize_t bytes = write(fd, str, strlen(str));
  if (bytes == -1) {
    syslog(LOG_ERR, "Error! Failed on writing to file: %s", strerror(errno));
    close(fd);
    closelog();
    return 1;
  }
  
  close(fd);
  syslog(LOG_DEBUG, "Writing %s to %s", str, file);
  closelog();
  return 0;
} 

