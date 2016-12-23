#ifndef CONSOLE_DRAW3_
#define CONSOLE_DRAW3_
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 200
#ifdef check
#define swap 0x4000
#else
#define swap 0x0000
#endif // check
#define mod 0x000F
extern void drawChar(int ch, int x, int y, int bgcolor, int fgcolor);
extern void drawString(char *p, int x, int y, int bg_color, int fg_color);
extern void drawCmdWindow();
extern void clearScreen();
extern void saveScreen();
extern void restoreScreen();
#endif
/*
drawChar()  �̫��ӰѼƤ��O�O�r���I���M�e�����C��
�i�H�ѦҤU�����C��ȹ�Ӫ��ӳ]�w�A�Q�n���C��

   0: ��     1: �t��   2: �t��   3: �t�C
   4: �t��   5: �t��   6: �t��   7: �L��
   8: �t��   9: �G��  10: �G��  11: �G�C
  12: �G��  13: �G��  14: �G��  15: ��
*/