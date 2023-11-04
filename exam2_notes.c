// https://www.w3schools.com/c/c_structs.php

/* Topics to look over******************************************************************* */
/*
1. Get really familiar with pointers.
*/
/* H******************************************************************* */

/* Program homework notes******************************************************************* */
/* Audio Files********************************************/
/*
WAV format- must be stored in file extensions of *.wav. 
- WAV format is a subset of Microsoft's RIFF specification for storing 
multimedia files.
- RIFF files- starts with a file header followed by a sequence of data chunks.
- WAV files are RIFF files with 3 chunks:
    1. indicates the file is a RIFF WAV file.
    2. Header of a "fmt" chunk; specifies the data format, like stereo. 
    3. "Data" chunk containing the actual sample data stored in the format
    specified in the "fmt" chunk.

    Ex. A WAV PCM file is stored in an uncompressed format; PCM means
    pulse-code-modulation; in this case it means uncompressed mode.
*/

/* Written homework notes******************************************************************* */
// Section 7.3*******************************************
/*
Pointers:
Ex. 
int numbs[2];
int* ptr = numbs;
numbs[0] = 10;
printf("%d\n", ++*ptr); --> outputs 11


Functions: 
*/

// Section 9.1*******************************************
/*
Diff btwn mode r and r+, w and w+, r+b (read-write-binary)

Functions: 
stdin-

gets- reads characters from the standard input until it encounters a newline
fputs- writes a character string to the file referenced by its second argument
*/
