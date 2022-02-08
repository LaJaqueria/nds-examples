
#include <nds.h>
#include "engine.h"

#include "elliready.h"
#include "background.h"

Sprite elli={0,0};

int main(void){

    videoSetMode(MODE_5_2D);
    
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_SPRITE);

    
    
   
    bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

    decompress(backgroundBitmap, BG_GFX, LZ77Vram);
    
    oamInit(&oamMain, SpriteMapping_1D_128, false);

    initSprite(&elli, (u8*)ellireadyTiles);
    dmaCopy(ellireadyPal, SPRITE_PALETTE, 512);
    elli.anim_frame=0;
    elli.state=IDLE;
    elli.velx=0;
    elli.vely=0;

    while(true){

        scanKeys();

		int keys = keysHeld();

        if(keys & KEY_START) break;
            
        if(keys){

            if(keys & KEY_UP){
                elli.state=UP;
                elli.vely=-2;

            }
            if(keys & KEY_DOWN){
                elli.state=DOWN;
                elli.vely=2;
            }

            if(keys & KEY_LEFT){
                elli.state=LEFT;
                elli.velx=-2;
            }
            if(keys & KEY_RIGHT){
                elli.state=RIGHT;
                elli.velx=2;
            }
        }else{
            elli.state=IDLE;
            elli.velx=0;
            elli.vely=0;
        }
   
        elli.x+=elli.velx;
        elli.y+=elli.vely;

        animSprite(&elli);
        oamSet(&oamMain, 0, elli.x, elli.y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, 
			elli.sprite_gfx_frame, -1, false, false, false, false, false);
        


        elli.anim_frame++;

        if(elli.anim_frame>=FRAMES_PER_ANIMATION) elli.anim_frame=0;

        swiWaitForVBlank();
        oamUpdate(&oamMain);
    }

    return 0;

}