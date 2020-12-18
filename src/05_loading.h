#include "shared.h"

class Loading
{
public:
    static void Render()
    {
        Display.clearDisplay();
        Display.setTextSize(1);
        Display.setTextColor(SSD1306_WHITE);
        Display.setCursor(0, 0);

        const char one[] = "Plebinator 2000 v0.65\nLoading resources...\n";
        const char oneA[] = "Cuntinator 2000 v0.65\nLoading resources...\n";

        for (int i = 0; i < strlen(one); i++)
        {
            if (Shared::IsNaughtyMode())
            {
                Display.print(oneA[i]);
            }
            else
            {
                Display.print(one[i]);
            }

            Display.display();

            delay(50);
        }

        delay(2000);

#ifdef MODE_LEE
        const char two[] = "Connect LeeNet...\n";
#endif

#ifdef MODE_ROSE
        const char two[] = "Connect RoseNet...\n";
#endif

        for (int i = 0; i < strlen(two); i++)
        {
            Display.print(two[i]);
            Display.display();

            delay(50);
        }

        delay(2000);

        const char three[] = "Connected.";

        for (int i = 0; i < strlen(three); i++)
        {
            Display.print(three[i]);
            Display.display();

            delay(50);
        }

        delay(2000);

#ifdef MODE_ROSE
        const char four[] = "Calling Jamie a\n****...\n";
        const char fourA[] = "Calling Jamie a\ncunt...\n";

        Display.clearDisplay();
        Display.setCursor(0, 0);

        for (int i = 0; i < strlen(four); i++)
        {
            if (Shared::IsNaughtyMode())
            {
                Display.print(fourA[i]);
            }
            else
            {
                Display.print(four[i]);
            }

            Display.display();

            delay(50);
        }

        delay(2000);

        Display.print("Complete.");
        Display.display();

        delay(2000);
#endif
    }
};