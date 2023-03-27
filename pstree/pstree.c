#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define print(format, ...) fprintf(stderr, format, ##__VA_ARGS__)

int main(int argc, char *argv[]) {
  struct option long_options[] = {
      {"show-pids", optional_argument, NULL, 'p'},
      {"numeric-sort", optional_argument, NULL, 'n'},
      {"version", optional_argument, NULL, 'V'},
      {0, 0, 0, 0}};
  const char *option = "pnV";
  int option_index = 0;
  bool sorted = false;
  int arg;
  while ((arg = getopt_long(argc, argv, option, long_options, &option_index)) !=
         -1) {
    switch (arg) {
    case 'p': {
      sorted = true;
      break;
    }
    case 'n': {

      break;
    }
    case 'V': {
      print("my pstree, version 0.1\n");
      fflush(stderr);
      break;
    }
    default: {
      print("unkown args, check again\n");
      fflush(stderr);
      assert(0);
    };
    }
  }
  // get info in /proc/[pid]/stat
  if(sorted) {

  }
  return 0;
}
