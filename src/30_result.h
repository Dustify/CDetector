#include "shared.h"

class Result
{

public:
    static void Render()
    {
        Display.clearDisplay();
        Display.setCursor(0, 0);

        const char one[] = "Scan complete...\n";

        for (int i = 0; i < strlen(one); i++)
        {
            Display.print(one[i]);
            Display.display();

            delay(50);
        }

        const char *two[4];

        if (Shared::IsNaughtyMode())
        {
            two[0] = "WARNING\nPossible cunt\ndetected";
            two[1] = "WARNING\nProbable cunt\ndetected";
            two[2] = "WARNING\nAbsolute cunt\ndetected";
            two[3] = "WARNING\nTOTAL cunt detected";
        }
        else
        {
            two[0] = "WARNING\nPossible pleb\ndetected";
            two[1] = "WARNING\nProbable pleb\ndetected";
            two[2] = "WARNING\nAbsolute pleb\ndetected";
            two[3] = "WARNING\nTOTAL pleb detected";
        }

        const char *twoA = two[random(4)];

        for (int i = 0; i < strlen(twoA); i++)
        {
            Display.print(twoA[i]);
            Display.display();

            delay(50);
        }

        delay(5000);
    }
};