#include "driver.h"

void driver::prc_driver()
{
        sc_uint<2> pattern;
        bool enable;

        pattern = 0;
        enable = 1;
        
        while(1) {
                d_enable = enable;
                d_select = pattern;
                wait(5, SC_NS);
                pattern ++ ;
        }
}
