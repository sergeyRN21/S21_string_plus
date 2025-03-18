#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_memchr1) {
  // ARRANGE
  char str1[] = "abcdefg";
  char c = 'c';

  // ACT
  char *ans1 = s21_memchr(str1, c, 5);

  // ASSERT
  ck_assert_ptr_eq(ans1, memchr(str1, c, 5));
}
END_TEST

START_TEST(test_memchr2) {
  // ARRANGE
  char str1[] = "abcdefg";
  char c = '\0';

  // ACT
  char *ans1 = s21_memchr(str1, c, 2);

  // ASSERT
  ck_assert_ptr_eq(ans1, memchr(str1, c, 2));
}
END_TEST

START_TEST(test_memchr3) {
  // ARRANGE
  char str1[] = "abc\0defg";
  char c = 'e';

  // ACT
  char *ans1 = s21_memchr(str1, c, 10);

  // ASSERT
  ck_assert_ptr_eq(ans1, memchr(str1, c, 10));
}
END_TEST

START_TEST(test_strchr1) {
  // ARRANGE
  char str1[] = "abcdefg";
  char c = 'c';

  // ACT
  char *ans1 = s21_strchr(str1, c);

  // ASSERT
  ck_assert_ptr_eq(ans1, strchr(str1, c));
}
END_TEST

START_TEST(test_strchr2) {
  // ARRANGE
  char str1[] = "abecdefg";
  char c = 'e';

  // ACT
  char *ans1 = s21_strchr(str1, c);

  // ASSERT
  ck_assert_ptr_eq(ans1, strchr(str1, c));
}
END_TEST

START_TEST(test_strchr3) {
  // ARRANGE
  char str1[] = "abc\0defg";
  char c = 'e';

  // ACT
  char *ans1 = s21_strchr(str1, c);

  // ASSERT
  ck_assert_ptr_eq(ans1, strchr(str1, c));
}
END_TEST

START_TEST(test_strrchr1) {
  // ARRANGE
  char str1[] = "abcdefgabc";
  char c = 'a';

  // ACT
  char *ans1 = s21_strchr(str1, c);

  // ASSERT
  ck_assert_ptr_eq(ans1, strchr(str1, c));
}
END_TEST

START_TEST(test_strrchr2) {
  // ARRANGE
  char str1[] = "abcdefgabc";
  char c = 'y';

  // ACT
  char *ans1 = s21_strchr(str1, c);

  // ASSERT
  ck_assert_ptr_eq(ans1, strchr(str1, c));
}
END_TEST

START_TEST(test_strrchr3) {
  // ARRANGE
  char str1[] = "abcdef\0gabc";
  char c = 'a';

  // ACT
  char *ans1 = s21_strchr(str1, c);

  // ASSERT
  ck_assert_ptr_eq(ans1, strchr(str1, c));
}
END_TEST

Suite *memchr_test(void) {
  Suite *s;
  TCase *tc_first, *tc_second, *tc_third;

  s = suite_create("memchr");

  tc_first = tcase_create("first");
  tcase_add_test(tc_first, test_memchr1);
  suite_add_tcase(s, tc_first);

  tc_second = tcase_create("second");
  tcase_add_test(tc_second, test_memchr2);
  suite_add_tcase(s, tc_second);

  tc_third = tcase_create("third");
  tcase_add_test(tc_third, test_memchr3);
  suite_add_tcase(s, tc_third);

  return s;
}

Suite *strchr_test(void) {
  Suite *s;
  TCase *tc_first, *tc_second, *tc_third;

  s = suite_create("strchr");

  tc_first = tcase_create("first");
  tcase_add_test(tc_first, test_strchr1);
  suite_add_tcase(s, tc_first);

  tc_second = tcase_create("second");
  tcase_add_test(tc_second, test_strchr2);
  suite_add_tcase(s, tc_second);

  tc_third = tcase_create("third");
  tcase_add_test(tc_third, test_strchr3);
  suite_add_tcase(s, tc_third);

  return s;
}

