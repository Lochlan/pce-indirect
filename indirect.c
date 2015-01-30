#include "huc.h"

#asm
;// pointer must be in zero page
    .zp
    data_pointer: .ds 2

;// our data
    .data
    foo: .dw $1234
    bar: .dw foo

    .code
#endasm

int output_value;

main() {
    #asm
    ;// map our data's bank
        map bar
    ;// load address into pointer
        lda bar
        sta <data_pointer
        lda bar+1
        sta <data_pointer+1
    ;// dereference pointer
        lda [data_pointer]
        sta _output_value
        inc data_pointer
        lda [data_pointer]
        sta _output_value+1
    #endasm

    put_hex(output_value, 4, 2, 2);
}
