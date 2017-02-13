/* ------------------------------------ includes ----- */

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* -------------------------------- type aliases ----- */

typedef FILE* FileInputStream;
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
  int8_t extra;
} None_0_int8;

typedef struct {
  int8_t v_13;
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

static void println_0(char* s_19);
static FileInputStream open_1(char* filename_3, State state_25);
static MaybeResult_0_Tuple_Tuple_int32_int32_int32 combine_0_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32 a_0, MaybeResult_0_int32 b_0);
static int32_t statusCode_0(enum_Status_0 s_0);
static bool isDefined_2_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_1);
static bool writeWord_0(FileOutputStream fos_1, int32_t word_0);
static void log_2(BitmapHeader_0 h_2);
static int32_t _main(void);
static void log_0(char* msg_0, int32_t x_6);
static void apply_14(Kernel_0* thiss_12, Image_0* src_3, Image_0* dest_2);
static FileOutputStream open_0(char* filename_2);
static enum_Status_0 getStatus_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_3);
static Tuple_int32_int32 getResult_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_2);
static int32_t clamp_0(int32_t x_3, int32_t down_0, int32_t up_0);
static int8_t impl_2(FileInputStream* thiss_116, State* state_29, bool* valid_2);
static bool isOpen_2(FileOutputStream thiss_108);
static int32_t at_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t col_1, int32_t row_0);
static bool writeBitmapHeader_0(FileOutputStream* fos_4, Image_0* image_1);
static int32_t min_1(int32_t x_1, int32_t y_0);
static MaybeResult_0_Tuple_int32_int32_int32_int32 combine_2_int32_int32_int32_int32(MaybeResult_0_int32 a_2, MaybeResult_0_int32 b_2, MaybeResult_0_int32 c_1, MaybeResult_0_int32 d_0);
static bool isDefined_2_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_1);
static bool writeFileHeader_0(FileOutputStream* fos_4, Image_0* image_1);
static enum_Status_0 processImage_0(FileInputStream* fis_7, FileOutputStream* fos_5, State* state_12, Kernel_0* kernel_1, Image_0* src_2);
static FileHeader_0 getResult_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_2);
static enum_Status_0 getStatus_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_3);
static enum_Status_0 getStatus_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_3);
static int32_t buildInt_0(FileInputStream* fis_2, State* state_7, int8_t b1_2, int8_t b2_2, int8_t b3_0, int8_t b4_0);
static MaybeResult_0_FileHeader_0 maybeReadFileHeader_0(FileInputStream fis_4, State state_9);
static void log_1(FileHeader_0 h_1);
static Tuple_int32_int32_int32 getResult_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_2);
static MaybeResult_0_Tuple_int32_int32_int32 combine_1_int32_int32_int32(MaybeResult_0_int32 a_1, MaybeResult_0_int32 b_1, MaybeResult_0_int32 c_0);
static void print_3(char c_5);
static bool write_4(FileOutputStream thiss_109, int8_t x_250);
static enum_Status_0 getStatus_1_int32(MaybeResult_0_int32 thiss_3);
static bool writeLong_0(FileOutputStream fos_3, int32_t long_0);
static MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 combine_0_Tuple_int32_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 a_0, MaybeResult_0_int32 b_0);
static bool writeImage_0(FileOutputStream* fos_4, Image_0* image_1);
static int32_t buildShort_0(FileInputStream* fis_1, State* state_6, int8_t b1_0, int8_t b2_0);
static void println_4(void);
static int32_t max_1(int32_t x_2, int32_t y_1);
static enum_Status_0 loadImageData_0(FileInputStream fis_6, Image_0* image_0, State state_11);
static MaybeResult_0_int32 maybeReadLong_0(FileInputStream fis_3, State state_8);
 int32_t main(int32_t argc, char** argv);
static State newState_1(void);
static bool isDefined_2_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_1);
static bool isDefined_2_int32(MaybeResult_0_int32 thiss_1);
static bool writeBytes_0(FileOutputStream fos_0, int8_t byte_0, int32_t count_2);
static bool isOpen_3(FileInputStream thiss_114);
static bool close_2(FileOutputStream thiss_107);
static bool isDefined_3_int8(Option_0_int8 thiss_95);
static int8_t apply_13(Kernel_0* thiss_11, array_int8 channel_1, int32_t width_4, int32_t height_4, int32_t index_3);
static Option_0_int8 tryReadByte_2(FileInputStream thiss_116, State state_29);
static MaybeResult_0_BitmapHeader_0 maybeReadBitmapHeader_0(FileInputStream fis_5, State state_10);
static MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 combine_0_FileHeader_0_BitmapHeader_0(MaybeResult_0_FileHeader_0 a_0, MaybeResult_0_BitmapHeader_0 b_0);
static int32_t fix_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t x_29, int32_t side_0);
static MaybeResult_0_int32 maybeReadDword_0(FileInputStream fis_2, State state_7);
static BitmapHeader_0 getResult_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_2);
static bool isEmpty_2_int8(Option_0_int8 thiss_93);
static enum_Status_0 getStatus_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_3);
static MaybeResult_0_Tuple_int32_int32 combine_0_int32_int32(MaybeResult_0_int32 a_0, MaybeResult_0_int32 b_0);
static bool skipBytes_0(FileInputStream fis_0, int32_t count_1, State state_5);
static int32_t getResult_1_int32(MaybeResult_0_int32 thiss_2);
static enum_Status_0 saveImage_0(FileOutputStream fos_4, Image_0* image_1);
static void print_0(char* x_21);
static bool isDefined_2_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_1);
static enum_Status_0 process_0(FileInputStream fis_7, FileOutputStream fos_5, State state_12);
static bool writeDword_0(FileOutputStream fos_2, int32_t dword_0);
static void println_2(int32_t x_25);
static int8_t get_4_int8(Option_0_int8 thiss_90);
static bool close_3(FileInputStream thiss_113, State state_27);
static void print_2(int32_t x_24);
static MaybeResult_0_int32 maybeReadWord_0(FileInputStream fis_1, State state_6);
static bool isSuccess_1(enum_Status_0 thiss_0);
static int32_t buildInt_1(FileInputStream* fis_3, State* state_8, int8_t b1_4, int8_t b2_4, int8_t b3_2, int8_t b4_2);

