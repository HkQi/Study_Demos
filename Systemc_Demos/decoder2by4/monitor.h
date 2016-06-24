#ifndef __DECODER_MONITOR_H__
#define __DECODER_MONITOR_H__

#include <systemc.h>

SC_MODULE(monitor) {
        sc_in<bool> m_enable;
        sc_in<sc_uint<2> > m_select;
        sc_in<sc_uint<4> > m_z;

        void prc_monitor();

        SC_CTOR(monitor) {
                SC_METHOD(prc_monitor);
                sensitive << m_z;
        }
};

#endif // __DECODER_MONITOR_H__
