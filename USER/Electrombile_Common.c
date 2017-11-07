#include "electrombile_common.h"

void delay(uint32_t n)
{
    for(uint32_t i = n; i > 0; i--)
      for(uint32_t j = 1000; j > 0; j--);
}
