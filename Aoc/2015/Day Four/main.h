#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <strings.h>
#include "md5.h"

void print_hash(uint8_t* p);
int to_hex(char* dest, size_t dest_len, const uint8_t* values, size_t val_len);