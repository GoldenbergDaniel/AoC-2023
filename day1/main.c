#include <stdio.h>
#include <stdlib.h>

#include "../common.h"
#include "../string.h"

i32 main(void)
{
  String table[11] = {{0}, str("one"), str("two"), str("three"), str("four"), str("five"),
                           str("six"), str("seven"), str("eight"), str("nine"), str("ten")};

  FILE *in = stdin;

  String res_str = str_alloc(16);
  i32 res_num = 0;
  u8 res_idx = 0;
  i32 sum = 0;

  String line = str_alloc(1024);
  while (fgets(line.str, 1024, in) != NULL)
  {
    line.len = cstr_len(line.str)-1;

    for (u32 i = 0; i < line.len; i++)
    {
      i8 c = line.str[i];
      if (c >= 48 && c <= 57)
      {
        res_str.str[res_idx] = c;
        res_idx++;
      }

      for (u8 j = 1; j < 11; j++)
      {
        u64 end = line.len < table[j].len+i ? line.len : table[j].len+i;
        String substr = str_substr(line, i, end);
        if (str_contains(substr, table[j]))
        {
          res_str.str[res_idx] = j + 48;
          i += table[j].len - 2;
          res_idx++;
        }
      }
    }

    res_num = res_num * 10 + (res_str.str[0] - 48);

    if (res_idx == 1)
    {
      res_num = res_num * 10 + (res_str.str[0] - 48);
    }
    else
    {
      res_num = res_num * 10 + (res_str.str[res_idx-1] - 48);
    }

    sum += res_num;

    res_num = 0;
    res_idx = 0;
  }

  printf("%i\n", sum);
}
