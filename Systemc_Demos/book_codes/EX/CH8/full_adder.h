// Copyright 2003 Star Galaxy Publishing
// File: full_adder.h

#include "half_adder.h"

SC_MODULE (full_adder) {
  sc_in<bool> a, b, carry_in;
  sc_out<bool> sum, carry_out;

  sc_signal<bool> c1, s1, c2;

  void or_process ();

  half_adder *ha1_ptr, *ha2_ptr;

  SC_CTOR (full_adder) {
    ha1_ptr = new half_adder ("ha1");
    // Named association:
    ha1_ptr->a (a);
    ha1_ptr->b (b);
    ha1_ptr->sum (s1);
    ha1_ptr->carry (c1);

    ha2_ptr = new half_adder ("ha2");
    // Positional association: 
    (*ha2_ptr) (s1, carry_in, sum, c2);

    SC_METHOD (or_process);
    sensitive << c1 << c2;
  }
};
