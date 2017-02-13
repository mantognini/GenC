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
  tag_None_0_CodeWord_0,
  tag_Some_0_CodeWord_0
} enum_Option_0_CodeWord_0;

typedef enum {
  tag_None_0_int8,
  tag_Some_0_int8
} enum_Option_0_int8;

typedef enum {
  tag_OpenError_0,
  tag_DecodeError_0,
  tag_Success_0,
  tag_EncodeError_0
} enum_Status_0;

/* ----------------------- data type definitions ----- */

typedef struct {
  int8_t* data;
  int32_t length;
} array_int8;

typedef struct {
  int32_t* data;
  int32_t length;
} array_int32;

typedef struct {
  array_int8 memory_1;
  array_int32 pteps_1;
  int32_t nextIndex_1;
} Dictionary_2;

typedef struct {
  array_int8 array_1;
  int32_t length_3;
} Buffer_2;

typedef struct {
  int8_t extra;
} None_0_CodeWord_0;

typedef struct {
  int8_t b1_0;
  int8_t b2_0;
} CodeWord_0;

typedef struct {
  CodeWord_0 v_13;
} Some_0_CodeWord_0;

typedef union {
  None_0_CodeWord_0 None_0_CodeWord_0_v;
  Some_0_CodeWord_0 Some_0_CodeWord_0_v;
} union_Option_0_CodeWord_0;

typedef struct {
  enum_Option_0_CodeWord_0 tag;
  union_Option_0_CodeWord_0 value;
} Option_0_CodeWord_0;

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
  Option_0_int8 _1;
  Option_0_int8 _2;
} Tuple_Option_0_int8_Option_0_int8;

/* ----------------------- function declarations ----- */

static bool writeBytes_2(FileOutputStream fos_6, Buffer_2* buffer_7);
static void setImpl_3(Buffer_2* thiss_821, Buffer_2* b_31);
static Option_0_int8 tryReadByte_3(FileInputStream thiss_132, State state_27);
static bool isEmpty_12(Buffer_2* thiss_787);
static bool appendTo_3(Dictionary_2* thiss_819, int32_t index_33, Buffer_2* buffer_11);
static bool isEmpty_8_CodeWord_0(Option_0_CodeWord_0 thiss_109);
static void initialise_2(Dictionary_2* dict_2);
static enum_Status_0 decodeFile_1(State* state_24);
static int32_t size_10(Buffer_2* thiss_767);
static bool isOpen_4(FileInputStream thiss_130);
static bool encode_4(FileInputStream fis_2, FileOutputStream fos_2, State state_7);
static void print_5(char c_3);
static int32_t capacity_7(Dictionary_2* thiss_755);
static FileOutputStream open_2(char* filename_2);
static void println_6(void);
static void clear_4(Buffer_2* thiss_799);
static Option_0_CodeWord_0 tryReadCodeWord_1(FileInputStream fis_1, State state_6);
static void set_8(Buffer_2* thiss_817, Buffer_2* b_29);
static int8_t get_5_int8(Option_0_int8 thiss_106);
static bool contains_5(Dictionary_2* thiss_800, int32_t index_31);
static bool isRangeEqual_3(Buffer_2* thiss_797, array_int8 other_2, int32_t otherStart_2, int32_t otherSize_2);
static CodeWord_0 get_5_CodeWord_0(Option_0_CodeWord_0 thiss_106);
static Option_0_int8 tryReadNext_1(FileInputStream fis_0, State state_5);
static int32_t _main(void);
static bool isEmpty_8_int8(Option_0_int8 thiss_109);
static bool encodeImpl_2(Dictionary_2* dictionary_5, FileInputStream fis_6, FileOutputStream fos_7, State state_30);
static int32_t lastIndex_3(Dictionary_2* thiss_818);
static int32_t capacity_5(Buffer_2* thiss_753);
static bool nonFull_6(Dictionary_2* thiss_780);
static void append_3(Buffer_2* thiss_781, int8_t x_289);
static bool decodeImpl_2(Dictionary_2* dictionary_8, FileInputStream fis_7, FileOutputStream fos_8, State state_31);
static bool write_8(FileOutputStream thiss_125, int8_t x_246);
 int32_t main(int32_t argc, char** argv);
