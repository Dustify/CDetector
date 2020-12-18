#include "shared.h"
#include "30_result.h"

#define SCAN_DURATION 5000

#define GRAPH_COUNT 50
#define GRAPH_HEIGHT 13

class Scanning
{

public:
    static void Render()
    {
        Display.clearDisplay();
        Display.setTextSize(1);
        Display.setTextColor(SSD1306_WHITE);

        unsigned long start = millis();

        int graphIndex = 0;

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