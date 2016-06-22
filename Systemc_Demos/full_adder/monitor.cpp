#include "monitor.h"

void monitor::prc_monitor() {
	cout << "At Time " << sc_time_stamp() << "::";
	cout << " (a, b, carry_in):";
	cout << m_a << m_b << m_cin;
	cout << " (sum, carry_out):";
	cout << m_sum << m_cout;
	cout << endl;
}
