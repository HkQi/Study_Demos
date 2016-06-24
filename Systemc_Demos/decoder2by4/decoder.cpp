#include "decoder.h"

void decoder::prc_decoder()
{
        if (enable) {
                switch (select.read()) {
                case 0: z = 0xE; break; // 15
                case 1: z = 0xD; break; // 14
                case 2: z = 0xB; break; // 12
                case 3: z = 0x7; break; // 7
                }
        } else {
                z = 0xF;
        }
}