static FileInputStream open_3(char* filename_3, State state_23);
static int8_t apply_21(Buffer_2* thiss_769, int32_t index_29);
static int32_t statusCode_1(State* state_24, enum_Status_0 s_20);
static bool isFull_5(Buffer_2* thiss_796);
static void insert_3(Dictionary_2* thiss_786, Buffer_2* b_23);
static bool isDefined_2_CodeWord_0(Option_0_CodeWord_0 thiss_111);
static Option_0_CodeWord_0 encode_5(Dictionary_2* thiss_798, Buffer_2* b_25);
static int32_t getBufferBeginning_3(Dictionary_2* thiss_801, int32_t index_32);
static bool writeCodeWord_1(FileOutputStream fos_0, CodeWord_0 cw_0);
static bool close_5(FileOutputStream thiss_123);
static int32_t codeWord2Index_1(CodeWord_0 cw_1);
static bool decode_1(FileInputStream fis_4, FileOutputStream fos_4, State state_9);
static bool isDefined_2_int8(Option_0_int8 thiss_111);
static CodeWord_0 index2CodeWord_1(int32_t index_3);
static bool close_4(FileInputStream thiss_129, State state_25);
static void println_5(char* s_19);
static int32_t getNextBufferBeginning_3(Dictionary_2* thiss_783);
static bool isOpen_5(FileOutputStream thiss_124);
static int8_t impl_4(FileInputStream* thiss_132, State* state_27, bool* valid_2);
static void print_4(char* x_17);
static void dropLast_3(Buffer_2* thiss_785);
static enum_Status_0 encodeFile_1(State* state_24);
static int32_t getBufferSize_3(Dictionary_2* thiss_795, int32_t index_30);
static State newState_2(void);

/* ------------------------ function definitions ----- */

static bool writeBytes_2(FileOutputStream fos_6, Buffer_2* buffer_7) {
    bool success_0 = true;
    int32_t i_20 = 0;
    int32_t size_3 = size_10(buffer_7);
    while (success_0 && i_20 < size_3) {
        FileOutputStream norm_92 = fos_6;
        int8_t norm_91 = apply_21(buffer_7, i_20);
        int8_t norm_93 = norm_91;
        bool norm_94 = write_8(norm_92, norm_93);
        success_0 = norm_94;
        i_20 = i_20 + 1;
    }
    return success_0;
}

static void setImpl_3(Buffer_2* thiss_821, Buffer_2* b_31) {
    thiss_821->length_3 = b_31->length_3;
    int32_t i_19 = 0;
    while (i_19 < thiss_821->length_3) {
        thiss_821->array_1.data[i_19] = b_31->array_1.data[i_19];
        i_19 = i_19 + 1;
    }
}

static Option_0_int8 tryReadByte_3(FileInputStream thiss_132, State state_27) {
    bool valid_2 = true;
    int8_t res_18 = impl_4(&thiss_132, &state_27, &valid_2);
    if (valid_2) {
        return (Option_0_int8) { .tag = tag_Some_0_int8, .value = (union_Option_0_int8) { .Some_0_int8_v = (Some_0_int8) { .v_13 = res_18 } } };
    } else {
        return (Option_0_int8) { .tag = tag_None_0_int8, .value = (union_Option_0_int8) { .None_0_int8_v = (None_0_int8) { .extra = 0 } } };
    }
}

static bool isEmpty_12(Buffer_2* thiss_787) {
    return thiss_787->length_3 == 0;
}

static bool appendTo_3(Dictionary_2* thiss_819, int32_t index_33, Buffer_2* buffer_11) {
    int32_t size_4 = getBufferSize_3(thiss_819, index_33);
    int32_t start_1 = getBufferBeginning_3(thiss_819, index_33);
    int32_t norm_84 = size_10(buffer_11);
    int32_t norm_88 = norm_84;
    int32_t norm_85 = capacity_5(buffer_11);
    int32_t norm_86 = norm_85;
    int32_t norm_87 = size_4;
    int32_t norm_89 = norm_86 - norm_87;
    if (norm_88 < norm_89) {
        int32_t i_21 = 0;
        while (i_21 < size_4) {
            append_3(buffer_11, thiss_819->memory_1.data[start_1 + i_21]);
            i_21 = i_21 + 1;
        }
        return true;
    } else {
        return false;
    }
}

