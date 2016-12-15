/* ------------------------------------ includes ----- */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

/* ---------------------- data type declarations ----- */

struct __leon_array_int32_t_t;
struct Kernel0;

/* ----------------------- data type definitions ----- */

typedef struct __leon_array_int32_t_t {
  int32_t* data;
  int32_t length;
} __leon_array_int32_t_t;

typedef struct Kernel0 {
  int32_t const size0;
  __leon_array_int32_t_t const buffer0;
} Kernel0;

/* ----------------------- function declarations ----- */

bool
isValidComponent0(int32_t const x0);

int32_t
getRed0(int32_t const rgb0);

int32_t
getGreen0(int32_t const rgb1);

int32_t
getBlue0(int32_t const rgb2);

int32_t
getGray0(int32_t const rgb3);

bool
testColorSinglePixel0(void);

bool
matches0(__leon_array_int32_t_t const value0, __leon_array_int32_t_t const expected0);

bool
testColorWholeImage0(void);

bool
isKernelValid0(Kernel0 const kernel0);

int32_t
up0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const x12);

int32_t
down0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const x13);

int32_t
fix0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const x14);

int32_t
at0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const row0, int32_t const col0);

int32_t
applyFilter0(__leon_array_int32_t_t const gray0, int32_t const size1, int32_t const idx0, Kernel0 const kernel1);

bool
testFilterConvolutionSmooth0(void);

int32_t
main(void);

/* ------------------------ function definitions ----- */

bool
isValidComponent0(int32_t const x0)
{
  return ((x0 >= 0) && (x0 <= 255));
}

int32_t
getRed0(int32_t const rgb0)
{
  return ((rgb0 & 16711680) >> 16);
}

int32_t
getGreen0(int32_t const rgb1)
{
  return ((rgb1 & 65280) >> 8);
}

int32_t
getBlue0(int32_t const rgb2)
{
  return (rgb2 & 255);
}

int32_t
getGray0(int32_t const rgb3)
{
  int32_t const __leon_normexec0 = getRed0(rgb3);
  int32_t const __leon_normexec1 = getGreen0(rgb3);
  int32_t const __leon_normexec2 = getBlue0(rgb3);
  return (((__leon_normexec0 + __leon_normexec1) + __leon_normexec2) / 3);
}

bool
testColorSinglePixel0(void)
{
  int32_t const color0 = 2146559;
  int32_t const __leon_normexec3 = getRed0(color0);
  if ((32 == __leon_normexec3))
  {
    int32_t const __leon_normexec4 = getGreen0(color0);
    if ((192 == __leon_normexec4))
    {
      int32_t const __leon_normexec5 = getBlue0(color0);
      if ((255 == __leon_normexec5))
      {
        int32_t const __leon_normexec6 = getGray0(color0);
        return (159 == __leon_normexec6);
      }
      else
      {
        return false;
      }

    }
    else
    {
      return false;
    }

  }
  else
  {
    return false;
  }

}

bool
matches0(__leon_array_int32_t_t const value0, __leon_array_int32_t_t const expected0)
{
  bool test0 = true;
  int32_t idx1 = 0;
  while ((idx1 < value0.length))
  {
    test0 = (test0 && (value0.data[idx1] == expected0.data[idx1]));
    idx1 = (idx1 + 1);
  }

  return test0;
}

bool
testColorWholeImage0(void)
{
  int32_t const WIDTH0 = 2;
  int32_t const HEIGHT0 = 2;
  int32_t __leon_buffer12[4] = { 2146559, 1193046, 16777215, 0 };
  __leon_array_int32_t_t const source0 = { .length = 4, .data = __leon_buffer12 };

  int32_t __leon_buffer13[4] = { 159, 52, 255, 0 };
  __leon_array_int32_t_t const expected1 = { .length = 4, .data = __leon_buffer13 };

  int32_t __leon_buffer14[4] = { 0, 0, 0, 0 };
  __leon_array_int32_t_t const gray1 = { .length = 4, .data = __leon_buffer14 };

  int32_t idx2 = 0;
  while ((idx2 < (WIDTH0 * HEIGHT0)))
  {
    int32_t const __leon_normexec7 = getGray0(source0.data[idx2]);
    gray1.data[idx2] = __leon_normexec7;
    idx2 = (idx2 + 1);
  }

  return matches0(gray1, expected1);
}

