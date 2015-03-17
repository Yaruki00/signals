#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define STDOUT_FILENO 1

void signal_handler( int no );

int main() {
  char buf[256];
  int ret;
  struct sigaction sa;

  sa.sa_handler = signal_handler;
  sa.sa_flags   = SA_RESTART;
  sigaction( SIGINT, &sa, 0 );

  int count = 0;
  while( 1 ) {
    printf( "%d\n", count++ );
    sleep( 1 );
  }

  return 0;

}

void signal_handler( int no ) {
  write( STDOUT_FILENO, "HAHAHA! INVALID SIGNAL!\n", 25 );
  write( STDOUT_FILENO, "stop 3 seconds\n", 16 );
  sleep(3);
}
