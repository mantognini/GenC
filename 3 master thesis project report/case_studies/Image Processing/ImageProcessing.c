/* ------------------------------------ includes ----- */

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

/* -------------------------------- type aliases ----- */

typedef FILE* FileInputStream;
typedef clock_t TimePoint;
typedef void* State;
typedef FILE* FileOutputStream;

/* --------------------------------------- enums ----- */

typedef enum {
  tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32,
  tag_Result_0_Tuple_Tuple_int32_int32_int32_int32
} enum_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32;

typedef enum {
  tag_None_0_int8,
  tag_Some_0_int8
} enum_Option_0_int8;

typedef enum {
  tag_Failure_0_BitmapHeader_0,
  tag_Result_0_BitmapHeader_0
} enum_MaybeResult_0_BitmapHeader_0;

typedef enum {
  tag_Failure_0_Tuple_int32_int32_int32_int32,
  tag_Result_0_Tuple_int32_int32_int32_int32
} enum_MaybeResult_0_Tuple_int32_int32_int32_int32;

typedef enum {
  tag_Failure_0_Tuple_Tuple_int32_int32_int32,
  tag_Result_0_Tuple_Tuple_int32_int32_int32
} enum_MaybeResult_0_Tuple_Tuple_int32_int32_int32;

typedef enum {
  tag_Failure_0_FileHeader_0,
  tag_Result_0_FileHeader_0
} enum_MaybeResult_0_FileHeader_0;

typedef enum {
  tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0,
  tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0
} enum_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0;

typedef enum {
  tag_Failure_0_int32,
  tag_Result_0_int32
} enum_MaybeResult_0_int32;

typedef enum {
  tag_Failure_0_Tuple_int32_int32,
  tag_Result_0_Tuple_int32_int32
} enum_MaybeResult_0_Tuple_int32_int32;

typedef enum {
  tag_ReadError_0,
  tag_OpenError_0,
  tag_WriteError_0,
  tag_CorruptedDataError_0,
  tag_Success_0,
  tag_NotImplementedError_0,
  tag_DomainError_0,
  tag_ImageTooBigError_0,
  tag_InvalidBitmapHeaderError_0,
  tag_InvalidFileHeaderError_0
} enum_Status_0;

typedef enum {
  tag_Failure_0_Tuple_int32_int32_int32,
  tag_Result_0_Tuple_int32_int32_int32
} enum_MaybeResult_0_Tuple_int32_int32_int32;

/* ----------------------- data type definitions ----- */

typedef struct {
  int8_t extra;
} None_0_int8;

typedef struct {
  int8_t v_14;
} Some_0_int8;

typedef union {
  None_0_int8 None_0_int8_v;
  Some_0_int8 Some_0_int8_v;
} union_Option_0_int8;

typedef struct {
  enum_Option_0_int8 tag;
  union_Option_0_int8 value;
} Option_0_int8;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_Tuple_Tuple_int32_int32_int32;

typedef struct {
  int32_t _1;
  int32_t _2;
} Tuple_int32_int32;

typedef struct {
  Tuple_int32_int32 _1;
  int32_t _2;
} Tuple_Tuple_int32_int32_int32;

typedef struct {
  Tuple_Tuple_int32_int32_int32 result_0;
} Result_0_Tuple_Tuple_int32_int32_int32;

typedef union {
  Failure_0_Tuple_Tuple_int32_int32_int32 Failure_0_Tuple_Tuple_int32_int32_int32_v;
  Result_0_Tuple_Tuple_int32_int32_int32 Result_0_Tuple_Tuple_int32_int32_int32_v;
} union_MaybeResult_0_Tuple_Tuple_int32_int32_int32;

typedef struct {
  enum_MaybeResult_0_Tuple_Tuple_int32_int32_int32 tag;
  union_MaybeResult_0_Tuple_Tuple_int32_int32_int32 value;
} MaybeResult_0_Tuple_Tuple_int32_int32_int32;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_Tuple_int32_int32;

typedef struct {
  Tuple_int32_int32 result_0;
} Result_0_Tuple_int32_int32;

typedef union {
  Failure_0_Tuple_int32_int32 Failure_0_Tuple_int32_int32_v;
  Result_0_Tuple_int32_int32 Result_0_Tuple_int32_int32_v;
} union_MaybeResult_0_Tuple_int32_int32;

typedef struct {
  enum_MaybeResult_0_Tuple_int32_int32 tag;
  union_MaybeResult_0_Tuple_int32_int32 value;
} MaybeResult_0_Tuple_int32_int32;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_int32;

typedef struct {
  int32_t result_0;
} Result_0_int32;

typedef union {
  Failure_0_int32 Failure_0_int32_v;
  Result_0_int32 Result_0_int32_v;
} union_MaybeResult_0_int32;

typedef struct {
  enum_MaybeResult_0_int32 tag;
  union_MaybeResult_0_int32 value;
} MaybeResult_0_int32;

typedef struct {
  int32_t width_0;
  int32_t height_0;
} BitmapHeader_0;

typedef struct {
  int32_t _1;
  int32_t _2;
  int32_t _3;
} Tuple_int32_int32_int32;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_Tuple_int32_int32_int32;

typedef struct {
  Tuple_int32_int32_int32 result_0;
} Result_0_Tuple_int32_int32_int32;

typedef union {
  Failure_0_Tuple_int32_int32_int32 Failure_0_Tuple_int32_int32_int32_v;
  Result_0_Tuple_int32_int32_int32 Result_0_Tuple_int32_int32_int32_v;
} union_MaybeResult_0_Tuple_int32_int32_int32;

typedef struct {
  enum_MaybeResult_0_Tuple_int32_int32_int32 tag;
  union_MaybeResult_0_Tuple_int32_int32_int32 value;
} MaybeResult_0_Tuple_int32_int32_int32;

typedef struct {
  int8_t _1;
  int8_t _2;
} Tuple_int8_int8;

typedef struct {
  int8_t* data;
  int32_t length;
} array_int8;

typedef struct {
  array_int8 r_0;
  array_int8 g_0;
  array_int8 b_3;
  int32_t w_0;
  int32_t h_0;
} Image_0;

typedef struct {
  int32_t* data;
  int32_t length;
} array_int32;

typedef struct {
  int32_t size_2;
  int32_t scale_0;
  array_int32 kernel_0;
} Kernel_0;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_FileHeader_0;

typedef struct {
  int32_t size_1;
  int32_t offset_0;
} FileHeader_0;

typedef struct {
  FileHeader_0 result_0;
} Result_0_FileHeader_0;

typedef union {
  Failure_0_FileHeader_0 Failure_0_FileHeader_0_v;
  Result_0_FileHeader_0 Result_0_FileHeader_0_v;
} union_MaybeResult_0_FileHeader_0;

typedef struct {
  enum_MaybeResult_0_FileHeader_0 tag;
  union_MaybeResult_0_FileHeader_0 value;
} MaybeResult_0_FileHeader_0;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_BitmapHeader_0;

typedef struct {
  BitmapHeader_0 result_0;
} Result_0_BitmapHeader_0;

typedef union {
  Failure_0_BitmapHeader_0 Failure_0_BitmapHeader_0_v;
  Result_0_BitmapHeader_0 Result_0_BitmapHeader_0_v;
} union_MaybeResult_0_BitmapHeader_0;

typedef struct {
  enum_MaybeResult_0_BitmapHeader_0 tag;
  union_MaybeResult_0_BitmapHeader_0 value;
} MaybeResult_0_BitmapHeader_0;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_Tuple_FileHeader_0_BitmapHeader_0;

typedef struct {
  FileHeader_0 _1;
  BitmapHeader_0 _2;
} Tuple_FileHeader_0_BitmapHeader_0;

typedef struct {
  Tuple_FileHeader_0_BitmapHeader_0 result_0;
} Result_0_Tuple_FileHeader_0_BitmapHeader_0;

typedef union {
  Failure_0_Tuple_FileHeader_0_BitmapHeader_0 Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v;
  Result_0_Tuple_FileHeader_0_BitmapHeader_0 Result_0_Tuple_FileHeader_0_BitmapHeader_0_v;
} union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0;

typedef struct {
  enum_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 tag;
  union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 value;
} MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_Tuple_int32_int32_int32_int32;

typedef struct {
  int32_t _1;
  int32_t _2;
  int32_t _3;
  int32_t _4;
} Tuple_int32_int32_int32_int32;

typedef struct {
  Tuple_int32_int32_int32_int32 result_0;
} Result_0_Tuple_int32_int32_int32_int32;

