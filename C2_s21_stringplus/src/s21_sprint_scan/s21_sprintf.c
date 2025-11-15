#include <locale.h>

#include "s21_sprint_scan.h"
#include "sprintf_handlers/s21_sprintf_handlers.h"

static int sprintf_process_specifier(char *buffer, va_list *args,
                                     struct formatSpecifiers *spec, int if_n);

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int total_written = 0;
  while (*format) {
    if (*format == '%') {
      format++;
      struct formatSpecifiers spec = {0};
      s21_set_specifier(&format, &spec, &args);
      total_written += sprintf_process_specifier(buffer + total_written, &args,
                                                 &spec, total_written);
    } else {
      buffer[total_written++] = *format;  // Копируем символы в буфер
    }
    format++;
  }
  buffer[total_written] = '\0';
  va_end(args);
  return total_written;  // Возвращаем общее количество записанных символов
}

static int sprintf_process_specifier(char *buffer, va_list *args,
                                     struct formatSpecifiers *spec, int if_n) {
  int total_written = 0;
  long double floatArgument = 0;  // общee для f, g, G, e, E
  long long int intArgument = 0;  // общее для c d i o u x X cdiouxX
  if (s21_strchr("fgGeE", spec->specifier)) {
    floatArgument = spec->length == 'L' ? va_arg(*args, long double)
                                        : va_arg(*args, double);
  } else if (s21_strchr("cdisouxXp", spec->specifier)) {
    intArgument = va_arg(*args, long long int);
  }
  switch (spec->specifier) {
    case 'c':
      if (spec->length == 'l') {
        total_written += s21_handle_wchar(buffer, (wchar_t)intArgument, spec);
      } else {
        total_written += s21_handle_char(buffer, (char)intArgument, spec);
      }
      break;
    case 'd':
    case 'i': {
      if (spec->length == 'l') {
        total_written +=
            s21_handle_integer(buffer, (long int)intArgument, spec);
      } else if (spec->length == 'h') {
        total_written += s21_handle_integer(buffer, (short)intArgument, spec);
      } else {
        total_written += s21_handle_integer(buffer, (int)intArgument, spec);
      }
      break;
    }
    case 's':
      total_written += s21_handle_string(buffer, (char *)intArgument, spec);
      break;
    case 'f':
      total_written += s21_handle_float(buffer, floatArgument, spec, true);
      break;
    case 'e':
    case 'E':
      total_written +=
          s21_handle_scientific(buffer, (double)floatArgument, spec, true);
      break;
    case 'g':
    case 'G':
      total_written += s21_handle_g(buffer, floatArgument, spec);
      break;
    case 'o': {
      total_written +=
          s21_handle_octal(buffer, (unsigned long int)intArgument, spec);
      break;
    }
    case 'u': {
      if (spec->length == 'l') {
        total_written +=
            s21_handle_unsigned(buffer, (unsigned long int)intArgument, spec);
      } else if (spec->length == 'h') {
        total_written +=
            s21_handle_unsigned(buffer, (unsigned short)intArgument, spec);
      } else {
        total_written +=
            s21_handle_unsigned(buffer, (unsigned int)intArgument, spec);
      }
      break;
    }
    case 'x': {
      total_written +=
          s21_handle_hexadecimal(buffer, (unsigned long int)intArgument, spec,
                                 0);  // Небольшие буквы
      break;
    }
    case 'X': {
      total_written +=
          s21_handle_hexadecimal(buffer, (unsigned long int)intArgument, spec,
                                 1);  // Заглавные буквы
      break;
    }
    case 'p': {
      total_written += s21_handle_pointer(buffer, (void *)intArgument, spec);
      break;
    }
    case 'n': {
      int count = total_written + if_n;  // Количество записанных символов
      int *ptr = va_arg(*args, int *);
      if (ptr) {
        *ptr = count;  // Записываем количество в переменную
      }
      break;
    }
    case '%':
      buffer[total_written++] = '%';  // Выводим символ '%'
      break;
    default:
      buffer[total_written++] = '?';  // Неизвестный спецификатор
      break;
  }
  return total_written;
}