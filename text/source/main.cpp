#include <nds.h>
#include <stdio.h>

int main()
{
	PrintConsole topScreen;
	PrintConsole bottomScreen;

	//Init main and sub consoles to text mode
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);
	consoleDemoInit();
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&topScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

	consoleSelect(&topScreen);
	iprintf("\n\n\t\tLa Jaqueria\n");
	iprintf("\t\x1b[31mTest texto Superior\n");
	iprintf("\t\x1b[35mwww.lajaqueria.org");

	consoleSelect(&bottomScreen);

	iprintf("\x1b[1;5HLa Jaqueria\n");
	iprintf("\x1b[2;2H\x1b[31mTest texto Inferior\n");
	iprintf("\x1b[3;2H\x1b[32mwww.lajaqueria.org");

	while (true)
	{
		swiWaitForVBlank();
	}

	return 0;
}