typedef union {
  Failure_0_Tuple_int32_int32_int32_int32 Failure_0_Tuple_int32_int32_int32_int32_v;
  Result_0_Tuple_int32_int32_int32_int32 Result_0_Tuple_int32_int32_int32_int32_v;
} union_MaybeResult_0_Tuple_int32_int32_int32_int32;

typedef struct {
  enum_MaybeResult_0_Tuple_int32_int32_int32_int32 tag;
  union_MaybeResult_0_Tuple_int32_int32_int32_int32 value;
} MaybeResult_0_Tuple_int32_int32_int32_int32;

typedef struct {
  enum_Status_0 status_0;
} Failure_0_Tuple_Tuple_int32_int32_int32_int32;

typedef struct {
  Tuple_int32_int32_int32 _1;
  int32_t _2;
} Tuple_Tuple_int32_int32_int32_int32;

typedef struct {
  Tuple_Tuple_int32_int32_int32_int32 result_0;
} Result_0_Tuple_Tuple_int32_int32_int32_int32;

typedef union {
  Failure_0_Tuple_Tuple_int32_int32_int32_int32 Failure_0_Tuple_Tuple_int32_int32_int32_int32_v;
  Result_0_Tuple_Tuple_int32_int32_int32_int32 Result_0_Tuple_Tuple_int32_int32_int32_int32_v;
} union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32;

typedef struct {
  enum_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 tag;
  union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 value;
} MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32;

/* ----------------------- function declarations ----- */

static Option_0_int8 tryReadByte_2(FileInputStream thiss_41, State state_29);
static bool isDefined_3_int8(Option_0_int8 thiss_179);
static int32_t statusCode_0(enum_Status_0 s_0);
static bool isDefined_2_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_1);
static void log_2(BitmapHeader_0 h_2);
static void log_0(char* msg_0, int32_t x_6);
static void print_3(char c_3);
static bool close_2(FileInputStream thiss_38, State state_27);
static bool writeWord_0(FileOutputStream fos_1, int32_t word_0);
static MaybeResult_0_Tuple_Tuple_int32_int32_int32 combine_0_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32 a_0, MaybeResult_0_int32 b_0);
static MaybeResult_0_Tuple_int32_int32_int32_int32 combine_2_int32_int32_int32_int32(MaybeResult_0_int32 a_2, MaybeResult_0_int32 b_2, MaybeResult_0_int32 c_1, MaybeResult_0_int32 d_0);
static enum_Status_0 getStatus_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_3);
static int8_t apply_13(Kernel_0* thiss_11, array_int8 channel_1, int32_t width_4, int32_t height_4, int32_t index_3);
static Tuple_int32_int32 getResult_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_2);
static void apply_14(Kernel_0* thiss_12, Image_0* src_3, Image_0* dest_2);
static enum_Status_0 loadImageData_0(FileInputStream fis_6, Image_0* image_0, State state_11);
static bool writeLong_0(FileOutputStream fos_3, int32_t long_0);
static int32_t at_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t col_1, int32_t row_0);
static bool close_3(FileOutputStream thiss_46);
static int8_t impl_0(FileInputStream* thiss_41, State* state_29, bool* valid_0);
static bool writeBitmapHeader_0(FileOutputStream* fos_4, Image_0* image_1);
static int32_t min_1(int32_t x_1, int32_t y_0);
static bool isDefined_2_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_1);
static FileHeader_0 getResult_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_2);
static enum_Status_0 getStatus_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_3);
static bool writeFileHeader_0(FileOutputStream* fos_4, Image_0* image_1);
static int32_t _main(void);
static enum_Status_0 getStatus_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_3);
static MaybeResult_0_FileHeader_0 maybeReadFileHeader_0(FileInputStream fis_4, State state_9);
static int32_t buildInt_1(FileInputStream* fis_3, State* state_8, int8_t b1_7, int8_t b2_7, int8_t b3_2, int8_t b4_2);
static void log_1(FileHeader_0 h_1);
static int32_t clamp_0(int32_t x_3, int32_t down_0, int32_t up_0);
static Tuple_int32_int32_int32 getResult_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_2);
static TimePoint now_0(void);
static void print_0(char* x_9);
static MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 combine_0_Tuple_int32_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 a_0, MaybeResult_0_int32 b_0);
static bool writeBytes_0(FileOutputStream fos_0, int8_t byte_0, int32_t count_2);
static enum_Status_0 process_0(FileInputStream fis_7, FileOutputStream fos_5, State state_12);
static MaybeResult_0_Tuple_int32_int32_int32 combine_1_int32_int32_int32(MaybeResult_0_int32 a_1, MaybeResult_0_int32 b_1, MaybeResult_0_int32 c_0);
static int32_t buildInt_0(FileInputStream* fis_2, State* state_7, int8_t b1_5, int8_t b2_5, int8_t b3_0, int8_t b4_0);
static FileOutputStream open_1(char* filename_3);
static MaybeResult_0_int32 maybeReadLong_0(FileInputStream fis_3, State state_8);
static int32_t elapsedMillis_0(TimePoint first_0, TimePoint second_0);
static enum_Status_0 getStatus_1_int32(MaybeResult_0_int32 thiss_3);
static MaybeResult_0_int32 maybeReadWord_0(FileInputStream fis_1, State state_6);
static void println_0(char* s_6);
static int32_t constructWord_0(int8_t byte1_0, int8_t byte2_0);
static bool skipBytes_0(FileInputStream fis_0, int32_t count_1, State state_5);
static void println_4(void);
static int32_t max_1(int32_t x_2, int32_t y_1);
static FileInputStream open_0(char* filename_2, State state_13);
 int32_t main(int32_t argc, char** argv);
static enum_Status_0 saveImage_0(FileOutputStream fos_4, Image_0* image_1);
static bool isDefined_2_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_1);
static bool isDefined_2_int32(MaybeResult_0_int32 thiss_1);
static void print_2(int32_t x_12);
static bool isOpen_3(FileOutputStream thiss_47);
static void println_2(int32_t x_13);
static bool isEmpty_3_int8(Option_0_int8 thiss_177);
static MaybeResult_0_BitmapHeader_0 maybeReadBitmapHeader_0(FileInputStream fis_5, State state_10);
static int32_t fix_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t x_29, int32_t side_0);
static enum_Status_0 processImage_0(FileInputStream* fis_7, FileOutputStream* fos_5, State* state_12, Kernel_0* kernel_1, Image_0* src_2);
static MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 combine_0_FileHeader_0_BitmapHeader_0(MaybeResult_0_FileHeader_0 a_0, MaybeResult_0_BitmapHeader_0 b_0);
static BitmapHeader_0 getResult_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_2);
static MaybeResult_0_int32 maybeReadDword_0(FileInputStream fis_2, State state_7);
static enum_Status_0 getStatus_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_3);
static MaybeResult_0_Tuple_int32_int32 combine_0_int32_int32(MaybeResult_0_int32 a_0, MaybeResult_0_int32 b_0);
static bool writeDword_0(FileOutputStream fos_2, int32_t dword_0);
static bool writeImage_0(FileOutputStream* fos_4, Image_0* image_1);
static Tuple_int8_int8 destructWord_0(int32_t word_1);
static int32_t getResult_1_int32(MaybeResult_0_int32 thiss_2);
static State newState_0(void);
static bool isDefined_2_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_1);
static bool write_4(FileOutputStream thiss_48, int8_t x_181);
static bool isOpen_2(FileInputStream thiss_39);
static int8_t get_4_int8(Option_0_int8 thiss_174);
static bool isSuccess_1(enum_Status_0 thiss_0);

/* ------------------------ function definitions ----- */

static Option_0_int8 tryReadByte_2(FileInputStream thiss_41, State state_29) {
    bool valid_0 = true;
    int8_t res_9 = impl_0(&thiss_41, &state_29, &valid_0);
    if (valid_0) {
        return (Option_0_int8) { .tag = tag_Some_0_int8, .value = (union_Option_0_int8) { .Some_0_int8_v = (Some_0_int8) { .v_14 = res_9 } } };
    } else {
        return (Option_0_int8) { .tag = tag_None_0_int8, .value = (union_Option_0_int8) { .None_0_int8_v = (None_0_int8) { .extra = 0 } } };
    }
}

static bool isDefined_3_int8(Option_0_int8 thiss_179) {
    bool norm_9 = isEmpty_3_int8(thiss_179);
    return !norm_9;
}