Suite *strrchr_test(void) {
  Suite *s;
  TCase *tc_first, *tc_second, *tc_third;

  s = suite_create("strrchr");

  tc_first = tcase_create("first");
  tcase_add_test(tc_first, test_strrchr1);
  suite_add_tcase(s, tc_first);

  tc_second = tcase_create("second");
  tcase_add_test(tc_second, test_strrchr2);
  suite_add_tcase(s, tc_second);

  tc_third = tcase_create("third");
  tcase_add_test(tc_third, test_strrchr3);
  suite_add_tcase(s, tc_third);

  return s;
}

START_TEST(test_strcspn1) {
  // ARRANGE
  char str1[] = "abcdefg";
  char str2[] = "qgjy";

  // ACT
  s21_size_t ans1 = s21_strcspn(str1, str2);

  // ASSERT
  ck_assert_uint_eq(ans1, strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn2) {
  // ARRANGE
  char str3[] = "abced";
  char str4[] = "ab";

  // ACT
  s21_size_t ans2 = s21_strcspn(str3, str4);

  // ASSERT
  ck_assert_uint_eq(ans2, strcspn(str3, str4));
}
END_TEST

START_TEST(test_strcspn3) {
  // ARRANGE
  char str5[] = "abcdef\\g\n    abc";
  char str6[] = " \n\t\\";

  // ACT
  s21_size_t ans3 = s21_strcspn(str5, str6);

  // ASSERT
  ck_assert_uint_eq(ans3, strcspn(str5, str6));
}
END_TEST

START_TEST(test_strcspn4) {
  // ARRANGE
  char str7[] = "abcdef";
  char str8[] = "";

  // ACT
  s21_size_t ans4 = s21_strcspn(str7, str8);

  // ASSERT
  ck_assert_uint_eq(ans4, strcspn(str7, str8));
}
END_TEST

START_TEST(test_strstr1) {
  // ARRANGE
  char haystack1[] = "abcdefghi";
  char needle1[] = "";

  // ACT
  char *ans1 = s21_strstr(haystack1, needle1);

  // ASSERT
  ck_assert_str_eq(ans1, strstr(haystack1, needle1));
}
END_TEST

START_TEST(test_strstr2) {
  // ARRANGE
  char haystack2[] = "";
  char needle2[] = "abc";

  // ACT
  char *ans2 = s21_strstr(haystack2, needle2);

  // ASSERT
  ck_assert_ptr_eq(ans2, strstr(haystack2, needle2));
}
END_TEST

START_TEST(test_strstr3) {
  // ARRANGE
  char haystack3[] = "abcde";
  char needle3[] = "c";

  // ACT
  char *ans3 = s21_strstr(haystack3, needle3);

  // ASSERT
  ck_assert_str_eq(ans3, strstr(haystack3, needle3));
}
END_TEST

START_TEST(test_strstr4) {
  // ARRANGE
  char haystack4[] = "abcdef";
  char needle4[] = "cdefg";

  // ACT
  char *ans4 = s21_strstr(haystack4, needle4);

  // ASSERT
  ck_assert_ptr_eq(ans4, strstr(haystack4, needle4));
}
END_TEST

START_TEST(test_strstr5) {
  // ARRANGE
  char haystack5[] = "";
  char needle5[] = "";

  // ACT
  char *ans5 = s21_strstr(haystack5, needle5);

  // ASSERT
  ck_assert_str_eq(ans5, strstr(haystack5, needle5));
}
END_TEST

START_TEST(test_strtok1) {
  // ARRANGE
  char str1_s21[] = "Hello, my name - Optimus Prime!";
  char str1_orig[] = "Hello, my name - Optimus Prime!";
  char *delim1 = ", -!";

  // ACT & ASSERT
  char *s21_token = s21_strtok(str1_s21, delim1);
  char *orig_token = strtok(str1_orig, delim1);
  while (s21_token && orig_token) {
    ck_assert_str_eq(s21_token, orig_token);
    s21_token = s21_strtok(s21_NULL, delim1);
    orig_token = strtok(s21_NULL, delim1);
  }
  ck_assert_ptr_eq(s21_token, orig_token);
}
END_TEST

START_TEST(test_strtok2) {
  // ARRANGE
  char str2_s21[] = "";
  char str2_orig[] = "";
  char *delim2 = " ,.";

  // ACT & ASSERT
  char *s21_token = s21_strtok(str2_s21, delim2);
  char *orig_token = strtok(str2_orig, delim2);
  while (s21_token && orig_token) {
    ck_assert_str_eq(s21_token, orig_token);
    s21_token = s21_strtok(s21_NULL, delim2);
    orig_token = strtok(s21_NULL, delim2);
  }
  ck_assert_ptr_eq(s21_token, orig_token);
}
END_TEST

START_TEST(test_strtok3) {
  // ARRANGE
  char str3_s21[] = "good";
  char str3_orig[] = "good";
  char *delim3 = "";

  // ACT & ASSERT
  char *s21_token = s21_strtok(str3_s21, delim3);
  char *orig_token = strtok(str3_orig, delim3);
  while (s21_token && orig_token) {
    ck_assert_str_eq(s21_token, orig_token);
    s21_token = s21_strtok(s21_NULL, delim3);
    orig_token = strtok(s21_NULL, delim3);
  }
  ck_assert_ptr_eq(s21_token, orig_token);
}
END_TEST

START_TEST(test_strtok4) {
  // ARRANGE
  char str4_s21[] = "hello goodboy";
  char str4_orig[] = "hello goodboy";
  char *delim4 = "";

  // ACT & ASSERT
  char *s21_token = s21_strtok(str4_s21, delim4);
  char *orig_token = strtok(str4_orig, delim4);
  while (s21_token && orig_token) {
    ck_assert_str_eq(s21_token, orig_token);
    s21_token = s21_strtok(s21_NULL, delim4);
    orig_token = strtok(s21_NULL, delim4);
  }
  ck_assert_ptr_eq(s21_token, orig_token);
}
END_TEST

START_TEST(test_strtok5) {
  // ARRANGE
  char str5_s21[] = ",. -!;";
  char str5_orig[] = ",. -!;";
  char *delim5 = " ,.-!;";

  // ACT & ASSERT
  char *s21_token = s21_strtok(str5_s21, delim5);
  char *orig_token = strtok(str5_orig, delim5);
  while (s21_token && orig_token) {
    ck_assert_str_eq(s21_token, orig_token);
    s21_token = s21_strtok(s21_NULL, delim5);
    orig_token = strtok(s21_NULL, delim5);
  }
  ck_assert_ptr_eq(s21_token, orig_token);
}
END_TEST

Suite *strcspn_test(void) {
  Suite *s;
  TCase *tc_first, *tc_second, *tc_third, *tc_fourth;

  s = suite_create("strcspn");

  tc_first = tcase_create("first");
  tcase_add_test(tc_first, test_strcspn1);
  suite_add_tcase(s, tc_first);

  tc_second = tcase_create("second");
  tcase_add_test(tc_second, test_strcspn2);
  suite_add_tcase(s, tc_second);

  tc_third = tcase_create("third");
  tcase_add_test(tc_third, test_strcspn3);
  suite_add_tcase(s, tc_third);

  tc_fourth = tcase_create("fourth");
  tcase_add_test(tc_fourth, test_strcspn4);
  suite_add_tcase(s, tc_fourth);

  return s;
}

Suite *strstr_test(void) {
  Suite *s;
  TCase *tc_first, *tc_second, *tc_third, *tc_fourth, *tc_fifth;

  s = suite_create("strstr");

  tc_first = tcase_create("first");
  tcase_add_test(tc_first, test_strstr1);
  suite_add_tcase(s, tc_first);

  tc_second = tcase_create("second");
  tcase_add_test(tc_second, test_strstr2);
  suite_add_tcase(s, tc_second);

  tc_third = tcase_create("third");
  tcase_add_test(tc_third, test_strstr3);
  suite_add_tcase(s, tc_third);

  tc_fourth = tcase_create("fourth");
  tcase_add_test(tc_fourth, test_strstr4);
  suite_add_tcase(s, tc_fourth);

  tc_fifth = tcase_create("fifth");
  tcase_add_test(tc_fifth, test_strstr5);
  suite_add_tcase(s, tc_fifth);

  return s;
}

Suite *strtok_test(void) {
  Suite *s;
  TCase *tc_first, *tc_second, *tc_third, *tc_fourth, *tc_fifth;

  s = suite_create("strtok");

  tc_first = tcase_create("first");
  tcase_add_test(tc_first, test_strtok1);
  suite_add_tcase(s, tc_first);

  tc_second = tcase_create("second");
  tcase_add_test(tc_second, test_strtok2);
  suite_add_tcase(s, tc_second);

  tc_third = tcase_create("third");
  tcase_add_test(tc_third, test_strtok3);
  suite_add_tcase(s, tc_third);

  tc_fourth = tcase_create("fourth");
  tcase_add_test(tc_fourth, test_strtok4);
  suite_add_tcase(s, tc_fourth);

  tc_fifth = tcase_create("fifth");
  tcase_add_test(tc_fifth, test_strtok5);
  suite_add_tcase(s, tc_fifth);

  return s;
}

START_TEST(test_s21_memcmp) {
  char *s1 = "Hello, world!";
  char *s2 = "Hello, world";
  ck_assert_int_eq(s21_memcmp(s1, s2, 13), memcmp(s1, s2, 13));
}
END_TEST

START_TEST(test_s21_strncmp) {
  char *s1 = "Hello, world!";
  char *s2 = "Hello, world";
  ck_assert_int_eq(s21_strncmp(s1, s2, 13), strncmp(s1, s2, 13));
}
END_TEST

START_TEST(test_s21_strerror) {
  for (size_t i = 0; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_memcmp_strncmp_strerror(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcmp_strncmp_strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strerror);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_memcpy_test) {
  char dest1[20] = "1234567";
  char dest2[20] = "1234567";
  char dest_1[] = "H&!o# w0r|f.";
  char dest_2[] = "H&!o# w0r|f.";
  char src[] = "hahaxx";
  char src1[5] = "\0";
  ck_assert_pstr_eq(s21_memcpy(dest1, src, sizeof src),
                    memcpy(dest2, src, sizeof src));
  ck_assert_pstr_eq(s21_memcpy(dest_1, src1, 3), memcpy(dest_2, src1, 3));
  ck_assert_pstr_eq(s21_memcpy(dest_1, src, sizeof src),
                    memcpy(dest_2, src, sizeof src));
}
END_TEST

START_TEST(s21_memset_test) {
  char dest1[] = "1234567";
  char dest2[] = "1234567";
  char dest_1[] = "He!lo . world\0";
  char dest_2[] = "He!lo . world\0";
  int c = 'x';
  ck_assert_pstr_eq(s21_memset(dest1, c, strlen(dest1)),
                    memset(dest2, c, strlen(dest2)));
  ck_assert_pstr_eq(s21_memset(dest1, c, 2), memset(dest2, c, 2));
  ck_assert_pstr_eq(s21_memset(dest_1, c, strlen(dest_1)),
                    memset(dest_2, c, strlen(dest_2)));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char dest1[10] = "1234567";
  char dest2[10] = "1234567";
  char dest_1[] = "He!lo . world\0";
  char dest_2[] = "He!lo . world\0";
  char src[] = "hi";
  char src1[5] = "\0";
  char src2[10] = "hi\0";
  ck_assert_str_eq(s21_strncpy(dest1, src, 3), strncpy(dest2, src, 3));
  ck_assert_str_eq(s21_strncpy(dest1, src2, 5), strncpy(dest2, src2, 5));
  ck_assert_str_eq(s21_strncpy(dest_1, src1, 5), strncpy(dest_2, src1, 5));
  ck_assert_str_eq(s21_strncpy(dest_1, src2, 10), strncpy(dest_2, src2, 10));
}
END_TEST

Suite *suite_memcpy_memset_strncpy(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("memcpy_memset_strncpy");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memcpy_test);
  tcase_add_test(tc_core, s21_memset_test);
  tcase_add_test(tc_core, s21_strncpy_test);
  suite_add_tcase(s, tc_core);
  return s;
}

START_TEST(s21_strlen_test) {
  char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_2[10] = "<<<";
  char test_4[10] = "5";
  char test_21[10] = "<<<";
  char test_41[10] = "5";
  char test_44[2] = "5";
  char test_5[] = "";
  ck_assert_str_eq(s21_strncat(test_2, test_4, 4),
                   strncat(test_21, test_41, 1));
  ck_assert_str_eq(s21_strncat(test_44, test_5, 0), strncat(test_4, test_5, 0));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

Suite *suite_strlen_strncat_strpbrk(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strlen_strncat_strpbrk");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strlen_test);
  tcase_add_test(tc_core, s21_strncat_test);
  tcase_add_test(tc_core, s21_strpbrk_test);
  suite_add_tcase(s, tc_core);
  return s;
}

START_TEST(s21_sprintf_test) {
  char s2[500];
  char s1[500];
  char s3[500];
  char s4[500];
  char s5[500];
  char s6[500];
  char s7[500];
  char s8[500];
  char s9[500];
  char s10[500];
  char s11[500];
  char s12[500];
  char s13[500];
  char s14[500];
  char s15[500];
  char s16[500];
  char s17[500];
  char s18[500];
  char s19[500];
  char s20[500];
  char c = 'x';
  wchar_t c1 = L'\x41';
  short int d = 110;
  double f = 1211.55321;
  char *s = "stopmakehaha";
  wchar_t *ss = L"stopmakehaha";
  unsigned u = 56456651;
  long int d1 = 9223372036854775807;
  int d2 = -12345;

  // без флагов
  sprintf(s2, "%15.6d Ha%15sha %10lc ha%10.5hdha %.0fhah%20.10ua %30.7ld", d2,
          s, c1, d, f, u, d1);
  s21_sprintf(s1, "%15.6d Ha%15sha %10lc ha%10.5hdha %.0fhah%20.10ua %30.7ld",
              d2, s, c1, d, f, u, d1);
  ck_assert_str_eq(s1, s2);

  // флаг -
  sprintf(s4,
          "%-10.6d Ha%-15.sha %c ha%-10.6hdha %-15.16fhah%-20.10ua %-30.7ld",
          d2, s, c, d, f, u, d1);
  s21_sprintf(
      s3, "%-10.6d Ha%-15.sha %c ha%-10.6hdha %-15.16fhah%-20.10ua %-30.7ld",
      d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s3, s4);

  // флаг -+
  sprintf(
      s6,
      "%-+10.6d Ha%-15.8sha %c ha%-+10.6hdha %-+15.1fhah%-20.10ua %-+30.7ld",
      d2, s, c, d, f, u, d1);
  s21_sprintf(
      s5,
      "%-+10.6d Ha%-15.8sha %c ha%-+10.6hdha %-+15.1fhah%-20.10ua %-+30.7ld",
      d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s5, s6);

  // флаг -пробел
  sprintf(s8,
          "%- 15.8d Ha%-15sha %c ha%- 10.6hdha %- 15.1fhah%-20.10ua %- 30.7ld",
          d2, s, c, d, f, u, d1);
  s21_sprintf(
      s7,
      "%- 15.8d Ha%-15.12sha %c ha%- 10.6hdha %- 15.1fhah%-20.10ua %- 30.7ld",
      d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s7, s8);

  // флаг пробел
  sprintf(s10, "% 10.6d Ha%12.0sha %c ha% 10.6hdha % 15.1fhah%20.10ua % 30.7ld",
          d2, s, c, d, f, u, d1);
  s21_sprintf(s9,
              "% 10.6d Ha%12.0sha %c ha% 10.6hdha % 15.1fhah%20.10ua % 30.7ld",
              d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s9, s10);

  // ширина < точность
  // без флагов
  sprintf(s12, "%7.15d Ha%5.10sha %c ha%5.10hdha %10.15fhah%10.20ua %7.30ld",
          d2, s, c, d, f, u, d1);
  s21_sprintf(s11,
              "%7.15d Ha%5.10sha %c ha%5.10hdha %10.15fhah%10.20ua %7.30ld", d2,
              s, c, d, f, u, d1);
  ck_assert_str_eq(s11, s12);

  // флаг -
  sprintf(s14,
          "%-7.15d Ha%-12.20sha %c ha%-5.10hdha %-10fhah%-10.20ua %-7.30ld", d2,
          s, c, d, f, u, d1);
  s21_sprintf(s13,
              "%-7.15d Ha%-12.20sha %c ha%-5.10hdha %-10fhah%-10.20ua %-7.30ld",
              d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s13, s14);

  // флаг -+
  sprintf(s16, "%+-7.15d Ha%-.sha %c ha%+-5.10hdha %+-10.fhah%-10.ua %-7.30ld",
          d2, s, c, d, f, u, d1);
  s21_sprintf(s15,
              "%+-7.15d Ha%-.sha %c ha%+-5.10hdha %+-10.fhah%-10.ua %-7.30ld",
              d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s15, s16);

  // флаг -пробел
  sprintf(
      s18,
      "%- 7.15d Ha%-2.8sha %-6c ha%- 5.10hdha %- 10.15fhah%-10.20ua %- 7.30ld",
      d2, s, c, d, f, u, d1);
  s21_sprintf(
      s17,
      "%- 7.15d Ha%-2.8sha %-6c ha%- 5.10hdha %- 10.15fhah%-10.20ua %- 7.30ld",
      d2, s, c, d, f, u, d1);
  ck_assert_str_eq(s17, s18);

  // флаг пробел
  sprintf(
      s20,
      "% 7.15d Ha%-2.50lsha %5c ha% 5.hdha % 10.50fhah%10.20ua % 7.30ld %s %lc",
      d2, ss, c, d, f, u, d1, "fff", c1);
  s21_sprintf(
      s19,
      "% 7.15d Ha%-2.50lsha %5c ha% 5.hdha % 10.50fhah%10.20ua % 7.30ld %s %lc",
      d2, ss, c, d, f, u, d1, "fff", c1);
  ck_assert_str_eq(s19, s20);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sprintf");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_sprintf_test);
  suite_add_tcase(s, tc_core);
  return s;
}

START_TEST(test_s21_to_upper1) {
  // ARRANGE
  const char *input = "hello world";
  const char *expected = "HELLO WORLD";

  // ACT
  char *result = s21_to_upper(input);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper2) {
  // ARRANGE
  const char *input = "12345";
  const char *expected = "12345";

  // ACT
  char *result = s21_to_upper(input);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper3) {
  // ARRANGE
  const char *input = "MixEd CaSe";
  const char *expected = "MIXED CASE";

  // ACT
  char *result = s21_to_upper(input);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower1) {
  // ARRANGE
  const char *input = "HELLO WORLD";
  const char *expected = "hello world";

  // ACT
  char *result = s21_to_lower(input);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower2) {
  // ARRANGE
  const char *input = "12345";
  const char *expected = "12345";

  // ACT
  char *result = s21_to_lower(input);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower3) {
  // ARRANGE
  const char *input = "MixEd CaSe";
  const char *expected = "mixed case";

  // ACT
  char *result = s21_to_lower(input);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert1) {
  // ARRANGE
  const char *src = "Hello World";
  const char *str = "Beautiful ";
  s21_size_t start_index = 6;
  const char *expected = "Hello Beautiful World";

  // ACT
  char *result = s21_insert(src, str, start_index);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert2) {
  // ARRANGE
  const char *src = "Hello";
  const char *str = "!";
  s21_size_t start_index = 5;
  const char *expected = "Hello!";

  // ACT
  char *result = s21_insert(src, str, start_index);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert3) {
  // ARRANGE
  const char *src = "StartEnd";
  const char *str = "Middle";
  s21_size_t start_index = 5;
  const char *expected = "StartMiddleEnd";

  // ACT
  char *result = s21_insert(src, str, start_index);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim1) {
  // ARRANGE
  const char *src = "   Hello World   ";
  const char *trim_chars = " ";
  const char *expected = "Hello World";

  // ACT
  char *result = s21_trim(src, trim_chars);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim2) {
  // ARRANGE
  const char *src = "***Hello***";
  const char *trim_chars = "*";
  const char *expected = "Hello";

  // ACT
  char *result = s21_trim(src, trim_chars);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim3) {
  // ARRANGE
  const char *src = "--==Hello World==--";
  const char *trim_chars = "-=";
  const char *expected = "Hello World";

  // ACT
  char *result = s21_trim(src, trim_chars);

  // ASSERT
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *suite_lower_upper_trim_insert(void) {
  Suite *s;
  TCase *tc_upper, *tc_lower, *tc_insert, *tc_trim;

  s = suite_create("lower_upper_trim_insert");

  tc_upper = tcase_create("to_upper");
  tcase_add_test(tc_upper, test_s21_to_upper1);
  tcase_add_test(tc_upper, test_s21_to_upper2);
  tcase_add_test(tc_upper, test_s21_to_upper3);
  suite_add_tcase(s, tc_upper);

  tc_lower = tcase_create("to_lower");
  tcase_add_test(tc_lower, test_s21_to_lower1);
  tcase_add_test(tc_lower, test_s21_to_lower2);
  tcase_add_test(tc_lower, test_s21_to_lower3);
  suite_add_tcase(s, tc_lower);

  tc_insert = tcase_create("insert");
  tcase_add_test(tc_insert, test_s21_insert1);
  tcase_add_test(tc_insert, test_s21_insert2);
  tcase_add_test(tc_insert, test_s21_insert3);
  suite_add_tcase(s, tc_insert);

  tc_trim = tcase_create("trim");
  tcase_add_test(tc_trim, test_s21_trim1);
  tcase_add_test(tc_trim, test_s21_trim2);
  tcase_add_test(tc_trim, test_s21_trim3);
  suite_add_tcase(s, tc_trim);

  return s;
}

int main() {
  int number_failed_strcspn, number_failed_strstr, number_failed_strtok,
      number_failed_memcmp_strncmp_strerror, no_failed_memcpy_memset_strncpy,
      no_failed_strlen_strncat_strpbrk, no_failed_memchr, no_failed_strchr,
      no_failed_strrchr, no_failed_sprintf, no_failed_lower_upper_trim_insert;
  Suite *s_strcspn, *s_strstr, *s_strtok, *s_memcmp_strncmp_strerror,
      *s_memcpy_memset_strncpy, *s_strlen_strncat_strpbrk, *s_memchr, *s_strchr,
      *s_strrchr, *s_sprintf, *s_lower_upper_trim_insert;
  SRunner *sr_strcspn, *sr_strstr, *sr_strtok, *sr_memcmp_strncmp_strerror,
      *sr_memcpy_memset_strncpy, *sr_strlen_strncat_strpbrk, *sr_memchr,
      *sr_strchr, *sr_strrchr, *sr_sprintf, *sr_lower_upper_trim_insert;

  s_memchr = memchr_test();
  sr_memchr = srunner_create(s_memchr);
  srunner_run_all(sr_memchr, CK_NORMAL);
  no_failed_memchr = srunner_ntests_failed(sr_memchr);
  srunner_free(sr_memchr);

  s_strchr = strchr_test();
  sr_strchr = srunner_create(s_strchr);
  srunner_run_all(sr_strchr, CK_NORMAL);
  no_failed_strchr = srunner_ntests_failed(sr_strchr);
  srunner_free(sr_strchr);

  s_strrchr = strrchr_test();
  sr_strrchr = srunner_create(s_strrchr);
  srunner_run_all(sr_strrchr, CK_NORMAL);
  no_failed_strrchr = srunner_ntests_failed(sr_strrchr);
  srunner_free(sr_strrchr);

  s_strcspn = strcspn_test();
  sr_strcspn = srunner_create(s_strcspn);
  srunner_run_all(sr_strcspn, CK_NORMAL);
  number_failed_strcspn = srunner_ntests_failed(sr_strcspn);
  srunner_free(sr_strcspn);

  s_strstr = strstr_test();
  sr_strstr = srunner_create(s_strstr);
  srunner_run_all(sr_strstr, CK_NORMAL);
  number_failed_strstr = srunner_ntests_failed(sr_strstr);
  srunner_free(sr_strstr);

  s_strtok = strtok_test();
  sr_strtok = srunner_create(s_strtok);
  srunner_run_all(sr_strtok, CK_NORMAL);
  number_failed_strtok = srunner_ntests_failed(sr_strtok);
  srunner_free(sr_strtok);

  s_memcpy_memset_strncpy = suite_memcpy_memset_strncpy();
  sr_memcpy_memset_strncpy = srunner_create(s_memcpy_memset_strncpy);
  srunner_run_all(sr_memcpy_memset_strncpy, CK_NORMAL);
  no_failed_memcpy_memset_strncpy =
      srunner_ntests_failed(sr_memcpy_memset_strncpy);
  srunner_free(sr_memcpy_memset_strncpy);

  s_memcmp_strncmp_strerror = suite_memcmp_strncmp_strerror();
  sr_memcmp_strncmp_strerror = srunner_create(s_memcmp_strncmp_strerror);
  srunner_run_all(sr_memcmp_strncmp_strerror, CK_NORMAL);
  number_failed_memcmp_strncmp_strerror =
      srunner_ntests_failed(sr_memcmp_strncmp_strerror);
  srunner_free(sr_memcmp_strncmp_strerror);

  s_strlen_strncat_strpbrk = suite_strlen_strncat_strpbrk();
  sr_strlen_strncat_strpbrk = srunner_create(s_strlen_strncat_strpbrk);
  srunner_run_all(sr_strlen_strncat_strpbrk, CK_NORMAL);
  no_failed_strlen_strncat_strpbrk =
      srunner_ntests_failed(sr_strlen_strncat_strpbrk);
  srunner_free(sr_strlen_strncat_strpbrk);

  s_sprintf = suite_sprintf();
  sr_sprintf = srunner_create(s_sprintf);
  srunner_run_all(sr_sprintf, CK_NORMAL);
  no_failed_sprintf = srunner_ntests_failed(sr_sprintf);
  srunner_free(sr_sprintf);

  s_lower_upper_trim_insert = suite_lower_upper_trim_insert();
  sr_lower_upper_trim_insert = srunner_create(s_lower_upper_trim_insert);
  srunner_run_all(sr_lower_upper_trim_insert, CK_NORMAL);
  no_failed_lower_upper_trim_insert =
      srunner_ntests_failed(sr_lower_upper_trim_insert);
  srunner_free(sr_lower_upper_trim_insert);

  int number_failed =
      number_failed_strcspn + number_failed_strstr + number_failed_strtok +
      number_failed_memcmp_strncmp_strerror + no_failed_memcpy_memset_strncpy +
      no_failed_strlen_strncat_strpbrk + no_failed_memchr + no_failed_strchr +
      no_failed_strrchr + no_failed_sprintf + no_failed_lower_upper_trim_insert;

  return (number_failed == 0) ? 0 : 1;
}
