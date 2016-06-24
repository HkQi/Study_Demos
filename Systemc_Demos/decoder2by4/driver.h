#ifndef __DECODER_DRIVER_H__
#define __DECODER_DRIVER_H__

#include "systemc.h"

SC_MODULE(driver) {
        sc_out<bool> d_enable;
        sc_out<sc_uint<2> > d_select;

        void prc_driver();

        SC_CTOR(driver) {
                SC_THREAD(prc_driver)
        }
};

#endif // __DECODER_DRIVER_H__