static bool isEmpty_8_CodeWord_0(Option_0_CodeWord_0 thiss_109) {
    if (thiss_109.tag == tag_Some_0_CodeWord_0) {
        return false;
    } else if (thiss_109.tag == tag_None_0_CodeWord_0) {
        return true;
    }
}

static void initialise_2(Dictionary_2* dict_2) {
    int8_t leon_buffer_7[64] = { 0 };
    array_int8 norm_10 = (array_int8) { .data = leon_buffer_7, .length = 64 };
    array_int8* norm_11 = &norm_10;
    int32_t norm_12 = 0;
    Buffer_2 res_217 = (Buffer_2) { .array_1 = (*norm_11), .length_3 = norm_12 };
    Buffer_2* buffer_8 = &res_217;
    int32_t value_2 = -128;
    while (value_2 <= ((int32_t)127)) {
        append_3(buffer_8, (int8_t)value_2);
        insert_3(dict_2, buffer_8);
        dropLast_3(buffer_8);
        value_2 = value_2 + 1;
    }
}

static enum_Status_0 decodeFile_1(State* state_24) {
    FileInputStream encoded_0 = open_3("encoded.txt", *state_24);
    FileOutputStream decoded_0 = open_2("decoded.txt");
    bool norm_70 = isOpen_4(encoded_0);
    bool norm_72 = norm_70;
    bool norm_74;
    if (norm_72) {
        bool norm_71 = isOpen_5(decoded_0);
        bool norm_73 = norm_71;
        norm_74 = norm_73;
    } else {
        norm_74 = false;
    }
    enum_Status_0 norm_128;
    if (norm_74) {
        if (decode_1(encoded_0, decoded_0, *state_24)) {
            norm_128 = tag_Success_0;
        } else {
            norm_128 = tag_DecodeError_0;
        }
    } else {
        norm_128 = tag_OpenError_0;
    }
    enum_Status_0 res_8 = norm_128;
    close_5(decoded_0);
    close_4(encoded_0, *state_24);
    return res_8;
}

static int32_t size_10(Buffer_2* thiss_767) {
    return thiss_767->length_3;
}


static bool isOpen_4(FILE* this) {
  return this != NULL;
}
    

static bool encode_4(FileInputStream fis_2, FileOutputStream fos_2, State state_7) {
    int8_t leon_buffer_5[524288] = { 0 };
    array_int8 norm_5 = (array_int8) { .data = leon_buffer_5, .length = 524288 };
    array_int8* norm_7 = &norm_5;
    int32_t leon_buffer_6[8192] = { 0 };
    array_int32 norm_6 = (array_int32) { .data = leon_buffer_6, .length = 8192 };
    array_int32* norm_8 = &norm_6;
    int32_t norm_9 = 0;
    Dictionary_2 res_219 = (Dictionary_2) { .memory_1 = (*norm_7), .pteps_1 = (*norm_8), .nextIndex_1 = norm_9 };
    Dictionary_2* dictionary_6 = &res_219;
    initialise_2(dictionary_6);
    return encodeImpl_2(dictionary_6, fis_2, fos_2, state_7);
}


static void print_5(char c) {
  printf("%c", c);
}
      

static int32_t capacity_7(Dictionary_2* thiss_755) {
    return thiss_755->pteps_1.length;
}


static FILE* open_2(char* filename) {
  FILE* this = fopen(filename, "w");
  /* this == NULL on failure */
  return this;
}
    

static void println_6(void) {
    print_5('\n');
}

static void clear_4(Buffer_2* thiss_799) {
    thiss_799->length_3 = 0;
}