static int32_t statusCode_0(enum_Status_0 s_0) {
    if (s_0 == tag_Success_0) {
        println_0("success");
        return 0;
    } else if (s_0 == tag_OpenError_0) {
        println_0("couldn't open file");
        return 1;
    } else if (s_0 == tag_ReadError_0) {
        println_0("couldn't read some expected data");
        return 2;
    } else if (s_0 == tag_DomainError_0) {
        println_0("integer out of range");
        return 3;
    } else if (s_0 == tag_InvalidFileHeaderError_0) {
        println_0("file format unsupported");
        return 4;
    } else if (s_0 == tag_InvalidBitmapHeaderError_0) {
        println_0("bitmap format unsupported");
        return 5;
    } else if (s_0 == tag_CorruptedDataError_0) {
        println_0("the file appears to be corrupted");
        return 6;
    } else if (s_0 == tag_ImageTooBigError_0) {
        println_0("the image is too big");
        return 7;
    } else if (s_0 == tag_WriteError_0) {
        println_0("couldn't write image");
        return 8;
    } else if (s_0 == tag_NotImplementedError_0) {
        println_0("not yet implemented");
        return 99;
    }
}

static bool isDefined_2_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_1) {
    if (thiss_1.tag == tag_Result_0_Tuple_int32_int32_int32) {
        return true;
    } else {
        return false;
    }
}

static void log_2(BitmapHeader_0 h_2) {
    log_0("width", h_2.width_0);
    log_0("height", h_2.height_0);
}

static void log_0(char* msg_0, int32_t x_6) {
    print_0(msg_0);
    print_0(": ");
    println_2(x_6);
}


static void print_3(char c) {
  printf("%c", c);
}
      


static bool close_2(FILE* this, void* unused) {
  if (this != NULL)
    return fclose(this) == 0;
  else
    return true;
}
    

static bool writeWord_0(FileOutputStream fos_1, int32_t word_0) {
    Tuple_int8_int8 tmp_5 = destructWord_0(word_0);
    Tuple_int8_int8 x$1_0 = (Tuple_int8_int8) { ._1 = tmp_5._1, ._2 = tmp_5._2 };
    int8_t b1_1 = x$1_0._1;
    int8_t b2_1 = x$1_0._2;
    bool norm_187 = write_4(fos_1, b2_1);
    bool norm_189 = norm_187;
    if (norm_189) {
        bool norm_188 = write_4(fos_1, b1_1);
        bool norm_190 = norm_188;
        return norm_190;
    } else {
        return false;
    }
}

static MaybeResult_0_Tuple_Tuple_int32_int32_int32 combine_0_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32 a_0, MaybeResult_0_int32 b_0) {
    if (isDefined_2_Tuple_int32_int32(a_0)) {
        if (isDefined_2_int32(b_0)) {
            Tuple_int32_int32 norm_91 = getResult_1_Tuple_int32_int32(a_0);
            Tuple_int32_int32 norm_93 = norm_91;
            int32_t norm_92 = getResult_1_int32(b_0);
            int32_t norm_94 = norm_92;
            Tuple_Tuple_int32_int32_int32 norm_95 = (Tuple_Tuple_int32_int32_int32) { ._1 = norm_93, ._2 = norm_94 };
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .tag = tag_Result_0_Tuple_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .Result_0_Tuple_Tuple_int32_int32_int32_v = (Result_0_Tuple_Tuple_int32_int32_int32) { .result_0 = norm_95 } } };
        } else {
            enum_Status_0 norm_96 = getStatus_1_int32(b_0);
            enum_Status_0 norm_97 = norm_96;
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32) { .status_0 = norm_97 } } };
        }
    } else {
        enum_Status_0 norm_98 = getStatus_1_Tuple_int32_int32(a_0);
        enum_Status_0 norm_99 = norm_98;
        return (MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32) { .status_0 = norm_99 } } };
    }
}

static MaybeResult_0_Tuple_int32_int32_int32_int32 combine_2_int32_int32_int32_int32(MaybeResult_0_int32 a_2, MaybeResult_0_int32 b_2, MaybeResult_0_int32 c_1, MaybeResult_0_int32 d_0) {
    MaybeResult_0_Tuple_int32_int32_int32 norm_103 = combine_1_int32_int32_int32(a_2, b_2, c_1);
    MaybeResult_0_Tuple_int32_int32_int32 norm_104 = norm_103;
    MaybeResult_0_int32 norm_105 = d_0;
    MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 tmp_1 = combine_0_Tuple_int32_int32_int32_int32(norm_104, norm_105);
    if (tmp_1.tag == tag_Result_0_Tuple_Tuple_int32_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32_int32) { .tag = tag_Result_0_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32_int32) { .Result_0_Tuple_int32_int32_int32_int32_v = (Result_0_Tuple_int32_int32_int32_int32) { .result_0 = (Tuple_int32_int32_int32_int32) { ._1 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._1._1, ._2 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._1._2, ._3 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._1._3, ._4 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._2 } } } };
    } else if (tmp_1.tag == tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32_int32) { .tag = tag_Failure_0_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32_int32) { .Failure_0_Tuple_int32_int32_int32_int32_v = (Failure_0_Tuple_int32_int32_int32_int32) { .status_0 = tmp_1.value.Failure_0_Tuple_Tuple_int32_int32_int32_int32_v.status_0 } } };
    }
}

static enum_Status_0 getStatus_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_3) {
    return thiss_3.value.Failure_0_Tuple_int32_int32_int32_v.status_0;
}

static int8_t apply_13(Kernel_0* thiss_11, array_int8 channel_1, int32_t width_4, int32_t height_4, int32_t index_3) {
    int32_t mid_2 = thiss_11->size_2 / 2;
    int32_t i_21 = index_3 % width_4;
    int32_t j_0 = index_3 / width_4;
    int32_t res_7 = 0;
    int32_t p_20 = -mid_2;
    while (p_20 <= mid_2) {
        int32_t q_1 = -mid_2;
        int32_t oldP_0 = p_20;
        while (q_1 <= mid_2) {
            int32_t kcol_0 = p_20 + mid_2;
            int32_t krow_0 = q_1 + mid_2;
            int32_t kidx_0 = krow_0 * thiss_11->size_2 + kcol_0;
            int32_t norm_159 = res_7;
            int32_t norm_156 = at_0(thiss_11, channel_1, &width_4, &height_4, &index_3, i_21 + p_20, j_0 + q_1);
            int32_t norm_157 = norm_156;
            int32_t norm_158 = thiss_11->kernel_0.data[kidx_0];
            int32_t norm_160 = norm_157 * norm_158;
            res_7 = norm_159 + norm_160;
            q_1 = q_1 + 1;
        }
        p_20 = p_20 + 1;
    }
    int32_t norm_161 = clamp_0(res_7 / thiss_11->scale_0, 0, 255);
    res_7 = norm_161;
    return (int8_t)res_7;
}

static Tuple_int32_int32 getResult_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_2) {
    return thiss_2.value.Result_0_Tuple_int32_int32_v.result_0;
}

static void apply_14(Kernel_0* thiss_12, Image_0* src_3, Image_0* dest_2) {
    int32_t size_8 = src_3->w_0 * src_3->h_0;
    int32_t i_22 = 0;
    while (i_22 < size_8) {
        int32_t norm_163 = i_22;
        int8_t norm_162 = apply_13(thiss_12, src_3->r_0, src_3->w_0, src_3->h_0, i_22);
        int8_t norm_164 = norm_162;
        dest_2->r_0.data[norm_163] = norm_164;
        int32_t norm_166 = i_22;
        int8_t norm_165 = apply_13(thiss_12, src_3->g_0, src_3->w_0, src_3->h_0, i_22);
        int8_t norm_167 = norm_165;
        dest_2->g_0.data[norm_166] = norm_167;
        int32_t norm_169 = i_22;
        int8_t norm_168 = apply_13(thiss_12, src_3->b_3, src_3->w_0, src_3->h_0, i_22);
        int8_t norm_170 = norm_168;
        dest_2->b_3.data[norm_169] = norm_170;
        i_22 = i_22 + 1;
    }
}

