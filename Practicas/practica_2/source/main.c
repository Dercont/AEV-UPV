/*
Se propone hacer una aplicación para 3DS que cuente el número de clics que el usuario hace en la pantalla táctil durante 3 segundos (aproximadamente) y vaya mostrando el contador en la pantalla superior. Al pulsar la tecla ‘A’ el proceso se debe reiniciar.
*/

#include <3ds.h>
#include <stdio.h>
// #include <time.h>

int main(int argc, char **argv)
{
	// Initialize services
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	u32 kDownOld = 0; //In these variables there will be information about keys detected in the previous frame

	//Touch Counter
	int times = 0;

	printf("\x1b[1;1HPress A to restart counter.");
	printf("\x1b[2;1HTouched Times: %d", (int)times);

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_A)
			break; // break in order to return to hbmenu
		if (kDown & KEY_TOUCH)
			times++;

		//Do the keys printing only if keys have changed
		if (kDown != kDownOld)

		{
			//Clear console
			consoleClear();

			//These two lines must be rewritten because we cleared the whole console
			printf("\x1b[1;1HPress A to restart counter.");
			printf("\x1b[2;1HTouched Times: %d", (int)times);
		}

		//Set keys old values for the next frame
		kDownOld = kDown;

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