static Option_0_CodeWord_0 tryReadCodeWord_1(FileInputStream fis_1, State state_6) {
    Option_0_int8 b1Opt_0 = tryReadByte_3(fis_1, state_6);
    Option_0_int8 b2Opt_0 = tryReadByte_3(fis_1, state_6);
    Tuple_Option_0_int8_Option_0_int8 tmp_2 = (Tuple_Option_0_int8_Option_0_int8) { ._1 = b1Opt_0, ._2 = b2Opt_0 };
    if (tmp_2._1.tag == tag_Some_0_int8 && tmp_2._2.tag == tag_Some_0_int8) {
        return (Option_0_CodeWord_0) { .tag = tag_Some_0_CodeWord_0, .value = (union_Option_0_CodeWord_0) { .Some_0_CodeWord_0_v = (Some_0_CodeWord_0) { .v_13 = (CodeWord_0) { .b1_0 = tmp_2._1.value.Some_0_int8_v.v_13, .b2_0 = tmp_2._2.value.Some_0_int8_v.v_13 } } } };
    } else {
        return (Option_0_CodeWord_0) { .tag = tag_None_0_CodeWord_0, .value = (union_Option_0_CodeWord_0) { .None_0_CodeWord_0_v = (None_0_CodeWord_0) { .extra = 0 } } };
    }
}

static void set_8(Buffer_2* thiss_817, Buffer_2* b_29) {
    if (isEmpty_12(b_29)) {
        clear_4(thiss_817);
    } else {
        setImpl_3(thiss_817, b_29);
    }
}

static int8_t get_5_int8(Option_0_int8 thiss_106) {
    return thiss_106.value.Some_0_int8_v.v_13;
}

static bool contains_5(Dictionary_2* thiss_800, int32_t index_31) {
    return index_31 < thiss_800->nextIndex_1;
}

static bool isRangeEqual_3(Buffer_2* thiss_797, array_int8 other_2, int32_t otherStart_2, int32_t otherSize_2) {
    int32_t norm_30 = size_10(thiss_797);
    int32_t norm_31 = norm_30;
    int32_t norm_32 = otherSize_2;
    if (norm_31 != norm_32) {
        return false;
    } else if (isEmpty_12(thiss_797)) {
        return true;
    } else {
        int32_t i_18 = 0;
        bool equal_0 = true;
        while (true) {
            bool norm_36 = equal_0;
            bool norm_38;
            if (norm_36) {
                int32_t norm_34 = i_18;
                int32_t norm_33 = size_10(thiss_797);
                int32_t norm_35 = norm_33;
                bool norm_37 = norm_34 < norm_35;
                norm_38 = norm_37;
            } else {
                norm_38 = false;
            }
            if (norm_38) {
                equal_0 = ((int32_t)other_2.data[otherStart_2 + i_18]) == ((int32_t)thiss_797->array_1.data[i_18]);
                i_18 = i_18 + 1;
            } else {
                break;
            }
        }
        return equal_0;
    }
}

static CodeWord_0 get_5_CodeWord_0(Option_0_CodeWord_0 thiss_106) {
    return thiss_106.value.Some_0_CodeWord_0_v.v_13;
}

static Option_0_int8 tryReadNext_1(FileInputStream fis_0, State state_5) {
    return tryReadByte_3(fis_0, state_5);
}

static int32_t _main(void) {
    State state_24 = newState_2();
    enum_Status_0 r1_0 = encodeFile_1(&state_24);
    bool norm_69;
    if (r1_0 == tag_Success_0) {
        norm_69 = true;
    } else {
        norm_69 = false;
    }
    enum_Status_0 norm_129;
    if (norm_69) {
        norm_129 = decodeFile_1(&state_24);
    } else {
        norm_129 = r1_0;
    }
    enum_Status_0 norm_130 = norm_129;
    return statusCode_1(&state_24, norm_130);
}

static bool isEmpty_8_int8(Option_0_int8 thiss_109) {
    if (thiss_109.tag == tag_Some_0_int8) {
        return false;
    } else if (thiss_109.tag == tag_None_0_int8) {
        return true;
    }
}

