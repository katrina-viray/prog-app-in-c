/* Range of possible integer values for bitfield structures */
// e.g. 0<=i2<=15 is the range.
struct mystruct{
int  i1:3;
 unsigned int i2:4;
};

/* structure variables wherein one of the fields is 
another structure variable (as in the book). */

/* How structure variable are stored in memory 
(can be un-used memory addresses between two fields)
 Pointer syntax with a pointer to a structure variable. */

/* Enumerated types. The variables are actually 4-byte 
variables. Know how the keywords in the declaration of
 an enumerated variable are assigned int values. */

/* In a question on the final, I might provide a
 structure variable that is the complete WAVE file header,
  and ask you to use the provided structure variable and 
  complete the program to do something with the WAVE file.*/