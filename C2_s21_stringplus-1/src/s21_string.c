#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  // Вычисляет длину начального сегмента str1,
  // который полностью состоит из символов, не входящих в str2
  s21_size_t ans = 0;
  int flag = 1;
  while (ans < s21_strlen(str1) && flag) {
    for (s21_size_t i = 0; i < s21_strlen(str2) && flag; i++) {
      if (str2[i] == str1[ans]) flag = 0;
    }
    if (flag) ans++;
  }
  return ans;
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *phaystack = haystack;
  int flag = 1;
  if (haystack == s21_NULL || needle == s21_NULL) flag = 0;
  const char *ans = s21_NULL;

  while (flag && *phaystack) {
    const char *pos_haystack = phaystack;
    const char *pneedle = needle;
    while (*pos_haystack && *pos_haystack == *pneedle) {
      pos_haystack++;
      pneedle++;
    }
    if (*pneedle == '\0') {
      ans = phaystack;
      flag = 0;
    }
    phaystack++;
  }

  if (flag && *needle == '\0') {
    ans = (char *)haystack;
  }

  return (haystack == s21_NULL || needle == s21_NULL) ? s21_NULL : (char *)ans;
}

char *s21_strtok(char *str, const char *delim) {
  static char *static_buff = s21_NULL;

  int flag = 1;
  if (str) {
    static_buff = str;
  }
  char *p_start = static_buff;
  if (static_buff == s21_NULL || *static_buff == '\0') {
    flag = 0;
  } else {
    // пропускаем разделители в самом начале
    while (*p_start && s21_strchr(delim, *p_start)) {
      p_start++;
    }

    if (*p_start == '\0') {
      static_buff = s21_NULL;
      flag = 0;
    } else {
      char *p_end = p_start;
      while (*p_end && !s21_strchr(delim, *p_end)) {
        p_end++;
      }
      if (*p_end) {
        *p_end = '\0';
        static_buff = p_end + 1;
      } else {
        static_buff = s21_NULL;
      }
    }
  }
  return (flag == 1 ? p_start : s21_NULL);
}

int s21_memcmp(char *s1, char *s2, s21_size_t n) {
  char diff = 0;
  while (n > 0 && diff == 0) {
    n--;
    if (*s1 != *s2) {
      diff = *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return diff;
}

int s21_strncmp(char *s1, char *s2, s21_size_t n) {
  int diff = 0;
  for (s21_size_t i = 0; diff == 0 && i < n; i++) {
    if (s1[i] != s2[i]) {
      diff = s1[i] - s2[i];
    }
  }
  return diff;
}

char *s21_strerror(int errnum) {
  static char unknown_error[100];
  char *error_messages[] = ERROR_MESSAGES;
  char *errmes;
  if (errnum >= 0 && errnum <= 133) {
    errmes = error_messages[errnum];
  } else {
    s21_sprintf(unknown_error, "Unknown error %d", errnum);
    errmes = unknown_error;
  }

  return errmes;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  char *result = s21_NULL;
  while (n-- > 0) {
    if (*ptr == (unsigned char)c) result = (char *)ptr;
    ptr++;
  }
  return result;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  int found = 0;
  while (*str != '\0' && !found) {
    if (*str == (unsigned char)c) {
      result = (char *)str;
      found = 1;
    }
    str++;
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  const unsigned char search = (unsigned char)c;
  const char *result = s21_NULL;
  while (*str != '\0') {
    if (*str == search) result = str;
    str++;
  }
  return (char *)result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *((char *)dest + i) = *((char *)src + i);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *((unsigned char *)str + i) = (unsigned char)c;
  }
  return str;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t n1 = 0;
  while (n1 < n) {
    if (*src == '\0')
      dest[n1++] = '\0';
    else
      dest[n1++] = *src++;
  }
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  unsigned char length = 0;
  while (*str++) length++;
  return length;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, j = 0;
  // while (dest[i]) i++;
  i = s21_strlen(dest);
  while (src[j] != '\0' && j < n) {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + j] = '\0';
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int i = 0, flag = 0;
  while (str1[i] != '\0' && !flag) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        result = (char *)&str1[i];
        flag = 1;
      }
    }
    i++;
  }
  return result;
}