static bool encodeImpl_2(Dictionary_2* dictionary_5, FileInputStream fis_6, FileOutputStream fos_7, State state_30) {
    bool bufferFull_0 = false;
    bool ioError_0 = false;
    int8_t leon_buffer_8[64] = { 0 };
    array_int8 norm_19 = (array_int8) { .data = leon_buffer_8, .length = 64 };
    array_int8* norm_20 = &norm_19;
    int32_t norm_21 = 0;
    Buffer_2 res_218 = (Buffer_2) { .array_1 = (*norm_20), .length_3 = norm_21 };
    Buffer_2* buffer_9 = &res_218;
    Option_0_int8 currentOpt_0 = tryReadNext_1(fis_6, state_30);
    while (true) {
        bool norm_27 = !bufferFull_0;
        bool norm_29;
        if (norm_27) {
            bool norm_24 = !ioError_0;
            bool norm_26;
            if (norm_24) {
                bool norm_23 = isDefined_2_int8(currentOpt_0);
                bool norm_25 = norm_23;
                norm_26 = norm_25;
            } else {
                norm_26 = false;
            }
            bool norm_28 = norm_26;
            norm_29 = norm_28;
        } else {
            norm_29 = false;
        }
        if (norm_29) {
            int8_t c_5 = get_5_int8(currentOpt_0);
            append_3(buffer_9, c_5);
            Option_0_CodeWord_0 code_1 = encode_5(dictionary_5, buffer_9);
            bool norm_44 = isFull_5(buffer_9);
            bool norm_46 = norm_44;
            bool norm_48;
            if (norm_46) {
                norm_48 = true;
            } else {
                bool norm_45 = isEmpty_8_CodeWord_0(code_1);
                bool norm_47 = norm_45;
                norm_48 = norm_47;
            }
            bool processBuffer_0 = norm_48;
            if (processBuffer_0) {
                if (nonFull_6(dictionary_5)) {
                    insert_3(dictionary_5, buffer_9);
                } else {
                    
                }
                dropLast_3(buffer_9);
                Option_0_CodeWord_0 code2_0 = encode_5(dictionary_5, buffer_9);
                FileOutputStream norm_59 = fos_7;
                CodeWord_0 norm_58 = get_5_CodeWord_0(code2_0);
                CodeWord_0 norm_60 = norm_58;
                bool norm_61 = writeCodeWord_1(norm_59, norm_60);
                ioError_0 = !norm_61;
                clear_4(buffer_9);
                append_3(buffer_9, c_5);
            } else {
                
            }
            bool norm_62 = isFull_5(buffer_9);
            bufferFull_0 = norm_62;
            Option_0_int8 norm_63 = tryReadNext_1(fis_6, state_30);
            currentOpt_0 = norm_63;
        } else {
            break;
        }
    }
    if (!bufferFull_0 && !ioError_0) {
        Option_0_CodeWord_0 code_2 = encode_5(dictionary_5, buffer_9);
        FileOutputStream norm_65 = fos_7;
        CodeWord_0 norm_64 = get_5_CodeWord_0(code_2);
        CodeWord_0 norm_66 = norm_64;
        bool norm_67 = writeCodeWord_1(norm_65, norm_66);
        ioError_0 = !norm_67;
    } else {
        
    }
    return !bufferFull_0 && !ioError_0;
}

static int32_t lastIndex_3(Dictionary_2* thiss_818) {
    return thiss_818->nextIndex_1 - 1;
}

static int32_t capacity_5(Buffer_2* thiss_753) {
    return thiss_753->array_1.length;
}

static bool nonFull_6(Dictionary_2* thiss_780) {
    int32_t norm_50 = thiss_780->nextIndex_1;
    int32_t norm_49 = capacity_7(thiss_780);
    int32_t norm_51 = norm_49;
    bool norm_52 = norm_50 < norm_51;
    if (norm_52) {
        bool norm_53 = thiss_780->nextIndex_1 == 0 || thiss_780->memory_1.length - thiss_780->pteps_1.data[thiss_780->nextIndex_1 - 1] >= 64;
        return norm_53;
    } else {
        return false;
    }
}

static void append_3(Buffer_2* thiss_781, int8_t x_289) {
    thiss_781->array_1.data[thiss_781->length_3] = x_289;
    thiss_781->length_3 = thiss_781->length_3 + 1;
}

