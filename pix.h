const prog_uchar deg[] = {
  0x06, 0x9, 0x9, 0x6, 0x00, 0x00, 0x00, 0x00
};

const prog_uchar d1[] = { //sun
  0x00, 0x80,
  0x08, 0x88,
  0x04, 0x10,
  0x21, 0xC2,
  
  0x12, 0x24,
  0x04, 0x10,
  0x08, 0x08,
  0x68, 0x0B,

  0x08, 0x08,
  0x04, 0x10,
  0x12, 0x24,
  0x21, 0xC2,
  
  0x04, 0x10,
  0x08, 0x88,
  0x00, 0x80,
  0x00, 0x00
};

const prog_uchar d2[] = { //suncloud
  0x00, 0x10,
  0x00, 0x92,
  0x0E, 0x44,
  0x11, 0x00,
  
  0x20, 0xB3,
  0x60, 0xC8,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00
};

const prog_uchar d3[] = { //cloud
  0x00, 0x00,
  0x00, 0x00,
  0x0E, 0x00,
  0x11, 0x00,
  
  0x20, 0xB0,
  0x60, 0xC8,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00
};

const prog_uchar d4[] = { //darkcloud
  0x00, 0x00,
  0x00, 0x60,
  0x0E, 0xF6,
  0x11, 0xFF,
  
  0x20, 0xFF,
  0x60, 0xCE,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00
};

const prog_uchar d9[] = { //raincloud
  0x00, 0x00,
  0x00, 0x60,
  0x0E, 0xF6,
  0x11, 0xFF,
  
  0x20, 0xFF,
  0x60, 0xCE,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x10, 0x00,
  0x20, 0x20,
  
  0x44, 0x40,
  0x08, 0x80,
  0x10, 0x00,
  0x00, 0x00
};

const prog_uchar d10[] = { //sunraincloud
  0x00, 0x10,
  0x00, 0x92,
  0x0E, 0x44,
  0x11, 0x00,
  
  0x20, 0xB3,
  0x60, 0xC8,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x10, 0x00,
  0x20, 0x20,
  
  0x44, 0x40,
  0x08, 0x80,
  0x10, 0x00,
  0x00, 0x00
};

const prog_uchar d11[] = { //thundercloud
  0x00, 0x00,
  0x00, 0x60,
  0x0E, 0xF6,
  0x11, 0xFF,
  
  0x20, 0xFF,
  0x60, 0xCE,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x02, 0x00,
  0x04, 0x00,
  
  0x08, 0x00,
  0x04, 0x00,
  0x02, 0x00,
  0x04, 0x00
};

const prog_uchar d13[] = { //snowcloud
  0x00, 0x00,
  0x00, 0x60,
  0x0E, 0xF6,
  0x11, 0xFF,
  
  0x20, 0xFF,
  0x60, 0xCE,
  0x80, 0x04,
  0x80, 0x04,
  
  0x7F, 0xF8,
  0x00, 0x00,
  0x14, 0x00,
  0x08, 0x14,
  
  0x14, 0x08,
  0x01, 0x54,
  0x00, 0x80,
  0x01, 0x40
};

const prog_uchar d50[] = { //fog
  0x00, 0x00,
  0x00, 0x00,
  0x06, 0x06,
  0x19, 0x98,
  
  0x60, 0x60,
  0x06, 0x06,
  0x19, 0x98,
  0x60, 0x60,
  
  0x06, 0x06,
  0x19, 0x98,
  0x60, 0x60,
  0x06, 0x06,
  
  0x19, 0x98,
  0x60, 0x60,
  0x00, 0x00,
  0x00, 0x00,
};

const prog_uchar d99[] = { //cross
  0x80, 0x01,
  0x40, 0x02,
  0x20, 0x04,
  0x10, 0x08,
  
  0x08, 0x10,
  0x04, 0x20,
  0x02, 0x40,
  0x01, 0x80,
  
  0x01, 0x80,
  0x02, 0x40,
  0x04, 0x20,
  0x08, 0x10,
  
  0x10, 0x08,
  0x20, 0x04,
  0x40, 0x02,
  0x80, 0x01,
};

const prog_uchar* icons[] = {d1, d2, d3, d4, d9, d10, d11, d13, d50, d99};

const char* wdays[] = {"--", "So", "Mo", "Di", "Mi", "Do", "Fr", "Sa"};
