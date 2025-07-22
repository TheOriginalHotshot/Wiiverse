#include "graphics.h"

GRRLIB_texImg *tex_background = NULL;
GRRLIB_texImg *tex_exit_icon = NULL;

void Init_Resources() {
    tex_background = GRRLIB_LoadTexture(background_png);
    tex_exit_icon = GRRLIB_LoadTexture(exit_icon_png);
}

void Free_Resources() {
    GRRLIB_FreeTexture(tex_background);
    GRRLIB_FreeTexture(tex_exit_icon);
}

void Draw_LoadingScreen() {
    GRRLIB_FillScreen(0x0000AAFF); // Blue background
    GRRLIB_Printf(300, 220, NULL, 0xFFFFFFFF, 1, "LOADING...");
    GRRLIB_Render();
}

void Draw_MainMenu() {
    // Draw background
    GRRLIB_DrawImg(0, 0, tex_background, 0, 1, 1, 0xFFFFFFFF);
    
    // Title
    GRRLIB_Printf(250, 50, NULL, 0xFFFFFFFF, 1.5, "Wiiverse");
    
    // Buttons
    GRRLIB_Rectangle(200, 150, 240, 50, 0x555555FF, 1); // Message Mii
    GRRLIB_Printf(265, 165, NULL, 0xFFFFFFFF, 1, "Message Mii");
    
    GRRLIB_Rectangle(200, 220, 240, 50, 0x555555FF, 1); // Communities
    GRRLIB_Printf(260, 235, NULL, 0xFFFFFFFF, 1, "Communities");
    
    GRRLIB_Rectangle(200, 290, 240, 50, 0x555555FF, 1); // Settings
    GRRLIB_Printf(280, 305, NULL, 0xFFFFFFFF, 1, "Settings");
    
    // Exit button (top-right)
    GRRLIB_DrawImg(570, 10, tex_exit_icon, 0, 0.5, 0.5, 0xFFFFFFFF);
    
    // Version text
    GRRLIB_Printf(280, 420, NULL, 0x999999FF, 0.7, "Alpha V1.0");
}