static enum_Status_0 loadImageData_0(FileInputStream fis_6, Image_0* image_0, State state_11) {
    int32_t size_5 = image_0->w_0 * image_0->h_0;
    int32_t i_19 = 0;
    enum_Status_0 status_23 = tag_Success_0;
    while (true) {
        bool norm_123 = isSuccess_1(status_23);
        bool norm_124 = norm_123;
        bool norm_126;
        if (norm_124) {
            bool norm_125 = i_19 < size_5;
            norm_126 = norm_125;
        } else {
            norm_126 = false;
        }
        if (norm_126) {
            Option_0_int8 rOpt_0 = tryReadByte_2(fis_6, state_11);
            Option_0_int8 gOpt_0 = tryReadByte_2(fis_6, state_11);
            Option_0_int8 bOpt_0 = tryReadByte_2(fis_6, state_11);
            bool norm_127 = isEmpty_3_int8(rOpt_0);
            bool norm_133 = norm_127;
            bool norm_135;
            if (norm_133) {
                norm_135 = true;
            } else {
                bool norm_128 = isEmpty_3_int8(gOpt_0);
                bool norm_130 = norm_128;
                bool norm_132;
                if (norm_130) {
                    norm_132 = true;
                } else {
                    bool norm_129 = isEmpty_3_int8(bOpt_0);
                    bool norm_131 = norm_129;
                    norm_132 = norm_131;
                }
                bool norm_134 = norm_132;
                norm_135 = norm_134;
            }
            if (norm_135) {
                status_23 = tag_ReadError_0;
                log_0("stopped reading data abruptly after", i_19);
            } else {
                int32_t norm_137 = i_19;
                int8_t norm_136 = get_4_int8(rOpt_0);
                int8_t norm_138 = norm_136;
                image_0->r_0.data[norm_137] = norm_138;
                int32_t norm_140 = i_19;
                int8_t norm_139 = get_4_int8(gOpt_0);
                int8_t norm_141 = norm_139;
                image_0->g_0.data[norm_140] = norm_141;
                int32_t norm_143 = i_19;
                int8_t norm_142 = get_4_int8(bOpt_0);
                int8_t norm_144 = norm_142;
                image_0->b_3.data[norm_143] = norm_144;
            }
            i_19 = i_19 + 1;
        } else {
            break;
        }
    }
    return status_23;
}

static bool writeLong_0(FileOutputStream fos_3, int32_t long_0) {
    int8_t b4_3 = (int8_t)((int32_t)(((uint32_t)long_0) >> 24));
    int8_t b3_3 = (int8_t)((int32_t)(((uint32_t)long_0) >> 16));
    int8_t b2_8 = (int8_t)((int32_t)(((uint32_t)long_0) >> 8));
    int8_t b1_8 = (int8_t)long_0;
    bool norm_210 = write_4(fos_3, b1_8);
    bool norm_220 = norm_210;
    if (norm_220) {
        bool norm_211 = write_4(fos_3, b2_8);
        bool norm_217 = norm_211;
        bool norm_219;
        if (norm_217) {
            bool norm_212 = write_4(fos_3, b3_3);
            bool norm_214 = norm_212;
            bool norm_216;
            if (norm_214) {
                bool norm_213 = write_4(fos_3, b4_3);
                bool norm_215 = norm_213;
                norm_216 = norm_215;
            } else {
                norm_216 = false;
            }
            bool norm_218 = norm_216;
            norm_219 = norm_218;
        } else {
            norm_219 = false;
        }
        bool norm_221 = norm_219;
        return norm_221;
    } else {
        return false;
    }
}

static int32_t at_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t col_1, int32_t row_0) {
    int32_t c_11 = fix_0(thiss_11, channel_1, width_4, height_4, index_3, col_1, *width_4);
    int32_t r_4 = fix_0(thiss_11, channel_1, width_4, height_4, index_3, row_0, *height_4);
    int8_t component_0 = channel_1.data[r_4 * (*width_4) + c_11];
    if (((int32_t)component_0) < 0) {
        return ((int32_t)component_0) + 255;
    } else {
        return (int32_t)component_0;
    }
}


static bool close_3(FILE* this) {
  if (this != NULL)
    return fclose(this) == 0;
  else
    return true;
}
    


static int8_t impl_0(FILE** this, void** unused, bool* valid) {
  int8_t x;
  *valid = fscanf(*this, "%c", &x) == 1;
  return x;
}
      

static bool writeBitmapHeader_0(FileOutputStream* fos_4, Image_0* image_1) {
    int32_t size_6 = 40;
    int32_t w_4 = image_1->w_0;
    int32_t h_7 = image_1->h_0;
    int32_t planes_0 = 1;
    int32_t bpp_1 = 24;
    int32_t comp_0 = 0;
    bool norm_209 = writeDword_0(*fos_4, size_6);
    bool norm_247 = norm_209;
    if (norm_247) {
        bool norm_222 = writeLong_0(*fos_4, w_4);
        bool norm_244 = norm_222;
        bool norm_246;
        if (norm_244) {
            bool norm_223 = writeLong_0(*fos_4, h_7);
            bool norm_241 = norm_223;
            bool norm_243;
            if (norm_241) {
                bool norm_224 = writeWord_0(*fos_4, planes_0);
                bool norm_238 = norm_224;
                bool norm_240;
                if (norm_238) {
                    bool norm_225 = writeWord_0(*fos_4, bpp_1);
                    bool norm_235 = norm_225;
                    bool norm_237;
                    if (norm_235) {
                        bool norm_226 = writeWord_0(*fos_4, comp_0);
                        bool norm_232 = norm_226;
                        bool norm_234;
                        if (norm_232) {
                            bool norm_231 = writeBytes_0(*fos_4, 0, 22);
                            bool norm_233 = norm_231;
                            norm_234 = norm_233;
                        } else {
                            norm_234 = false;
                        }
                        bool norm_236 = norm_234;
                        norm_237 = norm_236;
                    } else {
                        norm_237 = false;
                    }
                    bool norm_239 = norm_237;
                    norm_240 = norm_239;
                } else {
                    norm_240 = false;
                }
                bool norm_242 = norm_240;
                norm_243 = norm_242;
            } else {
                norm_243 = false;
            }
            bool norm_245 = norm_243;
            norm_246 = norm_245;
        } else {
            norm_246 = false;
        }
        bool norm_248 = norm_246;
        return norm_248;
    } else {
        return false;
    }
}

static int32_t min_1(int32_t x_1, int32_t y_0) {
    if (x_1 <= y_0) {
        return x_1;
    } else {
        return y_0;
    }
}

static bool isDefined_2_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_1) {
    if (thiss_1.tag == tag_Result_0_BitmapHeader_0) {
        return true;
    } else {
        return false;
    }
}

static FileHeader_0 getResult_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_2) {
    return thiss_2.value.Result_0_FileHeader_0_v.result_0;
}

static enum_Status_0 getStatus_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_3) {
    return thiss_3.value.Failure_0_FileHeader_0_v.status_0;
}

static bool writeFileHeader_0(FileOutputStream* fos_4, Image_0* image_1) {
    int32_t size_7 = 54 + (image_1->w_0 * image_1->h_0) * 3;
    int32_t reserved_0 = 0;
    int32_t offset_2 = 54;
    bool norm_171 = write_4(*fos_4, (int8_t)66);
    bool norm_206 = norm_171;
    if (norm_206) {
        bool norm_172 = write_4(*fos_4, (int8_t)77);
        bool norm_203 = norm_172;
        bool norm_205;
        if (norm_203) {
            bool norm_185 = writeDword_0(*fos_4, size_7);
            bool norm_200 = norm_185;
            bool norm_202;
            if (norm_200) {
                bool norm_191 = writeWord_0(*fos_4, reserved_0);
                bool norm_197 = norm_191;
                bool norm_199;
                if (norm_197) {
                    bool norm_192 = writeWord_0(*fos_4, reserved_0);
                    bool norm_194 = norm_192;
                    bool norm_196;
                    if (norm_194) {
                        bool norm_193 = writeDword_0(*fos_4, offset_2);
                        bool norm_195 = norm_193;
                        norm_196 = norm_195;
                    } else {
                        norm_196 = false;
                    }
                    bool norm_198 = norm_196;
                    norm_199 = norm_198;
                } else {
                    norm_199 = false;
                }
                bool norm_201 = norm_199;
                norm_202 = norm_201;
            } else {
                norm_202 = false;
            }
            bool norm_204 = norm_202;
            norm_205 = norm_204;
        } else {
            norm_205 = false;
        }
        bool norm_207 = norm_205;
        return norm_207;
    } else {
        return false;
    }
}