static bool decodeImpl_2(Dictionary_2* dictionary_8, FileInputStream fis_7, FileOutputStream fos_8, State state_31) {
    bool illegalInput_0 = false;
    bool ioError_1 = false;
    bool bufferFull_1 = false;
    Option_0_CodeWord_0 currentOpt_1 = tryReadCodeWord_1(fis_7, state_31);
    int8_t leon_buffer_0[64] = { 0 };
    array_int8 norm_80 = (array_int8) { .data = leon_buffer_0, .length = 64 };
    array_int8* norm_81 = &norm_80;
    int32_t norm_82 = 0;
    Buffer_2 res_220 = (Buffer_2) { .array_1 = (*norm_81), .length_3 = norm_82 };
    Buffer_2* buffer_12 = &res_220;
    if (isDefined_2_CodeWord_0(currentOpt_1)) {
        CodeWord_0 cw_2 = get_5_CodeWord_0(currentOpt_1);
        int32_t index_10 = codeWord2Index_1(cw_2);
        if (contains_5(dictionary_8, index_10)) {
            bool norm_90 = appendTo_3(dictionary_8, index_10, buffer_12);
            bufferFull_1 = !norm_90;
            bool norm_95 = writeBytes_2(fos_8, buffer_12);
            ioError_1 = !norm_95;
        } else {
            illegalInput_0 = true;
        }
        Option_0_CodeWord_0 norm_96 = tryReadCodeWord_1(fis_7, state_31);
        currentOpt_1 = norm_96;
    } else {
        
    }
    while (true) {
        bool norm_104 = !illegalInput_0;
        bool norm_106;
        if (norm_104) {
            bool norm_101 = !ioError_1;
            bool norm_103;
            if (norm_101) {
                bool norm_98 = !bufferFull_1;
                bool norm_100;
                if (norm_98) {
                    bool norm_97 = isDefined_2_CodeWord_0(currentOpt_1);
                    bool norm_99 = norm_97;
                    norm_100 = norm_99;
                } else {
                    norm_100 = false;
                }
                bool norm_102 = norm_100;
                norm_103 = norm_102;
            } else {
                norm_103 = false;
            }
            bool norm_105 = norm_103;
            norm_106 = norm_105;
        } else {
            norm_106 = false;
        }
        if (norm_106) {
            CodeWord_0 cw_3 = get_5_CodeWord_0(currentOpt_1);
            int32_t index_11 = codeWord2Index_1(cw_3);
            int8_t leon_buffer_1[64] = { 0 };
            array_int8 norm_107 = (array_int8) { .data = leon_buffer_1, .length = 64 };
            array_int8* norm_108 = &norm_107;
            int32_t norm_109 = 0;
            Buffer_2 res_221 = (Buffer_2) { .array_1 = (*norm_108), .length_3 = norm_109 };
            Buffer_2* entry_1 = &res_221;
            if (contains_5(dictionary_8, index_11)) {
                bool norm_110 = appendTo_3(dictionary_8, index_11, entry_1);
                illegalInput_0 = !norm_110;
            } else {
                int32_t norm_114 = index_11;
                int32_t norm_111 = lastIndex_3(dictionary_8);
                int32_t norm_112 = norm_111;
                int32_t norm_113 = 1;
                int32_t norm_115 = norm_112 + norm_113;
                if (norm_114 == norm_115) {
                    set_8(entry_1, buffer_12);
                    Buffer_2* norm_117 = entry_1;
                    int8_t norm_116 = apply_21(buffer_12, 0);
                    int8_t norm_118 = norm_116;
                    append_3(norm_117, norm_118);
                } else {
                    illegalInput_0 = true;
                }
            }
            bool norm_119 = writeBytes_2(fos_8, entry_1);
            ioError_1 = !norm_119;
            bool norm_120 = isFull_5(buffer_12);
            bufferFull_1 = norm_120;
            if (!bufferFull_1) {
                int8_t leon_buffer_2[64] = { 0 };
                array_int8 norm_121 = (array_int8) { .data = leon_buffer_2, .length = 64 };
                array_int8* norm_122 = &norm_121;
                int32_t norm_123 = 0;
                Buffer_2 res_222 = (Buffer_2) { .array_1 = (*norm_122), .length_3 = norm_123 };
                Buffer_2* tmp_1 = &res_222;
                set_8(tmp_1, buffer_12);
                Buffer_2* norm_125 = tmp_1;
                int8_t norm_124 = apply_21(entry_1, 0);
                int8_t norm_126 = norm_124;
                append_3(norm_125, norm_126);
                if (nonFull_6(dictionary_8)) {
                    insert_3(dictionary_8, tmp_1);
                } else {
                    
                }
                set_8(buffer_12, entry_1);
            } else {
                
            }
            Option_0_CodeWord_0 norm_127 = tryReadCodeWord_1(fis_7, state_31);
            currentOpt_1 = norm_127;
        } else {
            break;
        }
    }
    return !illegalInput_0 && (!ioError_1 && !bufferFull_1);
}


