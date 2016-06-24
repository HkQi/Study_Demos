#include "driver.h"
#include "monitor.h"
#include "decoder.h"

int sc_main(int argc, char *argv[])
{
        sc_signal<bool> t_enable;
        sc_signal<sc_uint<2> > t_sel;
        sc_signal<sc_uint<4> > t_z;

        decoder d("decoder");
        d.enable(t_enable);
        d.select(t_sel);
        d.z(t_z);

        driver dr("driver");
        dr.d_enable(t_enable);
        dr.d_select(t_sel);

        monitor mo("monitor");
        mo.m_enable(t_enable);
        mo.m_select(t_sel);
        mo.m_z(t_z);

        sc_start(100, SC_NS);

        return (0);
}