/* ------------------------ function definitions ----- */

static void println_0(char* s_19) {
    print_0(s_19);
    println_4();
}


static FILE* open_1(char* filename, void* unused) {
  FILE* this = fopen(filename, "r");
  /* this == NULL on failure */
  return this;
}
    

static MaybeResult_0_Tuple_Tuple_int32_int32_int32 combine_0_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32 a_0, MaybeResult_0_int32 b_0) {
    if (isDefined_2_Tuple_int32_int32(a_0)) {
        if (isDefined_2_int32(b_0)) {
            Tuple_int32_int32 norm_89 = getResult_1_Tuple_int32_int32(a_0);
            Tuple_int32_int32 norm_91 = norm_89;
            int32_t norm_90 = getResult_1_int32(b_0);
            int32_t norm_92 = norm_90;
            Tuple_Tuple_int32_int32_int32 norm_93 = (Tuple_Tuple_int32_int32_int32) { ._1 = norm_91, ._2 = norm_92 };
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .tag = tag_Result_0_Tuple_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .Result_0_Tuple_Tuple_int32_int32_int32_v = (Result_0_Tuple_Tuple_int32_int32_int32) { .result_0 = norm_93 } } };
        } else {
            enum_Status_0 norm_94 = getStatus_1_int32(b_0);
            enum_Status_0 norm_95 = norm_94;
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32) { .status_0 = norm_95 } } };
        }
    } else {
        enum_Status_0 norm_96 = getStatus_1_Tuple_int32_int32(a_0);
        enum_Status_0 norm_97 = norm_96;
        return (MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32) { .status_0 = norm_97 } } };
    }
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

static bool writeWord_0(FileOutputStream fos_1, int32_t word_0) {
    int32_t norm_184;
    if (word_0 >= 32768) {
        norm_184 = word_0 - 32768;
    } else {
        norm_184 = word_0;
    }
    int32_t signed_1 = norm_184;
    int8_t b2_1 = (int8_t)((int32_t)(((uint32_t)signed_1) >> 8));
    int8_t b1_1 = (int8_t)signed_1;
    bool norm_185 = write_4(fos_1, b1_1);
    bool norm_187 = norm_185;
    if (norm_187) {
        bool norm_186 = write_4(fos_1, b2_1);
        bool norm_188 = norm_186;
        return norm_188;
    } else {
        return false;
    }
}

static void log_2(BitmapHeader_0 h_2) {
    log_0("width", h_2.width_0);
    log_0("height", h_2.height_0);
}

static int32_t _main(void) {
    State state_26 = newState_1();
    FileInputStream input_1 = open_1("input.bmp", state_26);
    FileOutputStream output_1 = open_0("output.bmp");
    bool norm_0 = isOpen_3(input_1);
    bool norm_2 = norm_0;
    bool norm_4;
    if (norm_2) {
        bool norm_1 = isOpen_2(output_1);
        bool norm_3 = norm_1;
        norm_4 = norm_3;
    } else {
        norm_4 = false;
    }
    enum_Status_0 norm_265;
    if (norm_4) {
        norm_265 = process_0(input_1, output_1, state_26);
    } else {
        norm_265 = tag_OpenError_0;
    }
    enum_Status_0 status_24 = norm_265;
    close_2(output_1);
    close_3(input_1, state_26);
    return statusCode_0(status_24);
}

static void log_0(char* msg_0, int32_t x_6) {
    print_0(msg_0);
    print_0(": ");
    println_2(x_6);
}

static void apply_14(Kernel_0* thiss_12, Image_0* src_3, Image_0* dest_2) {
    int32_t size_8 = src_3->w_0 * src_3->h_0;
    int32_t i_22 = 0;
    while (i_22 < size_8) {
        int32_t norm_161 = i_22;
        int8_t norm_160 = apply_13(thiss_12, src_3->r_0, src_3->w_0, src_3->h_0, i_22);
        int8_t norm_162 = norm_160;
        dest_2->r_0.data[norm_161] = norm_162;
        int32_t norm_164 = i_22;
        int8_t norm_163 = apply_13(thiss_12, src_3->g_0, src_3->w_0, src_3->h_0, i_22);
        int8_t norm_165 = norm_163;
        dest_2->g_0.data[norm_164] = norm_165;
        int32_t norm_167 = i_22;
        int8_t norm_166 = apply_13(thiss_12, src_3->b_3, src_3->w_0, src_3->h_0, i_22);
        int8_t norm_168 = norm_166;
        dest_2->b_3.data[norm_167] = norm_168;
        i_22 = i_22 + 1;
    }
}


static FILE* open_0(char* filename) {
  FILE* this = fopen(filename, "w");
  /* this == NULL on failure */
  return this;
}
    

