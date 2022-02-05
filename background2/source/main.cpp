
#include <nds.h>
#include <stdio.h>

#include "background.h"
#include "fondo2.h"

int main(void){
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);
   	consoleDemoInit();


    vramSetBankA(VRAM_A_MAIN_BG);

	

	// set up our bitmap background
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0,0);
	
	decompress(backgroundBitmap, BG_GFX,  LZ77Vram);

    int bgsub=bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 5,0); 

    dmaCopy(fondo2Bitmap,bgGetGfxPtr(bgsub),256*256);
    dmaCopy(fondo2Pal,BG_PALETTE_SUB,256*2);
    
    while(true){
        swiWaitForVBlank();
		scanKeys();
		if (keysDown()&KEY_START) break;
    }

    return 0;
}