// s21_sprintf
// |
// |
// V

s21_size_t s21_wstrlen(const wchar_t *str) {
  unsigned char length = 0;
  while (*str++) length++;
  return length;
}

int s21_sprintf(char *str, const char *format, ...) {
  modifier format_mod = {};
  int count_smbls = 0;
  va_list str_parametr;
  va_start(str_parametr, format);
  for (s21_size_t i = 0; i < s21_strlen(format); i++) {
    if (*(format + i) != '%') {
      str[count_smbls] = *(format + i);
      count_smbls++;
    } else {
      i++;
      while (s21_flags(format, &i, &format_mod));
      s21_specifier_parser(str, format, str_parametr, &i, &count_smbls,
                           &format_mod);
    }
  }
  va_end(str_parametr);
  str[count_smbls] = '\0';
  return count_smbls;
}

int s21_flags(const char *format, s21_size_t *i, modifier *format_mod) {
  int flag = 1;
  char smbl = *(format + *i);
  if (smbl == '+') {
    format_mod->plus = '+';
  } else if (smbl == ' ')
    format_mod->space = 1;
  else if (smbl == '-') {
    format_mod->minus = 1;
  } else if (s21_strchr("1234567890", smbl))
    format_mod->width = s21_take_width(format, i);
  else if (smbl == 'h') {
    format_mod->h = 1;
  } else if (smbl == 'l') {
    format_mod->l = 1;
  } else if (smbl == '.') {
    (*i)++;
    int len = s21_take_width(format, i);
    format_mod->point = len;
    if (len == 0) format_mod->point = -1;
  } else
    flag = 0;
  if (flag) {
    *i = *i + 1;
  }

  return flag;
}

int s21_take_width(const char *format, s21_size_t *i) {
  int width = 0;
  int zero_size = 0;
  while (s21_strchr("1234567890", *(format + *i))) {
    zero_size++;
    width = width * 10 + (*(format + *i) - '0');
    (*i)++;
  }
  if (width > 0 || zero_size || s21_strchr("scdfhlu", *(format + *i))) (*i)--;
  return width;
}

void s21_specifier_parser(char *str, const char *format, va_list str_parametr,
                          s21_size_t *i, int *count_smbls,
                          modifier *format_mod) {
  int count_pointer = -1;
  int start;
  wchar_t c;
  wchar_t *s;
  char *s1;
  int len;
  long int d;
  double f;
  unsigned long u;
  char x = *(format + *i);
  switch (x) {
    case 'c':
      c = s21_c_value(format_mod, str_parametr);
      start = *count_smbls;
      s21_width(str, count_smbls, format_mod->width - 1);
      str[*count_smbls] = c;
      (*count_smbls)++;
      if (format_mod->minus) s21_reverse(str, start, *count_smbls - 1);
      break;
    case 's':
      s = s21_NULL;
      s1 = s21_NULL;
      len = s21_s_value(format_mod, str_parametr, &s, &s1);
      s21_s_per_str(format_mod, str, len, s, s1, count_smbls);
      break;
    case 'd':
      d = s21_d_value(format_mod, str_parametr);
      s21_d_flag(d, str, count_smbls, &count_pointer, format_mod);
      break;
    case 'f':
      f = va_arg(str_parametr, double);
      s21_f_flag(f, str, count_smbls, &count_pointer, format_mod);
      break;
    case 'u':
      u = s21_u_value(format_mod, str_parametr);
      s21_num_per_str(u, str, count_smbls, &count_pointer, *format_mod);
      break;
  };
  s21_freee_struct(format_mod);
}

void s21_width(char *str, int *count_smbls, int width) {
  while (width > 0) {
    str[(*count_smbls)] = ' ';
    (*count_smbls)++;
    width--;
  }
}

wchar_t s21_c_value(modifier *format_mod, va_list str_parametr) {
  wchar_t c;
  if (!format_mod->l) {
    c = va_arg(str_parametr, int);
  } else {
    c = va_arg(str_parametr, wchar_t);
  }
  return c;
}