static enum_Status_0 getStatus_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_3) {
    return thiss_3.value.Failure_0_Tuple_int32_int32_int32_v.status_0;
}

static Tuple_int32_int32 getResult_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_2) {
    return thiss_2.value.Result_0_Tuple_int32_int32_v.result_0;
}

static int32_t clamp_0(int32_t x_3, int32_t down_0, int32_t up_0) {
    int32_t norm_152 = down_0;
    int32_t norm_151 = min_1(x_3, up_0);
    int32_t norm_153 = norm_151;
    return max_1(norm_152, norm_153);
}


static int8_t impl_2(FILE** this, void** unused, bool* valid) {
  int8_t x;
  *valid = fscanf(*this, "%c", &x) == 1;
  return x;
}
      


static bool isOpen_2(FILE* this) {
  return this != NULL;
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

static bool writeBitmapHeader_0(FileOutputStream* fos_4, Image_0* image_1) {
    int32_t size_6 = 40;
    int32_t w_4 = image_1->w_0;
    int32_t h_7 = image_1->h_0;
    int32_t planes_0 = 1;
    int32_t bpp_1 = 24;
    int32_t comp_0 = 0;
    bool norm_207 = writeDword_0(*fos_4, size_6);
    bool norm_245 = norm_207;
    if (norm_245) {
        bool norm_220 = writeLong_0(*fos_4, w_4);
        bool norm_242 = norm_220;
        bool norm_244;
        if (norm_242) {
            bool norm_221 = writeLong_0(*fos_4, h_7);
            bool norm_239 = norm_221;
            bool norm_241;
            if (norm_239) {
                bool norm_222 = writeWord_0(*fos_4, planes_0);
                bool norm_236 = norm_222;
                bool norm_238;
                if (norm_236) {
                    bool norm_223 = writeWord_0(*fos_4, bpp_1);
                    bool norm_233 = norm_223;
                    bool norm_235;
                    if (norm_233) {
                        bool norm_224 = writeWord_0(*fos_4, comp_0);
                        bool norm_230 = norm_224;
                        bool norm_232;
                        if (norm_230) {
                            bool norm_229 = writeBytes_0(*fos_4, 0, 22);
                            bool norm_231 = norm_229;
                            norm_232 = norm_231;
                        } else {
                            norm_232 = false;
                        }
                        bool norm_234 = norm_232;
                        norm_235 = norm_234;
                    } else {
                        norm_235 = false;
                    }
                    bool norm_237 = norm_235;
                    norm_238 = norm_237;
                } else {
                    norm_238 = false;
                }
                bool norm_240 = norm_238;
                norm_241 = norm_240;
            } else {
                norm_241 = false;
            }
            bool norm_243 = norm_241;
            norm_244 = norm_243;
        } else {
            norm_244 = false;
        }
        bool norm_246 = norm_244;
        return norm_246;
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

static MaybeResult_0_Tuple_int32_int32_int32_int32 combine_2_int32_int32_int32_int32(MaybeResult_0_int32 a_2, MaybeResult_0_int32 b_2, MaybeResult_0_int32 c_1, MaybeResult_0_int32 d_0) {
    MaybeResult_0_Tuple_int32_int32_int32 norm_101 = combine_1_int32_int32_int32(a_2, b_2, c_1);
    MaybeResult_0_Tuple_int32_int32_int32 norm_102 = norm_101;
    MaybeResult_0_int32 norm_103 = d_0;
    MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 tmp_1 = combine_0_Tuple_int32_int32_int32_int32(norm_102, norm_103);
    if (tmp_1.tag == tag_Result_0_Tuple_Tuple_int32_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32_int32) { .tag = tag_Result_0_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32_int32) { .Result_0_Tuple_int32_int32_int32_int32_v = (Result_0_Tuple_int32_int32_int32_int32) { .result_0 = (Tuple_int32_int32_int32_int32) { ._1 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._1._1, ._2 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._1._2, ._3 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._1._3, ._4 = tmp_1.value.Result_0_Tuple_Tuple_int32_int32_int32_int32_v.result_0._2 } } } };
    } else if (tmp_1.tag == tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32_int32) { .tag = tag_Failure_0_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32_int32) { .Failure_0_Tuple_int32_int32_int32_int32_v = (Failure_0_Tuple_int32_int32_int32_int32) { .status_0 = tmp_1.value.Failure_0_Tuple_Tuple_int32_int32_int32_int32_v.status_0 } } };
    }
}

static bool isDefined_2_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_1) {
    if (thiss_1.tag == tag_Result_0_BitmapHeader_0) {
        return true;
    } else {
        return false;
    }
}

