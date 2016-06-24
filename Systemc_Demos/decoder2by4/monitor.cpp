#include "monitor.h"

void monitor::prc_monitor()
{
        cout << "At time " << sc_time_stamp() << ": ";
        cout << m_enable << m_select << "is :";
        cout << m_z << endl;
}