int s21_s_value(modifier *format_mod, va_list str_parametr, wchar_t **s,
                char **s1) {
  int len;
  if (format_mod->l) {
    *s = va_arg(str_parametr, wchar_t *);
    if (format_mod->point)
      len = (format_mod->point < (int)s21_wstrlen(*s)) ? format_mod->point
                                                       : ((int)s21_wstrlen(*s));
    else
      len = (int)s21_wstrlen(*s);
  } else {
    *s1 = va_arg(str_parametr, char *);
    if (format_mod->point)
      len = (format_mod->point < (int)s21_strlen(*s1)) ? format_mod->point
                                                       : ((int)s21_strlen(*s1));
    else
      len = (int)s21_strlen(*s1);
  }
  return len;
}

void s21_s_per_str(modifier *format_mod, char *str, int len, wchar_t *s,
                   char *s1, int *count_smbls) {
  if (format_mod->point == -1) len++;
  if (!format_mod->minus) s21_width(str, count_smbls, format_mod->width - len);
  if (format_mod->l) {
    for (int i = 0; i < len; i++) {
      str[*count_smbls] = s[i];
      (*count_smbls)++;
    }
  } else {
    for (int i = 0; i < len; i++) {
      str[*count_smbls] = s1[i];
      (*count_smbls)++;
    }
  }
  if (format_mod->minus) s21_width(str, count_smbls, format_mod->width - len);
}

long int s21_d_value(modifier *format_mod, va_list str_parametr) {
  long int d;
  if (!format_mod->l) {
    d = va_arg(str_parametr, int);
  } else {
    d = va_arg(str_parametr, long int);
  }
  return d;
}

void s21_d_flag(long int d, char *str, int *count_smbls, int *count_pointer,
                modifier *format_mod) {
  if (d < 0) {
    format_mod->plus = '-';
    d *= -1;
  }
  s21_num_per_str(d, str, count_smbls, count_pointer, *format_mod);
}

void s21_f_flag(double f, char *str, int *count_smbls, int *count_pointer,
                modifier *format_mod) {
  format_mod->accuracy = 6;
  if (format_mod->point) format_mod->accuracy = format_mod->point;
  if (format_mod->point == -1)
    *count_pointer = -1;
  else
    *count_pointer = 0;
  format_mod->point = 0;
  if (f < 0) {
    format_mod->plus = '-';
    f *= -1;
  }
  int count = 0;
  long long f1 = (long long)(f);
  long double part = f - (long long)f;
  if (format_mod->accuracy <= 0 && (int)(part * 10) > 4) f1++;
  while (count < format_mod->accuracy) {
    part *= 10;
    format_mod->part[count] = (int)part + '0';
    count++;
    part -= (int)part;
  }
  if ((int)(part * 10) > 4 && format_mod->accuracy > 0) {
    count--;
    format_mod->part[count] = (format_mod->part[count] - '0' + 1) + '0';
  }
  (*count_pointer) = s21_len_num(f1);
  s21_reverse(format_mod->part, 0, format_mod->accuracy - 1);
  s21_num_per_str(f1, str, count_smbls, count_pointer, *format_mod);
}

unsigned long s21_u_value(modifier *format_mod, va_list str_parametr) {
  unsigned long u;
  if (format_mod->h && !format_mod->l) {
    u = va_arg(str_parametr, unsigned);
  } else {
    u = va_arg(str_parametr, unsigned long);
  }
  return u;
}

void s21_num_per_str(unsigned long num, char *str, int *count_smbls,
                     int *count_pointer, modifier format_mod) {
  int diff = 0;
  int diff_tochnost = 0;
  int start;
  int len = s21_len_num(num);
  if (num == 0 && format_mod.point == -1) len--;
  if (format_mod.width) diff = format_mod.width - len - format_mod.accuracy;
  if (*count_pointer > -1) diff--;
  if (format_mod.plus) diff--;
  if (format_mod.point > 0) diff_tochnost = format_mod.point - len;
  diff *= (len <= format_mod.width);
  diff_tochnost *= (0 <= diff_tochnost);
  if (diff - diff_tochnost > 0 && !(format_mod.plus) && format_mod.space)
    diff--;
  if (format_mod.minus) s21_sign(str, count_smbls, format_mod);
  if (format_mod.space && !(format_mod.plus)) {
    (str[*count_smbls]) = ' ';
    (*count_smbls)++;
  }
  if (format_mod.minus) start = *count_smbls;
  s21_width(str, count_smbls, diff - diff_tochnost);
  if (!format_mod.minus) {
    s21_sign(str, count_smbls, format_mod);
    s21_accuracy(str, count_smbls, diff_tochnost);
    start = *count_smbls;
  }
  s21_input_num(num, str, count_smbls, count_pointer, format_mod,
                diff_tochnost);
  s21_reverse(str, start, *count_smbls - 1);
}