static bool writeFileHeader_0(FileOutputStream* fos_4, Image_0* image_1) {
    int32_t size_7 = 54 + (image_1->w_0 * image_1->h_0) * 3;
    int32_t reserved_0 = 0;
    int32_t offset_2 = 54;
    bool norm_169 = write_4(*fos_4, (int8_t)66);
    bool norm_204 = norm_169;
    if (norm_204) {
        bool norm_170 = write_4(*fos_4, (int8_t)77);
        bool norm_201 = norm_170;
        bool norm_203;
        if (norm_201) {
            bool norm_183 = writeDword_0(*fos_4, size_7);
            bool norm_198 = norm_183;
            bool norm_200;
            if (norm_198) {
                bool norm_189 = writeWord_0(*fos_4, reserved_0);
                bool norm_195 = norm_189;
                bool norm_197;
                if (norm_195) {
                    bool norm_190 = writeWord_0(*fos_4, reserved_0);
                    bool norm_192 = norm_190;
                    bool norm_194;
                    if (norm_192) {
                        bool norm_191 = writeDword_0(*fos_4, offset_2);
                        bool norm_193 = norm_191;
                        norm_194 = norm_193;
                    } else {
                        norm_194 = false;
                    }
                    bool norm_196 = norm_194;
                    norm_197 = norm_196;
                } else {
                    norm_197 = false;
                }
                bool norm_199 = norm_197;
                norm_200 = norm_199;
            } else {
                norm_200 = false;
            }
            bool norm_202 = norm_200;
            norm_203 = norm_202;
        } else {
            norm_203 = false;
        }
        bool norm_205 = norm_203;
        return norm_205;
    } else {
        return false;
    }
}

static enum_Status_0 processImage_0(FileInputStream* fis_7, FileOutputStream* fos_5, State* state_12, Kernel_0* kernel_1, Image_0* src_2) {
    int8_t leon_buffer_4[262144] = { 0 };
    array_int8 norm_143 = (array_int8) { .data = leon_buffer_4, .length = 262144 };
    array_int8* norm_146 = &norm_143;
    int8_t leon_buffer_5[262144] = { 0 };
    array_int8 norm_144 = (array_int8) { .data = leon_buffer_5, .length = 262144 };
    array_int8* norm_147 = &norm_144;
    int8_t leon_buffer_6[262144] = { 0 };
    array_int8 norm_145 = (array_int8) { .data = leon_buffer_6, .length = 262144 };
    array_int8* norm_148 = &norm_145;
    int32_t norm_149 = src_2->w_0;
    int32_t norm_150 = src_2->h_0;
    Image_0 dest_1 = (Image_0) { .r_0 = (*norm_146), .g_0 = (*norm_147), .b_3 = (*norm_148), .w_0 = norm_149, .h_0 = norm_150 };
    apply_14(kernel_1, src_2, &dest_1);
    return saveImage_0(*fos_5, &dest_1);
}

static FileHeader_0 getResult_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_2) {
    return thiss_2.value.Result_0_FileHeader_0_v.result_0;
}

static enum_Status_0 getStatus_1_FileHeader_0(MaybeResult_0_FileHeader_0 thiss_3) {
    return thiss_3.value.Failure_0_FileHeader_0_v.status_0;
}

static enum_Status_0 getStatus_1_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_3) {
    return thiss_3.value.Failure_0_Tuple_int32_int32_v.status_0;
}

static int32_t buildInt_0(FileInputStream* fis_2, State* state_7, int8_t b1_2, int8_t b2_2, int8_t b3_0, int8_t b4_0) {
    return ((((int32_t)(((uint32_t)((int32_t)b4_0)) << 24)) | ((int32_t)(((uint32_t)(((int32_t)b3_0) & 255)) << 16))) | ((int32_t)(((uint32_t)(((int32_t)b2_2) & 255)) << 8))) | (((int32_t)b1_2) & 255);
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

static void log_1(FileHeader_0 h_1) {
    log_0("size", h_1.size_1);
    log_0("offset", h_1.offset_0);
}

static Tuple_int32_int32_int32 getResult_1_Tuple_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 thiss_2) {
    return thiss_2.value.Result_0_Tuple_int32_int32_int32_v.result_0;
}

static MaybeResult_0_Tuple_int32_int32_int32 combine_1_int32_int32_int32(MaybeResult_0_int32 a_1, MaybeResult_0_int32 b_1, MaybeResult_0_int32 c_0) {
    MaybeResult_0_Tuple_int32_int32 norm_98 = combine_0_int32_int32(a_1, b_1);
    MaybeResult_0_Tuple_int32_int32 norm_99 = norm_98;
    MaybeResult_0_int32 norm_100 = c_0;
    MaybeResult_0_Tuple_Tuple_int32_int32_int32 tmp_0 = combine_0_Tuple_int32_int32_int32(norm_99, norm_100);
    if (tmp_0.tag == tag_Result_0_Tuple_Tuple_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32) { .tag = tag_Result_0_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32) { .Result_0_Tuple_int32_int32_int32_v = (Result_0_Tuple_int32_int32_int32) { .result_0 = (Tuple_int32_int32_int32) { ._1 = tmp_0.value.Result_0_Tuple_Tuple_int32_int32_int32_v.result_0._1._1, ._2 = tmp_0.value.Result_0_Tuple_Tuple_int32_int32_int32_v.result_0._1._2, ._3 = tmp_0.value.Result_0_Tuple_Tuple_int32_int32_int32_v.result_0._2 } } } };
    } else if (tmp_0.tag == tag_Failure_0_Tuple_Tuple_int32_int32_int32) {
        return (MaybeResult_0_Tuple_int32_int32_int32) { .tag = tag_Failure_0_Tuple_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_int32_int32_int32) { .Failure_0_Tuple_int32_int32_int32_v = (Failure_0_Tuple_int32_int32_int32) { .status_0 = tmp_0.value.Failure_0_Tuple_Tuple_int32_int32_int32_v.status_0 } } };
    }
}


static void print_3(char c) {
  printf("%c", c);
}
      


static bool write_4(FILE* this, int8_t x) {
  return fprintf(this, "%c", x) >= 0;
}
    

static enum_Status_0 getStatus_1_int32(MaybeResult_0_int32 thiss_3) {
    return thiss_3.value.Failure_0_int32_v.status_0;
}

