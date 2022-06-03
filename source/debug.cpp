#include "debug.hpp"

#include <3ds.h>
#include <cstdio>
#include <cstdarg>

void CitraPrint (std::string_view str) {
   svcOutputDebugString(str.data(), str.length());
}

void DebugPrint(const char *format, ...) {
   char buffer[0x200];
   va_list arg;
   va_start(arg, format);
   const int written = vsnprintf(buffer, sizeof(buffer), format, arg);
   va_end(arg);
   if (written >=0)
   svcOutputDebugString(buffer, sizeof(buffer));
}