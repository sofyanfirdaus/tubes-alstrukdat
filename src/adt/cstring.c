#include "cstring.h"

#include <stdlib.h>

#include "boolean.h"

String StringFrom(char* str) {
    String res;
    int i = 0;
    while (str[i] != 0) {
        STR_VALUE(res)[i] = str[i];
        i++;
    }
    // memastikan bahwa string hasilnya null-terminated
    STR_VALUE(res)[i] = 0;
    return res;
}

String StringFromArr(char str[], int size) {
    String res;
    int i = 0;
    while (i < size) {
        STR_VALUE(res)[i] = str[i];
        i++;
    }
    // memastikan bahwa string hasilnya null-terminated
    STR_VALUE(res)[i] = 0;
    return res;
}

void copy_string(String* dest, String src) {
    int idx;
    for (idx = 0; idx <= length(src); idx++) {
        STR_VALUE(*dest)[idx] = STR_VALUE(src)[idx];  // menyalin semua isinya termasuk null di akhir
    }
}

int length(String str) {
    // MenurStringt definisi, String dalam bahasa C selalu null-terminated
    int i = 0;
    while (STR_VALUE(str)[i] != 0) {
        i++;
    }
    return i;
}

String concat_string(String str1, String str2) {
    String result;
    int len1 = length(str1);
    int len2 = length(str2);
    int i;
    for (i = 0; i <= len1 + len2; i++) {
        if (i < len1) {
            STR_VALUE(result)[i] = STR_VALUE(str1)[i];
        } else {
            STR_VALUE(result)[i] = STR_VALUE(str2)[i - len1];
        }
    }
    return result;
}

String trim_end(String str) {
    int len = length(str);
    boolean ok = false;
    for (int i = len - 1; i >= 0 && !ok; i--) {
        if (STR_VALUE(str)[i] != ' ' && STR_VALUE(str)[i] != '\t' && STR_VALUE(str)[i] != '\n') {
            STR_VALUE(str)[i + 1] = 0;
            ok = true;
        }
    }
    return str;
}

String substring(String str, int start, int end) {
    int idx;
    for (idx = 0; idx < end - start; idx++) {
        STR_VALUE(str)[idx] = STR_VALUE(str)[start + idx];
    }
    STR_VALUE(str)[end - start] = 0;
    return str;
}

boolean is_string_equal(String a, String b) {
    int len_a = length(a);
    int len_b = length(b);
    boolean equal = len_a == len_b;
    for (int i = 0; i < len_a && equal; i++) {
        equal = STR_VALUE(a)[i] == STR_VALUE(b)[i];
    }
    return equal;
}

// is str startswith substr
boolean is_string_startswith(String str, String substr) {
    int len_substr = length(substr);

    boolean equal = true;
    for (int i = 0; i < len_substr; i++) {
        equal = STR_VALUE(str)[i] == STR_VALUE(substr)[i];
    }
    return equal;
}