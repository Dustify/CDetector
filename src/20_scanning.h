#include "shared.h"
#include "30_result.h"

#define SCAN_DURATION 5000

#define GRAPH_COUNT 50
#define GRAPH_HEIGHT 13

#define SEARCH_BM_X 108
#define SEARCH_BM_Y 2
#define SEARCH_BM_COUNT 3

#ifdef MODE_LEE

static const unsigned char PROGMEM search_1[] = {
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000001, B10000000,
    B00000010, B01000000,
    B00000100, B00100000,
    B00001000, B00010000,
    B00000000, B00000000};

static const unsigned char PROGMEM search_2[] = {
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000011, B11000000,
    B00000100, B00100000,
    B00001000, B00010000,
    B00010001, B10001000,
    B00000010, B01000000,
    B00000100, B00100000,
    B00001000, B00010000,
    B00000000, B00000000};

static const unsigned char PROGMEM search_3[] = {
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000000, B00000000,
    B00000011, B11000000,
    B00000100, B00100000,
    B00001000, B00010000,
    B00010000, B00001000,
    B00100011, B11000100,
    B00000100, B00100000,
    B00001000, B00010000,
    B00010001, B10001000,
    B00000010, B01000000,
    B00000100, B00100000,
    B00001000, B00010000,
    B00000000, B00000000};

#endif

#ifdef MODE_ROSE

static const unsigned char PROGMEM search_1[] =    {
B00000000, B00000000,
B00000000, B00000000,
B00000111, B00000000,
B00011000, B11000000,
B00010000, B10111100,
B00100100, B10000010,
B00100000, B10111110,
B01000000, B01000000,
B10000000, B01000000,
B00000000, B10000000,
B00000001, B00000000,
B00000110, B00000000,
B00001000, B00000000,
B00001000, B00000000,
B00010000, B00000000,
B00000000, B00000000};

static const unsigned char PROGMEM search_2[] =    {
B00000000, B00000000,
B00000000, B00000000,
B00000111, B00000000,
B00011000, B11000000,
B00010000, B10111100,
B00100100, B10000010,
B00100000, B10000000,
B01000000, B01111110,
B10000000, B01000000,
B00000000, B10000000,
B00000001, B00000000,
B00000110, B00000000,
B00001100, B00000000,
B00001011, B10000000,
B00010000, B10000000,
B00000000, B01000000};

static const unsigned char PROGMEM search_3[] =    {
B00000000, B00000100,
B00000000, B00100100,
B00000111, B00010101,
B00011000, B11000000,
B00010000, B10111100,
B00100100, B10000010,
B00100000, B10011110,
B01000000, B01000000,
B10000000, B01100100,
B00000000, B10011100,
B00000001, B00000000,
B00000110, B00111110,
B00001111, B11000000,
B00001000, B00111100,
B00010011, B11000000,
B00000000, B00001000};


#endif

class Scanning
{
private:
    static void RenderBitmap(const unsigned char *bitmap)
    {
        Display.drawBitmap(
            SEARCH_BM_X,
            SEARCH_BM_Y,
            bitmap,
            16,
            16,
            SSD1306_WHITE);
    }

public:
    static void Render()
    {
        Display.clearDisplay();
        Display.setTextSize(1);
        Display.setTextColor(SSD1306_WHITE);

        unsigned long start = millis();

        int graphIndex = 0;
        int bitmapIndex = 0;

        double duration = 0;

        while (Shared::IsButtonPressed() && duration < SCAN_DURATION)
        {
            double factor = duration / SCAN_DURATION;

            Display.setCursor(0, 0);
            Display.println("Scanning...");

            if (graphIndex >= GRAPH_COUNT)
            {
                graphIndex = 0;
            }

            Display.drawLine(
                2 * graphIndex,
                23,
                2 * graphIndex,
                23 - GRAPH_HEIGHT,
                SSD1306_BLACK);

            Display.drawLine(
                2 * graphIndex,
                23,
                2 * graphIndex,
                23 - random(GRAPH_HEIGHT),
                SSD1306_WHITE);

            graphIndex++;

            Display.fillRect(SEARCH_BM_X, SEARCH_BM_Y, 16, 16, SSD1306_BLACK);

            if (bitmapIndex >= SEARCH_BM_COUNT)
            {
                bitmapIndex = 0;
            }

            switch (bitmapIndex)
            {
            case 0:
                RenderBitmap(search_1);
                break;
            case 1:
                RenderBitmap(search_2);
                break;
            case 2:
                RenderBitmap(search_3);
                break;
            }

            if ((unsigned long)duration % 10 == 0)
            {
                bitmapIndex++;
            }

            Display.drawRoundRect(0, 27, 128, 5, 1, SSD1306_WHITE);
            Display.fillRect(2, 29, factor * 125, 1, SSD1306_WHITE);

            Display.display();

            duration = millis() - start;
        }

        if (duration < SCAN_DURATION)
        {
            Display.clearDisplay();
            Display.setCursor(45, 10);
            Display.print("WARNING");

            Display.setCursor(0, 19);
            Display.print("Scan did not complete");

            Display.display();
            delay(2000);
        }
        else
        {
            Result::Render();
        }
    }
};