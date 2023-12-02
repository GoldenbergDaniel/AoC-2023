#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"

u64 get_stream_len(FILE *stream);

i32 main(void)
{
  u64 in_len = get_stream_len(stdin);
  
  i8 *in = malloc(in_len);
  fread(in, 1, in_len, stdin);
  in = strncat(in, "\n", in_len);
  in_len++;

  i8 *res_str = malloc(16);
  i32 res_num = 0;
  u8 res_idx = 0;
  i32 sum = 0;

  for (u32 i = 0; i < in_len; i++)
  {
    i8 c = in[i];

    if (c >= 48 && c <= 57)
    {
      res_str[res_idx] = c;
      res_idx++;
    }

    if (in[i] == '\n')
    {
      res_num = res_num * 10 + (res_str[0] - 48);

      if (res_idx == 1)
      {
        res_num = res_num * 10 + (res_str[0] - 48);
      }
      else
      {
        res_num = res_num * 10 + (res_str[res_idx-1] - 48);
      }

      sum += res_num;

      res_num = 0;
      res_idx = 0;
    }
  }

  printf("%i\n", sum);
}

u64 get_stream_len(FILE *stream)
{
  fseek(stdin, 0, SEEK_END);
  u64 len = ftell(stdin);
  fseek(stdin, 0, SEEK_SET);

  return len;
}
