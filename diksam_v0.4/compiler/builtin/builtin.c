#include <stdio.h>
#include "../diksamc.h"


char *st_diksam_lang_dkh_text[] = {
    "void print(string str);
    "void println(string str) {
    "    print(str + \"\\n\");
    "}
    "
    "public class File {
    "    native_pointer fp;
    "    constructor initialize(native_pointer fp) {
    "\tthis.fp = fp;
    "    }
    "}
    "
    "File fopen(string file_name, string mode);
    "string fgets(File file);
    "void fputs(string str, File file);
    "void fclose(File file);
    "
    "double to_double(int int_value) {
    "    return int_value;
    "}
    "
    "int to_int(double double_value) {
    "    return double_value;
    "}
    "
    "int parse_int(string str) throws NumberFormatException;
    "double parse_double(string str) throws NumberFormatException;
    "
    "void exit(int status);
    "void randomize();
    "int random(int range);
    "
    "class StackTrace {
    "    int\tline_number;
    "    string file_name;
    "    string function_name;
    "}
    "
    "abstract public class Exception {
    "    public string message;
    "    public StackTrace[] stack_trace;
    "    public void print_stack_trace() {
    "\tint i;
    "\tprintln(\"Exception occured. \" + this.message);
    "\tfor (i = 0; i < this.stack_trace.size(); i++) {
    "\t    println(\"\\tat \" 
    "\t\t    + this.stack_trace[i].function_name
    "\t\t    + \"(\" + this.stack_trace[i].file_name
    "\t\t    + \":\" + this.stack_trace[i].line_number + \")\");
    "\t}
    "    }
    "    public virtual constructor initialize() {
    "\tthis.stack_trace = new StackTrace[0];
    "    }
    "}
    "
    "abstract public class BugException : Exception {
    "}
    "
    "abstract public class RuntimeException : Exception {
    "}
    "
    "public class NullPointerException : BugException {
    "}
    "
    "public class ArrayIndexOutOfBoundsException : BugException {
    "}
    "
    "public class StringIndexOutOfBoundsException : BugException {
    "}
    "
    "public class DivisionByZeroException : RuntimeException {
    "}
    "
    "public class MultibyteCharacterConvertionException : RuntimeException {
    "}
    "
    "public class ClassCastException : BugException {
    "}
    "
    "public abstract class ApplicationException : Exception {
    "}
    "
    "public class NumberFormatException : ApplicationException {
    "}
    "
    "delegate int HogeDelegate(int value);
    "
    "// BUGBUG for test routine
    "void test_native(HogeDelegate dele);
    "
    "void foo_file(File file) {
    "}
    NULL
};
char *st_diksam_lang_dkm_text[] = {
    "require diksam.lang;
    "
    "native_pointer __fopen(string file_name, string mode);
    "string __fgets(native_pointer fp);
    "void __fputs(string str, native_pointer fp);
    "void __fclose(native_pointer fp);
    "
    "File fopen(string file_name, string mode) {
    "    native_pointer fp = __fopen(file_name, mode);
    "    if (fp == null) {
    "\treturn null;
    "    } else {
    "\treturn new File(fp);
    "    }
    "}
    "
    "string fgets(File file) {
    "    return __fgets(file.fp);
    "}
    "
    "void fputs(string str, File file) {
    "    __fputs(str, file.fp);
    "}
    "
    "void fclose(File file) {
    "    __fclose(file.fp);
    "}
    NULL
};
char *st_diksam_math_dkh_text[] = {
    "double fabs(double z);
    "double pow(double z, double x);
    "double fmod(double number, double divisor);
    "double ceil(double z);
    "double floor(double z);
    "double sqrt(double z);
    "double exp(double z);
    "double log10(double z);
    "double log(double z);
    "double sin(double radian);
    "double cos(double radian);
    "double tan(double radian);
    "double asin(double arg);
    "double acos(double arg);
    "double atan(double arg);
    "double atan2(double num, double den);
    "double sinh(double value);
    "double cosh(double value);
    "double tanh(double value);
    NULL
};

BuiltinScript dkc_builtin_script[] = {
    {"diksam.lang", DKH_SOURCE, st_diksam_lang_dkh_text},
    {"diksam.lang", DKM_SOURCE, st_diksam_lang_dkm_text},
    {"diksam.math", DKH_SOURCE, st_diksam_math_dkh_text},
    {NULL, DKM_SOURCE, NULL}
};