/*
Se propone hacer una aplicación para 3DS que cuente el número de clics que el usuario hace en la pantalla táctil durante 3 segundos (aproximadamente) y vaya mostrando el contador en la pantalla superior. Al pulsar la tecla ‘A’ el proceso se debe reiniciar.
*/

#include <3ds.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	//Timer

	// Initialize services
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	//Touch Counter
	int times = 0;

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		//Labels
		printf("\x1b[1;1HPress A to restart counter.");
		printf("\x1b[2;1HTouched Times: %d", (int)times);

		//Timer

		if (kDown & KEY_A)
			//Clear console
			consoleClear();

		if (kDown & KEY_TOUCH)
		{
			if ()
				times++;
		}

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	// Exit services
	gfxExit();
	return 0;
}