static int32_t _main(void) {
    State state_26 = newState_0();
    FileInputStream input_1 = open_0("input.bmp", state_26);
    FileOutputStream output_1 = open_1("output.bmp");
    bool norm_0 = isOpen_2(input_1);
    bool norm_2 = norm_0;
    bool norm_4;
    if (norm_2) {
        bool norm_1 = isOpen_3(output_1);
        bool norm_3 = norm_1;
        norm_4 = norm_3;
    } else {
        norm_4 = false;
    }
    enum_Status_0 norm_267;
    if (norm_4) {
        norm_267 = process_0(input_1, output_1, state_26);
    } else {
        norm_267 = tag_OpenError_0;
    }
    enum_Status_0 status_24 = norm_267;
    close_3(output_1);
    close_2(input_1, state_26);
    return statusCode_0(status_24);
}

static enum_Status_0 getStatus_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_3) {
    return thiss_3.value.Failure_0_Tuple_int32_int32_v.status_0;
}

static MaybeResult_0_FileHeader_0 maybeReadFileHeader_0(FileInputStream fis_4, State state_9) {
    bool skipSuccess_0 = skipBytes_0(fis_4, 2, state_9);
    MaybeResult_0_int32 sizeRes_0 = maybeReadDword_0(fis_4, state_9);
    bool norm_33 = skipSuccess_0;
    bool norm_35;
    if (norm_33) {
        bool norm_32 = skipBytes_0(fis_4, 2 * 2, state_9);
        bool norm_34 = norm_32;
        norm_35 = norm_34;
    } else {
        norm_35 = false;
    }
    skipSuccess_0 = norm_35;
    MaybeResult_0_int32 offsetRes_0 = maybeReadDword_0(fis_4, state_9);
    MaybeResult_0_Tuple_int32_int32 tmp_2 = combine_0_int32_int32(sizeRes_0, offsetRes_0);
    if (!skipSuccess_0) {
        return (MaybeResult_0_FileHeader_0) { .tag = tag_Failure_0_FileHeader_0, .value = (union_MaybeResult_0_FileHeader_0) { .Failure_0_FileHeader_0_v = (Failure_0_FileHeader_0) { .status_0 = tag_ReadError_0 } } };
    } else if (tmp_2.tag == tag_Failure_0_Tuple_int32_int32) {
        return (MaybeResult_0_FileHeader_0) { .tag = tag_Failure_0_FileHeader_0, .value = (union_MaybeResult_0_FileHeader_0) { .Failure_0_FileHeader_0_v = (Failure_0_FileHeader_0) { .status_0 = tmp_2.value.Failure_0_Tuple_int32_int32_v.status_0 } } };
    } else if (tmp_2.tag == tag_Result_0_Tuple_int32_int32) {
        if (14 <= tmp_2.value.Result_0_Tuple_int32_int32_v.result_0._1 && (54 <= tmp_2.value.Result_0_Tuple_int32_int32_v.result_0._2 && tmp_2.value.Result_0_Tuple_int32_int32_v.result_0._2 <= tmp_2.value.Result_0_Tuple_int32_int32_v.result_0._1)) {
            return (MaybeResult_0_FileHeader_0) { .tag = tag_Result_0_FileHeader_0, .value = (union_MaybeResult_0_FileHeader_0) { .Result_0_FileHeader_0_v = (Result_0_FileHeader_0) { .result_0 = (FileHeader_0) { .size_1 = tmp_2.value.Result_0_Tuple_int32_int32_v.result_0._1, .offset_0 = tmp_2.value.Result_0_Tuple_int32_int32_v.result_0._2 } } } };
        } else {
            return (MaybeResult_0_FileHeader_0) { .tag = tag_Failure_0_FileHeader_0, .value = (union_MaybeResult_0_FileHeader_0) { .Failure_0_FileHeader_0_v = (Failure_0_FileHeader_0) { .status_0 = tag_InvalidFileHeaderError_0 } } };
        }
    }
}

static int32_t buildInt_1(FileInputStream* fis_3, State* state_8, int8_t b1_7, int8_t b2_7, int8_t b3_2, int8_t b4_2) {
    return ((((int32_t)(((uint32_t)((int32_t)b4_2)) << 24)) | ((int32_t)(((uint32_t)(((int32_t)b3_2) & 255)) << 16))) | ((int32_t)(((uint32_t)(((int32_t)b2_7) & 255)) << 8))) | (((int32_t)b1_7) & 255);
}

static void log_1(FileHeader_0 h_1) {
    log_0("size", h_1.size_1);
    log_0("offset", h_1.offset_0);
}

static int32_t clamp_0(int32_t x_3, int32_t down_0, int32_t up_0) {
    int32_t norm_154 = down_0;
    int32_t norm_153 = min_1(x_3, up_0);
    int32_t norm_155 = norm_153;
    return max_1(norm_154, norm_155);
}

static Tuple_int32_int32_int32 getResult_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_2) {
    return thiss_2.value.Result_0_Tuple_int32_int32_int32_v.result_0;
}


TimePoint now_0(void) {
  return clock();
}
    


static void print_0(char* s) {
  printf("%s", s);
}
      

static MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 combine_0_Tuple_int32_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 a_0, MaybeResult_0_int32 b_0) {
    if (isDefined_2_Tuple_int32_int32_int32(a_0)) {
        if (isDefined_2_int32(b_0)) {
            Tuple_int32_int32_int32 norm_82 = getResult_1_Tuple_int32_int32_int32(a_0);
            Tuple_int32_int32_int32 norm_84 = norm_82;
            int32_t norm_83 = getResult_1_int32(b_0);
            int32_t norm_85 = norm_83;
            Tuple_Tuple_int32_int32_int32_int32 norm_86 = (Tuple_Tuple_int32_int32_int32_int32) { ._1 = norm_84, ._2 = norm_85 };
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .tag = tag_Result_0_Tuple_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .Result_0_Tuple_Tuple_int32_int32_int32_int32_v = (Result_0_Tuple_Tuple_int32_int32_int32_int32) { .result_0 = norm_86 } } };
        } else {
            enum_Status_0 norm_87 = getStatus_1_int32(b_0);
            enum_Status_0 norm_88 = norm_87;
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32_int32) { .status_0 = norm_88 } } };
        }
    } else {
        enum_Status_0 norm_89 = getStatus_1_Tuple_int32_int32_int32(a_0);
        enum_Status_0 norm_90 = norm_89;
        return (MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32_int32) { .status_0 = norm_90 } } };
    }
}

static bool writeBytes_0(FileOutputStream fos_0, int8_t byte_0, int32_t count_2) {
    if (count_2 == 0) {
        return true;
    } else {
        bool norm_227 = write_4(fos_0, byte_0);
        bool norm_229 = norm_227;
        if (norm_229) {
            bool norm_228 = writeBytes_0(fos_0, byte_0, count_2 - 1);
            bool norm_230 = norm_228;
            return norm_230;
        } else {
            return false;
        }
    }
}

static enum_Status_0 process_0(FileInputStream fis_7, FileOutputStream fos_5, State state_12) {
    int32_t norm_6 = 5;
    int32_t norm_7 = 1;
    int32_t leon_buffer_0[25] = { 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, -1, 8, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0 };
    array_int32 norm_5 = (array_int32) { .data = leon_buffer_0, .length = 25 };
    array_int32* norm_8 = &norm_5;
    Kernel_0 kernel_1 = (Kernel_0) { .size_2 = norm_6, .scale_0 = norm_7, .kernel_0 = (*norm_8) };
    MaybeResult_0_FileHeader_0 fileHeaderRes_0 = maybeReadFileHeader_0(fis_7, state_12);
    MaybeResult_0_BitmapHeader_0 bitmapHeaderRes_0 = maybeReadBitmapHeader_0(fis_7, state_12);
    MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 tmp_4 = combine_0_FileHeader_0_BitmapHeader_0(fileHeaderRes_0, bitmapHeaderRes_0);
    enum_Status_0 norm_266;
    if (tmp_4.tag == tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0) {
        norm_266 = tmp_4.value.Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v.status_0;
    } else if (tmp_4.tag == tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0 && tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._1.size_1 <= 54) {
        norm_266 = tag_CorruptedDataError_0;
    } else if (tmp_4.tag == tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0) {
        log_1(tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._1);
        log_2(tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2);
        int32_t toSkip_0 = tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._1.offset_0 - 32;
        bool success_2 = skipBytes_0(fis_7, toSkip_0, state_12);
        if (!success_2) {
            norm_266 = tag_CorruptedDataError_0;
        } else if (tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.width_0 > 512 || tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.height_0 > 512) {
            norm_266 = tag_ImageTooBigError_0;
        } else if (tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.width_0 * tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.height_0 > 262144) {
            norm_266 = tag_ImageTooBigError_0;
        } else {
            int8_t leon_buffer_1[262144] = { 0 };
            array_int8 norm_115 = (array_int8) { .data = leon_buffer_1, .length = 262144 };
            array_int8* norm_118 = &norm_115;
            int8_t leon_buffer_2[262144] = { 0 };
            array_int8 norm_116 = (array_int8) { .data = leon_buffer_2, .length = 262144 };
            array_int8* norm_119 = &norm_116;
            int8_t leon_buffer_3[262144] = { 0 };
            array_int8 norm_117 = (array_int8) { .data = leon_buffer_3, .length = 262144 };
            array_int8* norm_120 = &norm_117;
            int32_t norm_121 = tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.width_0;
            int32_t norm_122 = tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.height_0;
            Image_0 image_2 = (Image_0) { .r_0 = (*norm_118), .g_0 = (*norm_119), .b_3 = (*norm_120), .w_0 = norm_121, .h_0 = norm_122 };
            enum_Status_0 status_27 = loadImageData_0(fis_7, &image_2, state_12);
            if (isSuccess_1(status_27)) {
                norm_266 = processImage_0(&fis_7, &fos_5, &state_12, &kernel_1, &image_2);
            } else {
                norm_266 = status_27;
            }
        }
    }
    enum_Status_0 status_25 = norm_266;
    return status_25;
}