void s21_input_num(unsigned long num, char *str, int *count_smbls,
                   int *count_pointer, modifier format_mod, int diff_tochnost) {
  for (int i = 0; i < (format_mod.accuracy); i++) {
    str[*count_smbls] = format_mod.part[i];
    if (i + 1 == format_mod.accuracy) {
      (*count_smbls)++;
      str[*count_smbls] = '.';
    }
    (*count_smbls)++;
  }
  if (num == 0 && format_mod.point != -1) {
    str[*count_smbls] = '0';
    (*count_smbls)++;
    (*count_pointer)--;
  }
  while (num > 0) {
    str[*count_smbls] = '0' + (num % 10);
    (*count_smbls)++;
    (*count_pointer)--;
    num /= 10;
  }
  if (format_mod.minus) s21_accuracy(str, count_smbls, diff_tochnost);
}

void s21_sign(char *str, int *count_smbls, modifier format_mod) {
  if (format_mod.plus) {
    (str[*count_smbls]) = format_mod.plus;
    (*count_smbls)++;
  }
}

int s21_len_num(unsigned long num) {
  int len = 0;
  if (num == 0) len++;
  while (num > 0) {
    len++;
    num /= 10;
  }
  return len;
}

void s21_accuracy(char *str, int *count_smbls, int accuracy) {
  while (accuracy > 0) {
    str[(*count_smbls)] = '0';
    (*count_smbls)++;
    accuracy--;
  }
}

void s21_reverse(char *str, int start, int end) {
  while (start < end) {
    char part = str[start];
    str[start++] = str[end];
    str[end--] = part;
  }
}

void s21_freee_struct(modifier *format_mod) {
  format_mod->plus = 0;
  format_mod->minus = 0;
  format_mod->space = 0;
  format_mod->width = 0;
  format_mod->h = 0;
  format_mod->l = 0;
  format_mod->point = 0;
  format_mod->accuracy = 0;
  s21_memset(format_mod->part, 0, s21_strlen(format_mod->part));
}

void *s21_to_upper(const char *str) {
  if (str == NULL || *str == '\0') return NULL;

  s21_size_t lenght = s21_strlen(str);

  char *result = (char *)malloc(lenght + 1);

  for (s21_size_t i = 0; i < lenght; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      result[i] = str[i] - 32;
    else
      result[i] = str[i];
  }
  result[lenght] = '\0';

  return result;
}

void *s21_to_lower(const char *str) {
  if (str == NULL || *str == '\0') return NULL;

  s21_size_t lenght = s21_strlen(str);

  char *result = (char *)malloc(lenght + 1);

  for (s21_size_t i = 0; i < lenght; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      result[i] = str[i] + 32;
    else
      result[i] = str[i];
  }
  result[lenght] = '\0';
  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str || start_index > s21_strlen(src)) return NULL;

  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  s21_size_t full_len = len_src + len_str;

  char *result = (char *)malloc(full_len + 1);

  s21_memcpy(result, src, start_index);

  result[start_index] = '\0';

  s21_strncat(result, str, s21_strlen(str));

  s21_strncat(result, src + start_index, s21_strlen(str));

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) return NULL;

  s21_size_t len = s21_strlen(src);

  const char *start = src;
  while (*start && s21_strchr(trim_chars, *start)) ++start;

  const char *end = src + len - 1;
  while (end > start && s21_strchr(trim_chars, *end)) --end;

  s21_size_t result_len = end - start + 1;
  char *result = malloc(result_len + 1);

  s21_memcpy(result, start, result_len);
  result[result_len] = '\0';

  return result;
}
