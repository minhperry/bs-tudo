#include "mp3.h"

void idTagFile(const char *fileName,char *comment)
{
	/* HIER MUESST IHR EUREN CODE EINFUEGEN */

	if (!strncmp(".", fileName, 2) || !strncmp("..", fileName, 3))
               	return;

	/* HIER MUESST IHR EUREN CODE EINFUEGEN */
	
	/* Hier ist ein kleiner Codeschnipsel, den ihr in euren Code einbauen sollt,		*
	 * um an geeigneter Stelle zu ueberpruefen, ob es sich um eine MP3-Datei handelt. 	*
	 *											*
	 *	if (strncmp(fileName + strlen(fileName) - 4, ".mp3", 4)) {			*
	 *		printf("%s: ausgelassen\n", fileName);					*
	 *		return;									*
	 *	}										*
	 *											*/

	/* HIER MUESST IHR EUREN CODE EINFUEGEN */
}