static MaybeResult_0_Tuple_int32_int32_int32 combine_1_int32_int32_int32(MaybeResult_0_int32 a_1, MaybeResult_0_int32 b_1, MaybeResult_0_int32 c_0) {
    MaybeResult_0_Tuple_int32_int32 norm_100 = combine_0_int32_int32(a_1, b_1);
    MaybeResult_0_Tuple_int32_int32 norm_101 = norm_100;
    MaybeResult_0_int32 norm_102 = c_0;
    MaybeResult_0_Tuple_Tuple_int32_int32_int32 tmp_0 = combine_0_Tuple_int32_int32_int32(norm_101, norm_102);
    if (tmp_0.tag == tag_Result_0_Tuple_Tuple_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32) { .tag = tag_Result_0_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32) { .Result_0_Tuple_int32_int32_int32_v = (Result_0_Tuple_int32_int32_int32) { .result_0 = (Tuple_int32_int32_int32) { ._1 = tmp_0.value.Result_0_Tuple_Tuple_int32_int32_int32_v.result_0._1._1, ._2 = tmp_0.value.Result_0_Tuple_Tuple_int32_int32_int32_v.result_0._1._2, ._3 = tmp_0.value.Result_0_Tuple_Tuple_int32_int32_int32_v.result_0._2 } } } };
    } else if (tmp_0.tag == tag_Failure_0_Tuple_Tuple_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32) { .tag = tag_Failure_0_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32) { .Failure_0_Tuple_int32_int32_int32_v = (Failure_0_Tuple_int32_int32_int32) { .status_0 = tmp_0.value.Failure_0_Tuple_Tuple_int32_int32_int32_v.status_0 } } };
    }
}

static int32_t buildInt_0(FileInputStream* fis_2, State* state_7, int8_t b1_5, int8_t b2_5, int8_t b3_0, int8_t b4_0) {
    return ((((int32_t)(((uint32_t)((int32_t)b4_0)) << 24)) | ((int32_t)(((uint32_t)(((int32_t)b3_0) & 255)) << 16))) | ((int32_t)(((uint32_t)(((int32_t)b2_5) & 255)) << 8))) | (((int32_t)b1_5) & 255);
}


static FILE* open_1(char* filename) {
  FILE* this = fopen(filename, "w");
  /* this == NULL on failure */
  return this;
}
    

static MaybeResult_0_int32 maybeReadLong_0(FileInputStream fis_3, State state_8) {
    Option_0_int8 byte1_4 = tryReadByte_2(fis_3, state_8);
    Option_0_int8 byte2_4 = tryReadByte_2(fis_3, state_8);
    Option_0_int8 byte3_1 = tryReadByte_2(fis_3, state_8);
    Option_0_int8 byte4_1 = tryReadByte_2(fis_3, state_8);
    bool norm_45 = isDefined_3_int8(byte1_4);
    bool norm_55 = norm_45;
    bool norm_57;
    if (norm_55) {
        bool norm_46 = isDefined_3_int8(byte2_4);
        bool norm_52 = norm_46;
        bool norm_54;
        if (norm_52) {
            bool norm_47 = isDefined_3_int8(byte3_1);
            bool norm_49 = norm_47;
            bool norm_51;
            if (norm_49) {
                bool norm_48 = isDefined_3_int8(byte4_1);
                bool norm_50 = norm_48;
                norm_51 = norm_50;
            } else {
                norm_51 = false;
            }
            bool norm_53 = norm_51;
            norm_54 = norm_53;
        } else {
            norm_54 = false;
        }
        bool norm_56 = norm_54;
        norm_57 = norm_56;
    } else {
        norm_57 = false;
    }
    if (norm_57) {
        int8_t norm_58 = get_4_int8(byte1_4);
        int8_t norm_62 = norm_58;
        int8_t norm_59 = get_4_int8(byte2_4);
        int8_t norm_63 = norm_59;
        int8_t norm_60 = get_4_int8(byte3_1);
        int8_t norm_64 = norm_60;
        int8_t norm_61 = get_4_int8(byte4_1);
        int8_t norm_65 = norm_61;
        int32_t long_1 = buildInt_1(&fis_3, &state_8, norm_62, norm_63, norm_64, norm_65);
        return (MaybeResult_0_int32) { .tag = tag_Result_0_int32, .value = (union_MaybeResult_0_int32) { .Result_0_int32_v = (Result_0_int32) { .result_0 = long_1 } } };
    } else {
        return (MaybeResult_0_int32) { .tag = tag_Failure_0_int32, .value = (union_MaybeResult_0_int32) { .Failure_0_int32_v = (Failure_0_int32) { .status_0 = tag_ReadError_0 } } };
    }
}


int32_t elapsedMillis_0(TimePoint first, TimePoint second) {
  return 1000 * (second - first) / CLOCKS_PER_SEC; // mind the order of operations!
}
    

static enum_Status_0 getStatus_1_int32(MaybeResult_0_int32 thiss_3) {
    return thiss_3.value.Failure_0_int32_v.status_0;
}

static MaybeResult_0_int32 maybeReadWord_0(FileInputStream fis_1, State state_6) {
    Option_0_int8 byte2_2 = tryReadByte_2(fis_1, state_6);
    Option_0_int8 byte1_2 = tryReadByte_2(fis_1, state_6);
    bool norm_70 = isDefined_3_int8(byte1_2);
    bool norm_72 = norm_70;
    bool norm_74;
    if (norm_72) {
        bool norm_71 = isDefined_3_int8(byte2_2);
        bool norm_73 = norm_71;
        norm_74 = norm_73;
    } else {
        norm_74 = false;
    }
    if (norm_74) {
        int8_t norm_76 = get_4_int8(byte1_2);
        int8_t norm_78 = norm_76;
        int8_t norm_77 = get_4_int8(byte2_2);
        int8_t norm_79 = norm_77;
        int32_t norm_80 = constructWord_0(norm_78, norm_79);
        int32_t norm_81 = norm_80;
        return (MaybeResult_0_int32) { .tag = tag_Result_0_int32, .value = (union_MaybeResult_0_int32) { .Result_0_int32_v = (Result_0_int32) { .result_0 = norm_81 } } };
    } else {
        return (MaybeResult_0_int32) { .tag = tag_Failure_0_int32, .value = (union_MaybeResult_0_int32) { .Failure_0_int32_v = (Failure_0_int32) { .status_0 = tag_ReadError_0 } } };
    }
}

static void println_0(char* s_6) {
    print_0(s_6);
    println_4();
}

static int32_t constructWord_0(int8_t byte1_0, int8_t byte2_0) {
    int32_t signed_0 = ((int32_t)(((uint32_t)((int32_t)byte1_0)) << 8)) | (((int32_t)byte2_0) & 255);
    int32_t norm_75;
    if (signed_0 < 0) {
        norm_75 = signed_0 + 65536;
    } else {
        norm_75 = signed_0;
    }
    int32_t unsigned_0 = norm_75;
    return unsigned_0;
}

