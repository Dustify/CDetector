#include "shared.h"

class Intro
{
public:
	static void Render()
	{
		if (Shared::IsNaughtyMode())
		{
			Display.clearDisplay();
			Display.setTextColor(SSD1306_WHITE);
			Display.setTextSize(2);

			Display.setCursor(40, 0);
			Display.println("CUNT");
			Display.setCursor(40, 18);
			Display.println("MODE");


			Display.display();

			delay(2000);
		}

		Display.clearDisplay();

		Display.drawRect(
			0,
			0,
			Display.width() - 1,
			Display.height() - 1,
			SSD1306_WHITE);

		Display.display();

		Display.setTextSize(1);
		Display.setTextColor(SSD1306_WHITE);

		Display.setCursor(15, 3);
		Display.print("Merry Christmas,");

#ifdef MODE_LEE
		Display.setCursor(38, 12);
		Display.print("Leeface");
#endif

#ifdef MODE_ROSE
		Display.setCursor(40, 12);
		Display.print("Roseface");
#endif

		Display.setCursor(12, 20);
		Display.print("Lots of love AJ x");

		Display.display();

		delay(3000);
	}
};