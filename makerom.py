code = bytearray([
    0x3e, 0x0f,         # LD A, 0FH
    0xd3, 0x02,         # OUT (02H), A

    0x3e, 0x55,         # LD A, 55H
    0xd3, 0x00,         # OUT (00H), A

    0x3e, 0xaa,         # LD A, AAH
    0xd3, 0x00,         # OUT (00H), A

    0xc3, 0x04, 0x00    # JP (0000H)
])

rom = code + bytearray([0x00] * (32768 - len(code)))

with open("rom.bin", "wb") as f:
    f.write(rom)