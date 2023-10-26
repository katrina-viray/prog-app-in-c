#include <stdio.h>

int decode(char c)
{
    if((c >= 33) && (c <= 71))
        return c;
    else
        return -1;
}

int main() {

}
