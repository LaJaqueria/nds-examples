#include <nds.h>
#include <stdio.h>

int main()
{
	PrintConsole topScreen;
	PrintConsole bottomScreen;

	//Init main and sub consoles to text mode
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&topScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

	consoleSelect(&topScreen);
	iprintf("\n\n\tLa Jaqueria\n");
	iprintf("\tTest texto Superior\n");
	iprintf("\twww.lajaqueria.org\x1b[39m");

	consoleSelect(&bottomScreen);

	iprintf("\n\n\tLa Jaqueria\n");
	iprintf("\tTest texto Inferior\n");
	iprintf("\t\twww.lajaqueria.org");

	while (true)
	{
		swiWaitForVBlank();
	}

	return 0;
}