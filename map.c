#include <stdio.h>
#include "map.h"
#include "player.h"
#include "box.h"
#include "torch.h"
#include "menu.h"
#include "Cheats/cheats.h"
#include "projectile.h"
#include "doorAndKeys.h"

char map[MAP_ROWS][MAP_COLS];

// Xavier & Pedro
void printMap()
{
    printf("\n");
    printf("Death Count: %d", deathCounter);
    printInventory();
    printf("\n");
    torchDisplay();
    sanityDisplay();
    printf("\n");
    if (thrown == true)
    {
        WIPDisplay();
    }
    else
    {
        printf("\n");
    }
    pressurePlate();
    printDebugStats();
    printf("\n\n");
    if (fullBrightOn == false)
    {
        for (int x = 0; x < MAP_ROWS; x++)
        {
            for (int y = 0; y < MAP_COLS; y++)
            {
                // Bomb projectile brightness
                if (thrown == true && ((x == WIP.position_x + 1 && y == WIP.position_y) || (x == WIP.position_x - 1 && y == WIP.position_y) || (x == WIP.position_x && y == WIP.position_y + 1) || (x == WIP.position_x && y == WIP.position_y - 1) || (x == WIP.position_x + 1 && y == WIP.position_y + 1) || (x == WIP.position_x - 1 && y == WIP.position_y + 1) || (x == WIP.position_x + 1 && y == WIP.position_y - 1) || (x == WIP.position_x - 1 && y == WIP.position_y - 1) || (x == WIP.position_x + 2 && y == WIP.position_y) || (x == WIP.position_x - 2 && y == WIP.position_y) || (x == WIP.position_x && y == WIP.position_y + 2) || (x == WIP.position_x && y == WIP.position_y - 2)) && WIP.projectileLevel > 10)
                {
                    if (x == box1.position_x && y == box1.position_y)
                        printf("📦");
                    else if (map[x][y] == 'X')
                        printf("🟧");
                    else if (map[x][y] == 'W')
                        printf("🧱");
                    else if (map[x][y] == 'T')
                        printf("🕸️ ");
                    else if (map[x][y] == 'K')
                        printf("🗝️ ");
                    else
                        printf("🟧");
                    continue;
                }

                if (thrown == true && ((x == WIP.position_x + 1 && y == WIP.position_y) || (x == WIP.position_x - 1 && y == WIP.position_y) || (x == WIP.position_x && y == WIP.position_y + 1) || (x == WIP.position_x && y == WIP.position_y - 1)) && WIP.projectileLevel > 5)
                {
                    if (x == WIP.position_x && y == WIP.position_y && WIP.collected == true)
                        printf("💣");
                    else if (map[x][y] == 'X')
                        printf("🟫");
                    else if (map[x][y] == 'W')
                        printf("🧱");
                    else
                        printf("🟫");
                    continue;
                }

                // player defualt vision radius
                if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x - 1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1) || (x == player.position_x - 2 && y == player.position_y) || (x == player.position_x + 2 && y == player.position_y) || (x == player.position_x && y == player.position_y - 2) || (x == player.position_x && y == player.position_y + 2) || (x == player.position_x + 1 && y == player.position_y + 1) || (x == player.position_x - 1 && y == player.position_y + 1) || (x == player.position_x + 1 && y == player.position_y - 1) || (x == player.position_x - 1 && y == player.position_y - 1)) && (torchLevel > 10))
                {
                    if (x == box1.position_x && y == box1.position_y)
                        printf("📦");
                    else if (x == WIP.position_x && y == WIP.position_y && WIP.collected == false)
                        printf("💣");
                    else if (map[x][y] == 'X')
                        printf("🟧");
                    else if (map[x][y] == 'Z')
                        printf("🟧");
                    else if (map[x][y] == 'W')
                        printf("🧱");
                    else if (map[x][y] == 'T')
                        printf("🕸️ ");
                    else if (map[x][y] == 'P')
                        printf("🟪");
                    else if (map[x][y] == 'H')
                        printf("🔒");
                    else if (map[x][y] == 'K')
                        printf("🗝️ ");
                    else if (map[x][y] == 'D')
                        printf("🪜 ");
                    // Trent. Torch now appears when in the light around the character
                    else if (map[x][y] == 'L')
                    {
                        printf("🕯️ ");
                    }
                }

                // play vision radius dim
                else if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x - 1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1)) && (torchLevel > 5))
                {
                    if (x == box1.position_x && y == box1.position_y)
                        printf("📦");
                    else if (x == WIP.position_x && y == WIP.position_y && WIP.collected == false)
                        printf("💣");
                    else if (map[x][y] == 'X')
                        printf("🟫");
                    else if (map[x][y] == 'Z')
                        printf("🟫");
                    else if (map[x][y] == 'W')
                        printf("🧱");
                    else if (map[x][y] == 'T')
                        printf("🕸️ ");
                    else if (map[x][y] == 'P')
                        printf("🟪");
                    else if (map[x][y] == 'H')
                        printf("🔒");
                    else if (map[x][y] == 'K')
                        printf("🗝️ ");
                    else if (map[x][y] == 'D')
                        printf("🪜 ");
                    // Trent. Torch now appears when in the light around the character
                    else if (map[x][y] == 'L')
                        printf("🕯️ ");

                }
                // candle/ environmental torch lighting
                else if (x == player.position_x && y == player.position_y)
                    printf("🤠");
                else if (x == box1.position_x && y == box1.position_y)
                    printf("📦");
                else if (x == WIP.position_x && y == WIP.position_y && WIP.collected == false)
                    printf("💣");
                else if ((map[x][y] == 'L') || (x > 0 && map[x - 1][y] == 'L') || (x < MAP_ROWS - 1 && map[x + 1][y] == 'L') || (y > 0 && map[x][y - 1] == 'L') || (y < MAP_COLS - 1 && map[x][y + 1] == 'L') || (x > 0 && y > 0 && map[x - 1][y - 1] == 'L') || (x > 0 && y < MAP_COLS - 1 && map[x - 1][y + 1] == 'L') || (x < MAP_ROWS - 1 && y > 0 && map[x + 1][y - 1] == 'L') || (x < MAP_ROWS - 1 && y < MAP_COLS - 1 && map[x + 1][y + 1] == 'L'))
                {
                    if (map[x][y] == 'X')
                        printf("🟫");
                    if (map[x][y] == 'Z')
                        printf("🟫");
                    if (map[x][y] == 'W')
                        printf("🧱");
                    if (map[x][y] == 'T')
                        printf("🕸️ ");
                    if (map[x][y] == 'K')
                        printf("🗝️ ");
                    if (map[x][y] == 'H')
                        printf("🔒");
                    if (map[x][y] == 'L')
                        printf("🕯️ ");
                    if (map[x][y] == 'D')
                        printf("🪜 ");
                    if (map[x][y] == 'P')
                        printf("🟪");
                }

                // blacking out map
                else if (x == player.position_x && y == player.position_y)
                    printf("🤠");
                else if (x == box1.position_x && y == box1.position_y)
                    printf("⬛");
                else if (x == WIP.position_x && y == WIP.position_y && WIP.collected == false)
                    printf("⬛");
                else if (map[x][y] == 'X')
                    printf("⬛");
                else if (map[x][y] == 'Z')
                    printf("⬛");
                else if (map[x][y] == 'W')
                    printf("⬛");
                else if (map[x][y] == 'H')
                    printf("⬛");
                else if (map[x][y] == 'P')
                    printf("⬛");
                else if (map[x][y] == 'T')
                    printf("⬛");
                else if (map[x][y] == 'L')
                    printf("🕯️ ");
                else if (map[x][y] == 'D')
                    printf("🪜 ");
                else if (map[x][y] == 'K')
                    printf("🗝️");
                else
                    printf("%c", map[x][y]);
            }
            if (torchLevel == 0)
            {
                playerDeath();
            }

            printf("\n");
        }
    }
    // FULL BRIGHTNESS CHEAT
    else if (fullBrightOn == true)
    {
        for (int x = 0; x < MAP_ROWS; x++)
        {
            for (int y = 0; y < MAP_COLS; y++)
            {
                if (x == player.position_x && y == player.position_y)
                    printf("🤠");
                else if (x == box1.position_x && y == box1.position_y)
                    printf("📦");
                else if (x == WIP.position_x && y == WIP.position_y && WIP.collected == false)
                    printf("💣");
                else if (map[x][y] == 'X')
                    printf("🟫");
                else if (map[x][y] == 'Z')
                    printf("🟫");
                else if (map[x][y] == 'W')
                    printf("🧱");
                else if (map[x][y] == 'T')
                    printf("🕸️ ");
                else if (map[x][y] == 'P')
                    printf("🟪");
                else if (map[x][y] == 'H')
                    printf("🔒");
                else if (map[x][y] == 'K' && getKey == false)
                    printf("🗝️ ");
                else if (map[x][y] == 'D')
                    printf("🪜 ");
                else if (map[x][y] == 'L')
                    printf("🕯️ ");
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    printf("\t\t W - Up\nA - Left\t S - Down\t D - Right\n\nE - Interact with Box\nP - Pause Game");
    printf("\n");
    printf("C - Turn Cheats On");
    printf("\n");
    printCheats();
    printf("\n\n");
}

void printDebugStats()
{
    printf("\n");
    printf("Is the box being grabbed: %s", box1.beingGrabbed ? "✅" : "❌");
}

void trapPlate()
{
    if (map[box1.position_x][box1.position_y] == 'T')
    {
        printf("You have triggered a trap! Game Over.\n");
        deathCounter++;
        printMenu();
    }
}

// Xavier with Cesar's help
void loadMap(const char *filename)
{

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Failed to open map file");
        return;
    }

    printf("loading map %s", filename);
    for (int row = 0; row < MAP_ROWS; row++)
    {
        for (int col = 0; col < MAP_COLS; col++)
        {
            int ch = fgetc(file);
            if (ch == EOF)
            {
                fclose(file);
                return;
            }
            if (ch == '\n')
            {
                col--;
                continue;
            }
            map[row][col] = (char)ch;
        }
    }
    fclose(file);
}





bool map_in_bounds(int row, int col)
{
    return row >= 0 && row < MAP_ROWS && col >= 0 && col < MAP_COLS;
}


char map_get_tile(int row, int col)
{
    if (!map_in_bounds(row, col))
        return TILE_WALL;
    return map[row][col];
}


char map_handlechar(char c, int x, int y)
{
    if (c == 'B')
    {
        //create_potion(x, y);
        return 'F';
    }

    return c;
}