static bool skipBytes_0(FileInputStream fis_0, int32_t count_1, State state_5) {
    int32_t i_18 = 0;
    bool success_0 = true;
    while (success_0 && i_18 < count_1) {
        Option_0_int8 opt_6 = tryReadByte_2(fis_0, state_5);
        bool norm_10 = isDefined_3_int8(opt_6);
        success_0 = norm_10;
        i_18 = i_18 + 1;
    }
    return success_0;
}

static void println_4(void) {
    print_3('\n');
}

static int32_t max_1(int32_t x_2, int32_t y_1) {
    if (x_2 < y_1) {
        return y_1;
    } else {
        return x_2;
    }
}


static FILE* open_0(char* filename, void* unused) {
  FILE* this = fopen(filename, "r");
  /* this == NULL on failure */
  return this;
}
    

 int32_t main(int32_t argc, char** argv) {
    return _main();
}

static enum_Status_0 saveImage_0(FileOutputStream fos_4, Image_0* image_1) {
    bool norm_208 = writeFileHeader_0(&fos_4, image_1);
    bool norm_263 = norm_208;
    bool norm_265;
    if (norm_263) {
        bool norm_249 = writeBitmapHeader_0(&fos_4, image_1);
        bool norm_260 = norm_249;
        bool norm_262;
        if (norm_260) {
            bool norm_259 = writeImage_0(&fos_4, image_1);
            bool norm_261 = norm_259;
            norm_262 = norm_261;
        } else {
            norm_262 = false;
        }
        bool norm_264 = norm_262;
        norm_265 = norm_264;
    } else {
        norm_265 = false;
    }
    if (norm_265) {
        return tag_Success_0;
    } else {
        return tag_WriteError_0;
    }
}

static bool isDefined_2_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_1) {
    if (thiss_1.tag == tag_Result_0_FileHeader_0) {
        return true;
    } else {
        return false;
    }
}

static bool isDefined_2_int32(MaybeResult_0_int32 thiss_1) {
    if (thiss_1.tag == tag_Result_0_int32) {
        return true;
    } else {
        return false;
    }
}


static void print_2(int32_t x) {
  printf("%"PRIi32, x);
}
     


static bool isOpen_3(FILE* this) {
  return this != NULL;
}
    

static void println_2(int32_t x_13) {
    print_2(x_13);
    println_4();
}

static bool isEmpty_3_int8(Option_0_int8 thiss_177) {
    if (thiss_177.tag == tag_Some_0_int8) {
        return false;
    } else if (thiss_177.tag == tag_None_0_int8) {
        return true;
    }
}

static MaybeResult_0_BitmapHeader_0 maybeReadBitmapHeader_0(FileInputStream fis_5, State state_10) {
    bool skipSuccess_1 = skipBytes_0(fis_5, 4, state_10);
    MaybeResult_0_int32 widthRes_0 = maybeReadLong_0(fis_5, state_10);
    MaybeResult_0_int32 heightRes_0 = maybeReadLong_0(fis_5, state_10);
    bool norm_67 = skipSuccess_1;
    bool norm_69;
    if (norm_67) {
        bool norm_66 = skipBytes_0(fis_5, 2, state_10);
        bool norm_68 = norm_66;
        norm_69 = norm_68;
    } else {
        norm_69 = false;
    }
    skipSuccess_1 = norm_69;
    MaybeResult_0_int32 bppRes_0 = maybeReadWord_0(fis_5, state_10);
    MaybeResult_0_int32 compressionRes_0 = maybeReadWord_0(fis_5, state_10);
    MaybeResult_0_Tuple_int32_int32_int32_int32 tmp_3 = combine_2_int32_int32_int32_int32(widthRes_0, heightRes_0, bppRes_0, compressionRes_0);
    if (!skipSuccess_1) {
        return (MaybeResult_0_BitmapHeader_0) { .tag = tag_Failure_0_BitmapHeader_0, .value = (union_MaybeResult_0_BitmapHeader_0) { .Failure_0_BitmapHeader_0_v = (Failure_0_BitmapHeader_0) { .status_0 = tag_ReadError_0 } } };
    } else if (tmp_3.tag == tag_Failure_0_Tuple_int32_int32_int32_int32) {
        return (MaybeResult_0_BitmapHeader_0) { .tag = tag_Failure_0_BitmapHeader_0, .value = (union_MaybeResult_0_BitmapHeader_0) { .Failure_0_BitmapHeader_0_v = (Failure_0_BitmapHeader_0) { .status_0 = tmp_3.value.Failure_0_Tuple_int32_int32_int32_int32_v.status_0 } } };
    } else if (tmp_3.tag == tag_Result_0_Tuple_int32_int32_int32_int32) {
        if (tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._1 < 0 || (tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._2 < 0 || (tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._3 != 24 || tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._4 != 0))) {
            log_0("width", tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._1);
            log_0("height", tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._2);
            log_0("bpp", tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._3);
            log_0("compression", tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._4);
            return (MaybeResult_0_BitmapHeader_0) { .tag = tag_Failure_0_BitmapHeader_0, .value = (union_MaybeResult_0_BitmapHeader_0) { .Failure_0_BitmapHeader_0_v = (Failure_0_BitmapHeader_0) { .status_0 = tag_InvalidBitmapHeaderError_0 } } };
        } else {
            return (MaybeResult_0_BitmapHeader_0) { .tag = tag_Result_0_BitmapHeader_0, .value = (union_MaybeResult_0_BitmapHeader_0) { .Result_0_BitmapHeader_0_v = (Result_0_BitmapHeader_0) { .result_0 = (BitmapHeader_0) { .width_0 = tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._1, .height_0 = tmp_3.value.Result_0_Tuple_int32_int32_int32_int32_v.result_0._2 } } } };
        }
    }
}

static int32_t fix_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t x_29, int32_t side_0) {
    return clamp_0(x_29, 0, side_0 - 1);
}

static enum_Status_0 processImage_0(FileInputStream* fis_7, FileOutputStream* fos_5, State* state_12, Kernel_0* kernel_1, Image_0* src_2) {
    TimePoint t1_0 = now_0();
    int8_t leon_buffer_4[262144] = { 0 };
    array_int8 norm_145 = (array_int8) { .data = leon_buffer_4, .length = 262144 };
    array_int8* norm_148 = &norm_145;
    int8_t leon_buffer_5[262144] = { 0 };
    array_int8 norm_146 = (array_int8) { .data = leon_buffer_5, .length = 262144 };
    array_int8* norm_149 = &norm_146;
    int8_t leon_buffer_6[262144] = { 0 };
    array_int8 norm_147 = (array_int8) { .data = leon_buffer_6, .length = 262144 };
    array_int8* norm_150 = &norm_147;
    int32_t norm_151 = src_2->w_0;
    int32_t norm_152 = src_2->h_0;
    Image_0 dest_1 = (Image_0) { .r_0 = (*norm_148), .g_0 = (*norm_149), .b_3 = (*norm_150), .w_0 = norm_151, .h_0 = norm_152 };
    apply_14(kernel_1, src_2, &dest_1);
    TimePoint t2_0 = now_0();
    int32_t ms_0 = elapsedMillis_0(t1_0, t2_0);
    print_0("Computation time: ");
    print_2(ms_0);
    println_0("ms.");
    return saveImage_0(*fos_5, &dest_1);
}

static MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 combine_0_FileHeader_0_BitmapHeader_0(MaybeResult_0_FileHeader_0 a_0, MaybeResult_0_BitmapHeader_0 b_0) {
    if (isDefined_2_FileHeader_0(a_0)) {
        if (isDefined_2_BitmapHeader_0(b_0)) {
            FileHeader_0 norm_106 = getResult_1_FileHeader_0(a_0);
            FileHeader_0 norm_108 = norm_106;
            BitmapHeader_0 norm_107 = getResult_1_BitmapHeader_0(b_0);
            BitmapHeader_0 norm_109 = norm_107;
            Tuple_FileHeader_0_BitmapHeader_0 norm_110 = (Tuple_FileHeader_0_BitmapHeader_0) { ._1 = norm_108, ._2 = norm_109 };
            return (MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .tag = tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0, .value = (union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .Result_0_Tuple_FileHeader_0_BitmapHeader_0_v = (Result_0_Tuple_FileHeader_0_BitmapHeader_0) { .result_0 = norm_110 } } };
        } else {
            enum_Status_0 norm_111 = getStatus_1_BitmapHeader_0(b_0);
            enum_Status_0 norm_112 = norm_111;
            return (MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .tag = tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0, .value = (union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v = (Failure_0_Tuple_FileHeader_0_BitmapHeader_0) { .status_0 = norm_112 } } };
        }
    } else {
        enum_Status_0 norm_113 = getStatus_1_FileHeader_0(a_0);
        enum_Status_0 norm_114 = norm_113;
        return (MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .tag = tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0, .value = (union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v = (Failure_0_Tuple_FileHeader_0_BitmapHeader_0) { .status_0 = norm_114 } } };
    }
}

