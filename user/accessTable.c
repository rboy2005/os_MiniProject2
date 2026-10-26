#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
int
main(int argc, char *argv[])
{
     struct pstat st;
     st.inuse[0] = 5;
     printf(1, "inuse[0]: %d\n", st.inuse[0]);
     exit();
}

