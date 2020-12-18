#include "shared.h"
#include "20_scanning.h"

static const unsigned char PROGMEM arrow_up[] =
    {
        B00000001, B10000000,
        B00000011, B11000000,
        B00000111, B11100000,
        B00001111, B11110000,
        B00011111, B11111000,
        B00111111, B11111100,
        B01111111, B11111110,
        B11111111, B11111111,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000};

static const unsigned char PROGMEM arrow_down[] =
    {
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B00001111, B11110000,
        B11111111, B11111111,
        B01111111, B11111110,
        B00111111, B11111100,
        B00011111, B11111000,
        B00001111, B11110000,
        B00000111, B11100000,
        B00000011, B11000000,
        B00000001, B10000000};

class Waiting
{

public:
    static void Render()
    {
        Display.setTextSize(1);
        Display.setTextColor(SSD1306_WHITE);

        int counter = 0;

        while (true)
        {
            if (Shared::IsButtonPressed())
            {
                Scanning::Render();
            }

            unsigned long start = millis();

            Display.clearDisplay();

            if (counter <= 2000)
            {
                Display.setCursor(8, 20);
                Display.print("Aim towards subject");

                Display.drawBitmap(56, 0, arrow_up, 16, 16, SSD1306_WHITE);

                Display.display();
            }
            else
            {
                Display.setCursor(8, 0);
                Display.print("Hold button to scan");

                Display.drawBitmap(56, 12, arrow_down, 16, 16, SSD1306_WHITE);

                Display.display();
            }

            unsigned long duration = millis() - start;

            counter += duration;

            if (counter > 4000)
            {
                counter = 0;
            }
        }
    }
};