static BitmapHeader_0 getResult_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_2) {
    return thiss_2.value.Result_0_BitmapHeader_0_v.result_0;
}

static MaybeResult_0_int32 maybeReadDword_0(FileInputStream fis_2, State state_7) {
    Option_0_int8 byte1_3 = tryReadByte_2(fis_2, state_7);
    Option_0_int8 byte2_3 = tryReadByte_2(fis_2, state_7);
    Option_0_int8 byte3_0 = tryReadByte_2(fis_2, state_7);
    Option_0_int8 byte4_0 = tryReadByte_2(fis_2, state_7);
    bool norm_11 = isDefined_3_int8(byte1_3);
    bool norm_21 = norm_11;
    bool norm_23;
    if (norm_21) {
        bool norm_12 = isDefined_3_int8(byte2_3);
        bool norm_18 = norm_12;
        bool norm_20;
        if (norm_18) {
            bool norm_13 = isDefined_3_int8(byte3_0);
            bool norm_15 = norm_13;
            bool norm_17;
            if (norm_15) {
                bool norm_14 = isDefined_3_int8(byte4_0);
                bool norm_16 = norm_14;
                norm_17 = norm_16;
            } else {
                norm_17 = false;
            }
            bool norm_19 = norm_17;
            norm_20 = norm_19;
        } else {
            norm_20 = false;
        }
        bool norm_22 = norm_20;
        norm_23 = norm_22;
    } else {
        norm_23 = false;
    }
    if (norm_23) {
        if (((int32_t)get_4_int8(byte4_0)) >= 0) {
            int8_t norm_24 = get_4_int8(byte1_3);
            int8_t norm_28 = norm_24;
            int8_t norm_25 = get_4_int8(byte2_3);
            int8_t norm_29 = norm_25;
            int8_t norm_26 = get_4_int8(byte3_0);
            int8_t norm_30 = norm_26;
            int8_t norm_27 = get_4_int8(byte4_0);
            int8_t norm_31 = norm_27;
            int32_t dword_2 = buildInt_0(&fis_2, &state_7, norm_28, norm_29, norm_30, norm_31);
            return (MaybeResult_0_int32) { .tag = tag_Result_0_int32, .value = (union_MaybeResult_0_int32) { .Result_0_int32_v = (Result_0_int32) { .result_0 = dword_2 } } };
        } else {
            return (MaybeResult_0_int32) { .tag = tag_Failure_0_int32, .value = (union_MaybeResult_0_int32) { .Failure_0_int32_v = (Failure_0_int32) { .status_0 = tag_DomainError_0 } } };
        }
    } else {
        return (MaybeResult_0_int32) { .tag = tag_Failure_0_int32, .value = (union_MaybeResult_0_int32) { .Failure_0_int32_v = (Failure_0_int32) { .status_0 = tag_ReadError_0 } } };
    }
}

static enum_Status_0 getStatus_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_3) {
    return thiss_3.value.Failure_0_BitmapHeader_0_v.status_0;
}

static MaybeResult_0_Tuple_int32_int32 combine_0_int32_int32(MaybeResult_0_int32 a_0, MaybeResult_0_int32 b_0) {
    if (isDefined_2_int32(a_0)) {
        if (isDefined_2_int32(b_0)) {
            int32_t norm_36 = getResult_1_int32(a_0);
            int32_t norm_38 = norm_36;
            int32_t norm_37 = getResult_1_int32(b_0);
            int32_t norm_39 = norm_37;
            Tuple_int32_int32 norm_40 = (Tuple_int32_int32) { ._1 = norm_38, ._2 = norm_39 };
            return (MaybeResult_0_Tuple_int32_int32) { .tag = tag_Result_0_Tuple_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32) { .Result_0_Tuple_int32_int32_v = (Result_0_Tuple_int32_int32) { .result_0 = norm_40 } } };
        } else {
            enum_Status_0 norm_41 = getStatus_1_int32(b_0);
            enum_Status_0 norm_42 = norm_41;
            return (MaybeResult_0_Tuple_int32_int32) { .tag = tag_Failure_0_Tuple_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32) { .Failure_0_Tuple_int32_int32_v = (Failure_0_Tuple_int32_int32) { .status_0 = norm_42 } } };
        }
    } else {
        enum_Status_0 norm_43 = getStatus_1_int32(a_0);
        enum_Status_0 norm_44 = norm_43;
        return (MaybeResult_0_Tuple_int32_int32) { .tag = tag_Failure_0_Tuple_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32) { .Failure_0_Tuple_int32_int32_v = (Failure_0_Tuple_int32_int32) { .status_0 = norm_44 } } };
    }
}

static bool writeDword_0(FileOutputStream fos_2, int32_t dword_0) {
    int8_t b4_1 = (int8_t)((int32_t)(((uint32_t)dword_0) >> 24));
    int8_t b3_1 = (int8_t)((int32_t)(((uint32_t)dword_0) >> 16));
    int8_t b2_6 = (int8_t)((int32_t)(((uint32_t)dword_0) >> 8));
    int8_t b1_6 = (int8_t)dword_0;
    bool norm_173 = write_4(fos_2, b1_6);
    bool norm_183 = norm_173;
    if (norm_183) {
        bool norm_174 = write_4(fos_2, b2_6);
        bool norm_180 = norm_174;
        bool norm_182;
        if (norm_180) {
            bool norm_175 = write_4(fos_2, b3_1);
            bool norm_177 = norm_175;
            bool norm_179;
            if (norm_177) {
                bool norm_176 = write_4(fos_2, b4_1);
                bool norm_178 = norm_176;
                norm_179 = norm_178;
            } else {
                norm_179 = false;
            }
            bool norm_181 = norm_179;
            norm_182 = norm_181;
        } else {
            norm_182 = false;
        }
        bool norm_184 = norm_182;
        return norm_184;
    } else {
        return false;
    }
}

static bool writeImage_0(FileOutputStream* fos_4, Image_0* image_1) {
    int32_t count_3 = image_1->w_0 * image_1->h_0;
    int32_t i_20 = 0;
    bool success_1 = true;
    while (success_1 && i_20 < count_3) {
        bool norm_250 = write_4(*fos_4, image_1->r_0.data[i_20]);
        bool norm_256 = norm_250;
        bool norm_258;
        if (norm_256) {
            bool norm_251 = write_4(*fos_4, image_1->g_0.data[i_20]);
            bool norm_253 = norm_251;
            bool norm_255;
            if (norm_253) {
                bool norm_252 = write_4(*fos_4, image_1->b_3.data[i_20]);
                bool norm_254 = norm_252;
                norm_255 = norm_254;
            } else {
                norm_255 = false;
            }
            bool norm_257 = norm_255;
            norm_258 = norm_257;
        } else {
            norm_258 = false;
        }
        success_1 = norm_258;
        i_20 = i_20 + 1;
    }
    return success_1;
}

static Tuple_int8_int8 destructWord_0(int32_t word_1) {
    int32_t norm_186;
    if (word_1 >= 32768) {
        norm_186 = word_1 - 65536;
    } else {
        norm_186 = word_1;
    }
    int32_t signed_1 = norm_186;
    int8_t b1_2 = (int8_t)((int32_t)(((uint32_t)signed_1) >> 8));
    int8_t b2_2 = (int8_t)signed_1;
    return (Tuple_int8_int8) { ._1 = b1_2, ._2 = b2_2 };
}

static int32_t getResult_1_int32(MaybeResult_0_int32 thiss_2) {
    return thiss_2.value.Result_0_int32_v.result_0;
}

static void* newState_0(void) { return NULL; }

static bool isDefined_2_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_1) {
    if (thiss_1.tag == tag_Result_0_Tuple_int32_int32) {
        return true;
    } else {
        return false;
    }
}


static bool write_4(FILE* this, int8_t x) {
  return fprintf(this, "%c", x) >= 0;
}
    


static bool isOpen_2(FILE* this) {
  return this != NULL;
}
    

static int8_t get_4_int8(Option_0_int8 thiss_174) {
    return thiss_174.value.Some_0_int8_v.v_14;
}

static bool isSuccess_1(enum_Status_0 thiss_0) {
    return thiss_0 == tag_Success_0;
}
