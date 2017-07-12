//旋转270度
static void LCD_rotate270(T_U16*dst, T_U16*src, int w_max, int h_max,
                                       int x, int y, int w, int h)
{
   int src_w;
   int src_h;
   T_U16*src_p;
   int dst_l;

   src  += y * w_max + x;
   dst  +=  w_max*h_max - 1;
   
   dst  -= (w_max-x-w ) * h_max + y;
   dst_l = h_max - h;

   for (src_w=w-1; src_w>=0; src_w--)
   {
       src_p = src + src_w;

       for (src_h=0; src_h<h; src_h++)
       {
           *dst-- = *src_p;
           src_p += w_max;
       }

       dst = dst - dst_l;
   }
}

//使用方法
/*
LCD_rotate270((T_U16 *)displayBuf, (T_U16 *)phys_buffer, 272, 480, 0, 0, 272, 480); 
displayBuf是要转换后要存储的buff
phys_buffer是输入源
*/

//旋转90度
static void LCD_rotate90(T_U8*dst, T_U8*src, int w_max, int h_max,
                                       int x, int y, int w, int h)
{
   int src_w;
   int src_h;
   T_U8*src_p;
   int dst_l;

   src  += y * w_max + x;
   dst  += (w_max-x-w ) * h_max + y;
   dst_l = h_max - h;

   for (src_w=w-1; src_w>=0; src_w--)
   {
       src_p = src + src_w;

       for (src_h=0; src_h<h; src_h++)
       {
           *dst++ = *src_p;
           src_p += w_max;
       }

       dst = dst + dst_l;
   }
}