bool
isKernelValid0(Kernel0 const kernel0)
{
  return ((kernel0.size0 > 0) && (kernel0.size0 < 1000) && ((kernel0.size0 % 2) == 1) && (kernel0.buffer0.length == (kernel0.size0 * kernel0.size0)));
}

int32_t
up0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const x12)
{
  if ((x12 < 0))
  {
    return 0;
  }
  else
  {
    return x12;
  }

}

int32_t
down0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const x13)
{
  if ((x13 >= (*size1)))
  {
    return ((*size1) - 1);
  }
  else
  {
    return x13;
  }

}

int32_t
fix0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const x14)
{
  int32_t const __leon_normexec8 = up0(gray0, size1, idx0, kernel1, x14);
  return down0(gray0, size1, idx0, kernel1, __leon_normexec8);
}

int32_t
at0(__leon_array_int32_t_t const* gray0, int32_t const* size1, int32_t const* idx0, Kernel0 const* kernel1, int32_t const row0, int32_t const col0)
{
  int32_t const r3 = fix0(gray0, size1, idx0, kernel1, row0);
  int32_t const c2 = fix0(gray0, size1, idx0, kernel1, col0);
  return (*gray0).data[((r3 * (*size1)) + c2)];
}

int32_t
applyFilter0(__leon_array_int32_t_t const gray0, int32_t const size1, int32_t const idx0, Kernel0 const kernel1)
{
  int32_t const mid0 = (kernel1.size0 / 2);
  int32_t const i9 = (idx0 / size1);
  int32_t const j0 = (idx0 % size1);
  int32_t res2 = 0;
  int32_t p17 = (-mid0);
  while ((p17 <= mid0))
  {
    int32_t q0 = (-mid0);
    while ((q0 <= mid0))
    {
      int32_t const krow0 = (p17 + mid0);
      int32_t const kcol0 = (q0 + mid0);
      int32_t const kidx0 = ((krow0 * kernel1.size0) + kcol0);
      int32_t const __leon_normexec9 = at0((&gray0), (&size1), (&idx0), (&kernel1), (i9 + p17), (j0 + q0));
      res2 = (res2 + (__leon_normexec9 * kernel1.buffer0.data[kidx0]));
      q0 = (q0 + 1);
    }

    p17 = (p17 + 1);
  }

  return res2;
}

bool
testFilterConvolutionSmooth0(void)
{
  int32_t __leon_buffer15[4] = { 127, 255, 51, 0 };
  __leon_array_int32_t_t const gray2 = { .length = 4, .data = __leon_buffer15 };

  int32_t __leon_buffer16[4] = { 124, 158, 76, 73 };
  __leon_array_int32_t_t const expected2 = { .length = 4, .data = __leon_buffer16 };

  int32_t const size4 = 2;
  int32_t __leon_buffer17[9] = { 1, 1, 1, 1, 2, 1, 1, 1, 1 };
  __leon_array_int32_t_t const __leon_normexec10 = { .length = 9, .data = __leon_buffer17 };

  Kernel0 const kernel2 = (Kernel0) { .size0 = 3, .buffer0 = __leon_normexec10 };
  int32_t __leon_vla_buffer18[gray2.length];
  for (int32_t __leon_i19 = 0; __leon_i19 < gray2.length; ++__leon_i19) {
    __leon_vla_buffer18[__leon_i19] = 0;
  }
  __leon_array_int32_t_t const smoothed0 = { .length = gray2.length, .data = __leon_vla_buffer18 };

  int32_t idx3 = 0;
  while ((idx3 < smoothed0.length))
  {
    int32_t const __leon_normexec11 = applyFilter0(gray2, size4, idx3, kernel2);
    smoothed0.data[idx3] = (__leon_normexec11 / 10);
    idx3 = (idx3 + 1);
  }

  return matches0(smoothed0, expected2);
}

int32_t
main(void)
{
  if (testColorSinglePixel0())
  {
    if (testColorWholeImage0())
    {
      if (testFilterConvolutionSmooth0())
      {
        return 0;
      }
      else
      {
        return 1;
      }

    }
    else
    {
      return 1;
    }

  }
  else
  {
    return 1;
  }
}