static bool writeLong_0(FileOutputStream fos_3, int32_t long_0) {
    int8_t b4_3 = (int8_t)((int32_t)(((uint32_t)long_0) >> 24));
    int8_t b3_3 = (int8_t)((int32_t)(((uint32_t)long_0) >> 16));
    int8_t b2_5 = (int8_t)((int32_t)(((uint32_t)long_0) >> 8));
    int8_t b1_5 = (int8_t)long_0;
    bool norm_208 = write_4(fos_3, b1_5);
    bool norm_218 = norm_208;
    if (norm_218) {
        bool norm_209 = write_4(fos_3, b2_5);
        bool norm_215 = norm_209;
        bool norm_217;
        if (norm_215) {
            bool norm_210 = write_4(fos_3, b3_3);
            bool norm_212 = norm_210;
            bool norm_214;
            if (norm_212) {
                bool norm_211 = write_4(fos_3, b4_3);
                bool norm_213 = norm_211;
                norm_214 = norm_213;
            } else {
                norm_214 = false;
            }
            bool norm_216 = norm_214;
            norm_217 = norm_216;
        } else {
            norm_217 = false;
        }
        bool norm_219 = norm_217;
        return norm_219;
    } else {
        return false;
    }
}

static MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32 combine_0_Tuple_int32_int32_int32_int32(MaybeResult_0_Tuple_int32_int32_int32 a_0, MaybeResult_0_int32 b_0) {
    if (isDefined_2_Tuple_int32_int32_int32(a_0)) {
        if (isDefined_2_int32(b_0)) {
            Tuple_int32_int32_int32 norm_80 = getResult_1_Tuple_int32_int32_int32(a_0);
            Tuple_int32_int32_int32 norm_82 = norm_80;
            int32_t norm_81 = getResult_1_int32(b_0);
            int32_t norm_83 = norm_81;
            Tuple_Tuple_int32_int32_int32_int32 norm_84 = (Tuple_Tuple_int32_int32_int32_int32) { ._1 = norm_82, ._2 = norm_83 };
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .tag = tag_Result_0_Tuple_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .Result_0_Tuple_Tuple_int32_int32_int32_int32_v = (Result_0_Tuple_Tuple_int32_int32_int32_int32) { .result_0 = norm_84 } } };
        } else {
            enum_Status_0 norm_85 = getStatus_1_int32(b_0);
            enum_Status_0 norm_86 = norm_85;
            return (MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32_int32) { .status_0 = norm_86 } } };
        }
    } else {
        enum_Status_0 norm_87 = getStatus_1_Tuple_int32_int32_int32(a_0);
        enum_Status_0 norm_88 = norm_87;
        return (MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .tag = tag_Failure_0_Tuple_Tuple_int32_int32_int32_int32, .value = (union_MaybeResult_0_Tuple_Tuple_int32_int32_int32_int32) { .Failure_0_Tuple_Tuple_int32_int32_int32_int32_v = (Failure_0_Tuple_Tuple_int32_int32_int32_int32) { .status_0 = norm_88 } } };
    }
}

static bool writeImage_0(FileOutputStream* fos_4, Image_0* image_1) {
    int32_t count_3 = image_1->w_0 * image_1->h_0;
    int32_t i_20 = 0;
    bool success_1 = true;
    while (success_1 && i_20 < count_3) {
        bool norm_248 = write_4(*fos_4, image_1->r_0.data[i_20]);
        bool norm_254 = norm_248;
        bool norm_256;
        if (norm_254) {
            bool norm_249 = write_4(*fos_4, image_1->g_0.data[i_20]);
            bool norm_251 = norm_249;
            bool norm_253;
            if (norm_251) {
                bool norm_250 = write_4(*fos_4, image_1->b_3.data[i_20]);
                bool norm_252 = norm_250;
                norm_253 = norm_252;
            } else {
                norm_253 = false;
            }
            bool norm_255 = norm_253;
            norm_256 = norm_255;
        } else {
            norm_256 = false;
        }
        success_1 = norm_256;
        i_20 = i_20 + 1;
    }
    return success_1;
}

