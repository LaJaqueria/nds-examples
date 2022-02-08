
#include <nds.h>
#include <stdio.h>

#include "background.h"

int main(void)
{
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_0_2D);
    consoleDemoInit();

    PrintConsole bottomScreen;
    consoleInit(&bottomScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);
    vramSetBankA(VRAM_A_MAIN_BG);

    // set up our bitmap background
    bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

    decompress(backgroundBitmap, BG_GFX, LZ77Vram);

    consoleSelect(&bottomScreen);
    iprintf("\n\n\t\tJaqueria Rules\n");
    iprintf("\tClub de desarrollo retro\n");
    iprintf("\t\t256 color bitmap demo");
    while (true)
    {
        swiWaitForVBlank();
        scanKeys();
        if (keysDown() & KEY_START)
            break;
    }

    return 0;
}