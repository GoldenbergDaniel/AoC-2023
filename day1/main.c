#include <stdio.h>
#include <stdlib.h>

#include "ext/common.h"
#include "ext/string.h"

i32 main(void)
{
  String table[10] = 
  {
    str("one"), str("two"), str("three"), str("four"), str("five"),
    str("six"), str("seven"), str("eight"), str("nine"), str("ten")
  };

  i32 sum = 0;
  String nums_str = str_alloc(16);

  String line = str_alloc(1024);
  while (fgets(line.str, 1024, stdin) != NULL)
  {
    u8 nums_idx = 0;
    line.len = cstr_len(line.str)-1;

    for (u32 i = 0; i < line.len; i++)
    {
      i8 c = line.str[i];
      if (c >= 48 && c <= 57)
      {
        nums_str.str[nums_idx] = c;
        nums_idx++;
      }

      for (u8 j = 0; j < 10; j++)
      {
        if (line.len < table[j].len + i) continue;

        String substr = str_substr(line, i, i + table[j].len);
        if (str_contains(substr, table[j]))
        {
          nums_str.str[nums_idx] = j+49;
          i += table[j].len-2;
          nums_idx++;
        }
      }
    }

    i32 res_num = 0;
    res_num = res_num * 10 + (nums_str.str[0] - 48);

    if (nums_idx == 1)
    {
      res_num = res_num * 10 + (nums_str.str[0] - 48);
    }
    else
    {
      res_num = res_num * 10 + (nums_str.str[nums_idx-1] - 48);
    }

    sum += res_num;
  }

  printf("%i\n", sum);
}