static int32_t buildShort_0(FileInputStream* fis_1, State* state_6, int8_t b1_0, int8_t b2_0) {
    return ((int32_t)(((uint32_t)((int32_t)b2_0)) << 8)) | (((int32_t)b1_0) & 255);
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

static enum_Status_0 loadImageData_0(FileInputStream fis_6, Image_0* image_0, State state_11) {
    int32_t size_5 = image_0->w_0 * image_0->h_0;
    int32_t i_19 = 0;
    enum_Status_0 status_23 = tag_Success_0;
    while (true) {
        bool norm_121 = isSuccess_1(status_23);
        bool norm_122 = norm_121;
        bool norm_124;
        if (norm_122) {
            bool norm_123 = i_19 < size_5;
            norm_124 = norm_123;
        } else {
            norm_124 = false;
        }
        if (norm_124) {
            Option_0_int8 rOpt_0 = tryReadByte_2(fis_6, state_11);
            Option_0_int8 gOpt_0 = tryReadByte_2(fis_6, state_11);
            Option_0_int8 bOpt_0 = tryReadByte_2(fis_6, state_11);
            bool norm_125 = isEmpty_2_int8(rOpt_0);
            bool norm_131 = norm_125;
            bool norm_133;
            if (norm_131) {
                norm_133 = true;
            } else {
                bool norm_126 = isEmpty_2_int8(gOpt_0);
                bool norm_128 = norm_126;
                bool norm_130;
                if (norm_128) {
                    norm_130 = true;
                } else {
                    bool norm_127 = isEmpty_2_int8(bOpt_0);
                    bool norm_129 = norm_127;
                    norm_130 = norm_129;
                }
                bool norm_132 = norm_130;
                norm_133 = norm_132;
            }
            if (norm_133) {
                status_23 = tag_ReadError_0;
                log_0("stopped reading data abruptly after", i_19);
            } else {
                int32_t norm_135 = i_19;
                int8_t norm_134 = get_4_int8(rOpt_0);
                int8_t norm_136 = norm_134;
                image_0->r_0.data[norm_135] = norm_136;
                int32_t norm_138 = i_19;
                int8_t norm_137 = get_4_int8(gOpt_0);
                int8_t norm_139 = norm_137;
                image_0->g_0.data[norm_138] = norm_139;
                int32_t norm_141 = i_19;
                int8_t norm_140 = get_4_int8(bOpt_0);
                int8_t norm_142 = norm_140;
                image_0->b_3.data[norm_141] = norm_142;
            }
            i_19 = i_19 + 1;
        } else {
            break;
        }
    }
    return status_23;
}

static MaybeResult_0_int32 maybeReadLong_0(FileInputStream fis_3, State state_8) {
    Option_0_int8 byte1_2 = tryReadByte_2(fis_3, state_8);
    Option_0_int8 byte2_2 = tryReadByte_2(fis_3, state_8);
    Option_0_int8 byte3_1 = tryReadByte_2(fis_3, state_8);
    Option_0_int8 byte4_1 = tryReadByte_2(fis_3, state_8);
    bool norm_45 = isDefined_3_int8(byte1_2);
    bool norm_55 = norm_45;
    bool norm_57;
    if (norm_55) {
        bool norm_46 = isDefined_3_int8(byte2_2);
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
        int8_t norm_58 = get_4_int8(byte1_2);
        int8_t norm_62 = norm_58;
        int8_t norm_59 = get_4_int8(byte2_2);
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

 int32_t main(int32_t argc, char** argv) {
    return _main();
}

static void* newState_1(void) { return NULL; }

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

static bool writeBytes_0(FileOutputStream fos_0, int8_t byte_0, int32_t count_2) {
    if (count_2 == 0) {
        return true;
    } else {
        bool norm_225 = write_4(fos_0, byte_0);
        bool norm_227 = norm_225;
        if (norm_227) {
            bool norm_226 = writeBytes_0(fos_0, byte_0, count_2 - 1);
            bool norm_228 = norm_226;
            return norm_228;
        } else {
            return false;
        }
    }
}


static bool isOpen_3(FILE* this) {
  return this != NULL;
}
    


static bool close_2(FILE* this) {
  if (this != NULL)
    return fclose(this) == 0;
  else
    return true;
}
    

static bool isDefined_3_int8(Option_0_int8 thiss_95) {
    bool norm_9 = isEmpty_2_int8(thiss_95);
    return !norm_9;
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
            int32_t norm_157 = res_7;
            int32_t norm_154 = at_0(thiss_11, channel_1, &width_4, &height_4, &index_3, i_21 + p_20, j_0 + q_1);
            int32_t norm_155 = norm_154;
            int32_t norm_156 = thiss_11->kernel_0.data[kidx_0];
            int32_t norm_158 = norm_155 * norm_156;
            res_7 = norm_157 + norm_158;
            q_1 = q_1 + 1;
        }
        p_20 = p_20 + 1;
    }
    int32_t norm_159 = clamp_0(res_7 / thiss_11->scale_0, 0, 255);
    res_7 = norm_159;
    return (int8_t)res_7;
}

static Option_0_int8 tryReadByte_2(FileInputStream thiss_116, State state_29) {
    bool valid_2 = true;
    int8_t res_16 = impl_2(&thiss_116, &state_29, &valid_2);
    if (valid_2) {
        return (Option_0_int8) { .tag = tag_Some_0_int8, .value = (union_Option_0_int8) { .Some_0_int8_v = (Some_0_int8) { .v_13 = res_16 } } };
    } else {
        return (Option_0_int8) { .tag = tag_None_0_int8, .value = (union_Option_0_int8) { .None_0_int8_v = (None_0_int8) { .extra = 0 } } };
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

static MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 combine_0_FileHeader_0_BitmapHeader_0(MaybeResult_0_FileHeader_0 a_0, MaybeResult_0_BitmapHeader_0 b_0) {
    if (isDefined_2_FileHeader_0(a_0)) {
        if (isDefined_2_BitmapHeader_0(b_0)) {
            FileHeader_0 norm_104 = getResult_1_FileHeader_0(a_0);
            FileHeader_0 norm_106 = norm_104;
            BitmapHeader_0 norm_105 = getResult_1_BitmapHeader_0(b_0);
            BitmapHeader_0 norm_107 = norm_105;
            Tuple_FileHeader_0_BitmapHeader_0 norm_108 = (Tuple_FileHeader_0_BitmapHeader_0) { ._1 = norm_106, ._2 = norm_107 };
            return (MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .tag = tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0, .value = (union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .Result_0_Tuple_FileHeader_0_BitmapHeader_0_v = (Result_0_Tuple_FileHeader_0_BitmapHeader_0) { .result_0 = norm_108 } } };
        } else {
            enum_Status_0 norm_109 = getStatus_1_BitmapHeader_0(b_0);
            enum_Status_0 norm_110 = norm_109;
            return (MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .tag = tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0, .value = (union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v = (Failure_0_Tuple_FileHeader_0_BitmapHeader_0) { .status_0 = norm_110 } } };
        }
    } else {
        enum_Status_0 norm_111 = getStatus_1_FileHeader_0(a_0);
        enum_Status_0 norm_112 = norm_111;
        return (MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .tag = tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0, .value = (union_MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0) { .Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v = (Failure_0_Tuple_FileHeader_0_BitmapHeader_0) { .status_0 = norm_112 } } };
    }
}

static int32_t fix_0(Kernel_0* thiss_11, array_int8 channel_1, int32_t* width_4, int32_t* height_4, int32_t* index_3, int32_t x_29, int32_t side_0) {
    return clamp_0(x_29, 0, side_0 - 1);
}

static MaybeResult_0_int32 maybeReadDword_0(FileInputStream fis_2, State state_7) {
    Option_0_int8 byte1_1 = tryReadByte_2(fis_2, state_7);
    Option_0_int8 byte2_1 = tryReadByte_2(fis_2, state_7);
    Option_0_int8 byte3_0 = tryReadByte_2(fis_2, state_7);
    Option_0_int8 byte4_0 = tryReadByte_2(fis_2, state_7);
    bool norm_11 = isDefined_3_int8(byte1_1);
    bool norm_21 = norm_11;
    bool norm_23;
    if (norm_21) {
        bool norm_12 = isDefined_3_int8(byte2_1);
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
            int8_t norm_24 = get_4_int8(byte1_1);
            int8_t norm_28 = norm_24;
            int8_t norm_25 = get_4_int8(byte2_1);
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

static BitmapHeader_0 getResult_1_BitmapHeader_0(MaybeResult_0_BitmapHeader_0 thiss_2) {
    return thiss_2.value.Result_0_BitmapHeader_0_v.result_0;
}

static bool isEmpty_2_int8(Option_0_int8 thiss_93) {
    if (thiss_93.tag == tag_Some_0_int8) {
        return false;
    } else if (thiss_93.tag == tag_None_0_int8) {
        return true;
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

static int32_t getResult_1_int32(MaybeResult_0_int32 thiss_2) {
    return thiss_2.value.Result_0_int32_v.result_0;
}

static enum_Status_0 saveImage_0(FileOutputStream fos_4, Image_0* image_1) {
    bool norm_206 = writeFileHeader_0(&fos_4, image_1);
    bool norm_261 = norm_206;
    bool norm_263;
    if (norm_261) {
        bool norm_247 = writeBitmapHeader_0(&fos_4, image_1);
        bool norm_258 = norm_247;
        bool norm_260;
        if (norm_258) {
            bool norm_257 = writeImage_0(&fos_4, image_1);
            bool norm_259 = norm_257;
            norm_260 = norm_259;
        } else {
            norm_260 = false;
        }
        bool norm_262 = norm_260;
        norm_263 = norm_262;
    } else {
        norm_263 = false;
    }
    if (norm_263) {
        return tag_Success_0;
    } else {
        return tag_WriteError_0;
    }
}


static void print_0(char* s) {
  printf("%s", s);
}
      

static bool isDefined_2_Tuple_int32_int32(MaybeResult_0_Tuple_int32_int32 thiss_1) {
    if (thiss_1.tag == tag_Result_0_Tuple_int32_int32) {
        return true;
    } else {
        return false;
    }
}

static enum_Status_0 process_0(FileInputStream fis_7, FileOutputStream fos_5, State state_12) {
    int32_t norm_6 = 5;
    int32_t norm_7 = 25;
    int32_t leon_buffer_0[25] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    array_int32 norm_5 = (array_int32) { .data = leon_buffer_0, .length = 25 };
    array_int32* norm_8 = &norm_5;
    Kernel_0 kernel_1 = (Kernel_0) { .size_2 = norm_6, .scale_0 = norm_7, .kernel_0 = (*norm_8) };
    MaybeResult_0_FileHeader_0 fileHeaderRes_0 = maybeReadFileHeader_0(fis_7, state_12);
    MaybeResult_0_BitmapHeader_0 bitmapHeaderRes_0 = maybeReadBitmapHeader_0(fis_7, state_12);
    MaybeResult_0_Tuple_FileHeader_0_BitmapHeader_0 tmp_4 = combine_0_FileHeader_0_BitmapHeader_0(fileHeaderRes_0, bitmapHeaderRes_0);
    enum_Status_0 norm_264;
    if (tmp_4.tag == tag_Failure_0_Tuple_FileHeader_0_BitmapHeader_0) {
        norm_264 = tmp_4.value.Failure_0_Tuple_FileHeader_0_BitmapHeader_0_v.status_0;
    } else if (tmp_4.tag == tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0 && tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._1.size_1 <= 54) {
        norm_264 = tag_CorruptedDataError_0;
    } else if (tmp_4.tag == tag_Result_0_Tuple_FileHeader_0_BitmapHeader_0) {
        log_1(tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._1);
        log_2(tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2);
        int32_t toSkip_0 = tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._1.offset_0 - 32;
        bool success_2 = skipBytes_0(fis_7, toSkip_0, state_12);
        if (!success_2) {
            norm_264 = tag_CorruptedDataError_0;
        } else if (tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.width_0 > 512 || tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.height_0 > 512) {
            norm_264 = tag_ImageTooBigError_0;
        } else if (tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.width_0 * tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.height_0 > 262144) {
            norm_264 = tag_ImageTooBigError_0;
        } else {
            int8_t leon_buffer_1[262144] = { 0 };
            array_int8 norm_113 = (array_int8) { .data = leon_buffer_1, .length = 262144 };
            array_int8* norm_116 = &norm_113;
            int8_t leon_buffer_2[262144] = { 0 };
            array_int8 norm_114 = (array_int8) { .data = leon_buffer_2, .length = 262144 };
            array_int8* norm_117 = &norm_114;
            int8_t leon_buffer_3[262144] = { 0 };
            array_int8 norm_115 = (array_int8) { .data = leon_buffer_3, .length = 262144 };
            array_int8* norm_118 = &norm_115;
            int32_t norm_119 = tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.width_0;
            int32_t norm_120 = tmp_4.value.Result_0_Tuple_FileHeader_0_BitmapHeader_0_v.result_0._2.height_0;
            Image_0 image_2 = (Image_0) { .r_0 = (*norm_116), .g_0 = (*norm_117), .b_3 = (*norm_118), .w_0 = norm_119, .h_0 = norm_120 };
            enum_Status_0 status_27 = loadImageData_0(fis_7, &image_2, state_12);
            if (isSuccess_1(status_27)) {
                norm_264 = processImage_0(&fis_7, &fos_5, &state_12, &kernel_1, &image_2);
            } else {
                norm_264 = status_27;
            }
        }
    }
    enum_Status_0 status_25 = norm_264;
    return status_25;
}

static bool writeDword_0(FileOutputStream fos_2, int32_t dword_0) {
    int8_t b4_1 = (int8_t)((int32_t)(((uint32_t)dword_0) >> 24));
    int8_t b3_1 = (int8_t)((int32_t)(((uint32_t)dword_0) >> 16));
    int8_t b2_3 = (int8_t)((int32_t)(((uint32_t)dword_0) >> 8));
    int8_t b1_3 = (int8_t)dword_0;
    bool norm_171 = write_4(fos_2, b1_3);
    bool norm_181 = norm_171;
    if (norm_181) {
        bool norm_172 = write_4(fos_2, b2_3);
        bool norm_178 = norm_172;
        bool norm_180;
        if (norm_178) {
            bool norm_173 = write_4(fos_2, b3_1);
            bool norm_175 = norm_173;
            bool norm_177;
            if (norm_175) {
                bool norm_174 = write_4(fos_2, b4_1);
                bool norm_176 = norm_174;
                norm_177 = norm_176;
            } else {
                norm_177 = false;
            }
            bool norm_179 = norm_177;
            norm_180 = norm_179;
        } else {
            norm_180 = false;
        }
        bool norm_182 = norm_180;
        return norm_182;
    } else {
        return false;
    }
}

static void println_2(int32_t x_25) {
    print_2(x_25);
    println_4();
}

static int8_t get_4_int8(Option_0_int8 thiss_90) {
    return thiss_90.value.Some_0_int8_v.v_13;
}


static bool close_3(FILE* this, void* unused) {
  if (this != NULL)
    return fclose(this) == 0;
  else
    return true;
}
    


static void print_2(int32_t x) {
  printf("%"PRIi32, x);
}
     

static MaybeResult_0_int32 maybeReadWord_0(FileInputStream fis_1, State state_6) {
    Option_0_int8 byte1_0 = tryReadByte_2(fis_1, state_6);
    Option_0_int8 byte2_0 = tryReadByte_2(fis_1, state_6);
    bool norm_70 = isDefined_3_int8(byte1_0);
    bool norm_72 = norm_70;
    bool norm_74;
    if (norm_72) {
        bool norm_71 = isDefined_3_int8(byte2_0);
        bool norm_73 = norm_71;
        norm_74 = norm_73;
    } else {
        norm_74 = false;
    }
    if (norm_74) {
        int8_t norm_75 = get_4_int8(byte1_0);
        int8_t norm_77 = norm_75;
        int8_t norm_76 = get_4_int8(byte2_0);
        int8_t norm_78 = norm_76;
        int32_t signed_0 = buildShort_0(&fis_1, &state_6, norm_77, norm_78);
        int32_t norm_79;
        if (signed_0 < 0) {
            norm_79 = signed_0 + 65536;
        } else {
            norm_79 = signed_0;
        }
        int32_t unsigned_0 = norm_79;
        return (MaybeResult_0_int32) { .tag = tag_Result_0_int32, .value = (union_MaybeResult_0_int32) { .Result_0_int32_v = (Result_0_int32) { .result_0 = unsigned_0 } } };
    } else {
        return (MaybeResult_0_int32) { .tag = tag_Failure_0_int32, .value = (union_MaybeResult_0_int32) { .Failure_0_int32_v = (Failure_0_int32) { .status_0 = tag_ReadError_0 } } };
    }
}

static bool isSuccess_1(enum_Status_0 thiss_0) {
    return thiss_0 == tag_Success_0;
}

static int32_t buildInt_1(FileInputStream* fis_3, State* state_8, int8_t b1_4, int8_t b2_4, int8_t b3_2, int8_t b4_2) {
    return ((((int32_t)(((uint32_t)((int32_t)b4_2)) << 24)) | ((int32_t)(((uint32_t)(((int32_t)b3_2) & 255)) << 16))) | ((int32_t)(((uint32_t)(((int32_t)b2_4) & 255)) << 8))) | (((int32_t)b1_4) & 255);
}