static bool write_8(FILE* this, int8_t x) {
  return fprintf(this, "%c", x) >= 0;
}
    

 int32_t main(int32_t argc, char** argv) {
    return _main();
}


static FILE* open_3(char* filename, void* unused) {
  FILE* this = fopen(filename, "r");
  /* this == NULL on failure */
  return this;
}
    

static int8_t apply_21(Buffer_2* thiss_769, int32_t index_29) {
    return thiss_769->array_1.data[index_29];
}

static int32_t statusCode_1(State* state_24, enum_Status_0 s_20) {
    if (s_20 == tag_Success_0) {
        println_5("success");
        return 0;
    } else if (s_20 == tag_OpenError_0) {
        println_5("couldn't open file");
        return 1;
    } else if (s_20 == tag_EncodeError_0) {
        println_5("encoding failed");
        return 2;
    } else if (s_20 == tag_DecodeError_0) {
        println_5("decoding failed");
        return 3;
    }
}

static bool isFull_5(Buffer_2* thiss_796) {
    int32_t norm_42 = thiss_796->length_3;
    int32_t norm_41 = capacity_5(thiss_796);
    int32_t norm_43 = norm_41;
    return norm_42 == norm_43;
}

static void insert_3(Dictionary_2* thiss_786, Buffer_2* b_23) {
    int32_t start_2 = getNextBufferBeginning_3(thiss_786);
    int32_t i_22 = 0;
    while (true) {
        int32_t norm_14 = i_22;
        int32_t norm_13 = size_10(b_23);
        int32_t norm_15 = norm_13;
        if (norm_14 < norm_15) {
            int32_t norm_17 = start_2 + i_22;
            int8_t norm_16 = apply_21(b_23, i_22);
            int8_t norm_18 = norm_16;
            thiss_786->memory_1.data[norm_17] = norm_18;
            i_22 = i_22 + 1;
        } else {
            break;
        }
    }
    thiss_786->pteps_1.data[thiss_786->nextIndex_1] = start_2 + i_22;
    thiss_786->nextIndex_1 = thiss_786->nextIndex_1 + 1;
}

static bool isDefined_2_CodeWord_0(Option_0_CodeWord_0 thiss_111) {
    bool norm_83 = isEmpty_8_CodeWord_0(thiss_111);
    return !norm_83;
}

static Option_0_CodeWord_0 encode_5(Dictionary_2* thiss_798, Buffer_2* b_25) {
    bool found_0 = false;
    int32_t index_9 = 0;
    while (!found_0 && index_9 < thiss_798->nextIndex_1) {
        int32_t start_3 = getBufferBeginning_3(thiss_798, index_9);
        int32_t size_5 = getBufferSize_3(thiss_798, index_9);
        if (isRangeEqual_3(b_25, thiss_798->memory_1, start_3, size_5)) {
            found_0 = true;
        } else {
            index_9 = index_9 + 1;
        }
    }
    if (found_0) {
        CodeWord_0 norm_39 = index2CodeWord_1(index_9);
        CodeWord_0 norm_40 = norm_39;
        return (Option_0_CodeWord_0) { .tag = tag_Some_0_CodeWord_0, .value = (union_Option_0_CodeWord_0) { .Some_0_CodeWord_0_v = (Some_0_CodeWord_0) { .v_13 = norm_40 } } };
    } else {
        return (Option_0_CodeWord_0) { .tag = tag_None_0_CodeWord_0, .value = (union_Option_0_CodeWord_0) { .None_0_CodeWord_0_v = (None_0_CodeWord_0) { .extra = 0 } } };
    }
}

static int32_t getBufferBeginning_3(Dictionary_2* thiss_801, int32_t index_32) {
    if (index_32 == 0) {
        return 0;
    } else {
        return thiss_801->pteps_1.data[index_32 - 1];
    }
}

static bool writeCodeWord_1(FileOutputStream fos_0, CodeWord_0 cw_0) {
    bool norm_54 = write_8(fos_0, cw_0.b1_0);
    bool norm_56 = norm_54;
    if (norm_56) {
        bool norm_55 = write_8(fos_0, cw_0.b2_0);
        bool norm_57 = norm_55;
        return norm_57;
    } else {
        return false;
    }
}


