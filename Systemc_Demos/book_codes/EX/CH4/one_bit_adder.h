// Copyright 2003 Star Galaxy Publishing
// File: one_bit_adder.h

void one_bit_adder (bool a, bool b, bool cin, bool &sum, bool &cout);

// File: one_bit_adder.cpp

void one_bit_adder (bool a, bool b, bool cin, bool &sum, bool &cout) {
  sum = a ^ b ^ cin;
  cout = (a & b) | (a & cin) | (b & cin);
}

