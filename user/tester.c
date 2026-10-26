#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


int
main(int argc, char *argv[])
{
  printf(1, "getpid has been called: %d times!\n", firstpart());
  exit();
}