static bool close_5(FILE* this) {
  if (this != NULL)
    return fclose(this) == 0;
  else
    return true;
}
    

static int32_t codeWord2Index_1(CodeWord_0 cw_1) {
    int32_t signed_1 = ((int32_t)(((uint32_t)((int32_t)cw_1.b1_0)) << 8)) | (255 & ((int32_t)cw_1.b2_0));
    return signed_1 + 32768;
}

static bool decode_1(FileInputStream fis_4, FileOutputStream fos_4, State state_9) {
    int8_t leon_buffer_3[524288] = { 0 };
    array_int8 norm_75 = (array_int8) { .data = leon_buffer_3, .length = 524288 };
    array_int8* norm_77 = &norm_75;
    int32_t leon_buffer_4[8192] = { 0 };
    array_int32 norm_76 = (array_int32) { .data = leon_buffer_4, .length = 8192 };
    array_int32* norm_78 = &norm_76;
    int32_t norm_79 = 0;
    Dictionary_2 res_223 = (Dictionary_2) { .memory_1 = (*norm_77), .pteps_1 = (*norm_78), .nextIndex_1 = norm_79 };
    Dictionary_2* dictionary_9 = &res_223;
    initialise_2(dictionary_9);
    return decodeImpl_2(dictionary_9, fis_4, fos_4, state_9);
}

static bool isDefined_2_int8(Option_0_int8 thiss_111) {
    bool norm_22 = isEmpty_8_int8(thiss_111);
    return !norm_22;
}

static CodeWord_0 index2CodeWord_1(int32_t index_3) {
    int32_t signed_0 = index_3 - 32768;
    int8_t b2_2 = (int8_t)signed_0;
    int8_t b1_2 = (int8_t)((int32_t)(((uint32_t)signed_0) >> 8));
    return (CodeWord_0) { .b1_0 = b1_2, .b2_0 = b2_2 };
}


static bool close_4(FILE* this, void* unused) {
  if (this != NULL)
    return fclose(this) == 0;
  else
    return true;
}
    

static void println_5(char* s_19) {
    print_4(s_19);
    println_6();
}

static int32_t getNextBufferBeginning_3(Dictionary_2* thiss_783) {
    if (thiss_783->nextIndex_1 == 0) {
        return 0;
    } else {
        return thiss_783->pteps_1.data[thiss_783->nextIndex_1 - 1];
    }
}


static bool isOpen_5(FILE* this) {
  return this != NULL;
}
    


static int8_t impl_4(FILE** this, void** unused, bool* valid) {
  int8_t x;
  *valid = fscanf(*this, "%c", &x) == 1;
  return x;
}
      


static void print_4(char* s) {
  printf("%s", s);
}
      

static void dropLast_3(Buffer_2* thiss_785) {
    thiss_785->length_3 = thiss_785->length_3 - 1;
}

static enum_Status_0 encodeFile_1(State* state_24) {
    FileInputStream input_1 = open_3("input.txt", *state_24);
    FileOutputStream encoded_1 = open_2("encoded.txt");
    bool norm_0 = isOpen_4(input_1);
    bool norm_2 = norm_0;
    bool norm_4;
    if (norm_2) {
        bool norm_1 = isOpen_5(encoded_1);
        bool norm_3 = norm_1;
        norm_4 = norm_3;
    } else {
        norm_4 = false;
    }
    enum_Status_0 norm_68;
    if (norm_4) {
        if (encode_4(input_1, encoded_1, *state_24)) {
            norm_68 = tag_Success_0;
        } else {
            norm_68 = tag_EncodeError_0;
        }
    } else {
        norm_68 = tag_OpenError_0;
    }
    enum_Status_0 res_9 = norm_68;
    close_5(encoded_1);
    close_4(input_1, *state_24);
    return res_9;
}

static int32_t getBufferSize_3(Dictionary_2* thiss_795, int32_t index_30) {
    if (index_30 == 0) {
        return thiss_795->pteps_1.data[0];
    } else {
        return thiss_795->pteps_1.data[index_30] - thiss_795->pteps_1.data[index_30 - 1];
    }
}

static void* newState_2(void) { return NULL; }
