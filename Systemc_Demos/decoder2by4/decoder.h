#ifndef __DECODER_H__
#define __DECODER_H__

#include <systemc.h>

SC_MODULE(decoder) {
        sc_in<bool> enable;
        sc_in<sc_uint<2> > select;
        sc_out<sc_uint<4> > z;
        
        void prc_decoder();
        
        SC_CTOR(decoder) {
                SC_METHOD(prc_decoder);
                sensitive << enable;
                sensitive << select;
        }
};


#endif // __DECODER_H__
