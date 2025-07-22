#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <ogc/lwp_watchdog.h>
#include <ogc/system.h>
#include "graphics.h"

// Embedded PNG data (use GRRLIB tool to convert)
extern const u8 background_png[];
extern const u8 exit_icon_png[];

int main() {
    // Initialize video and input
    GRRLIB_Init();
    WPAD_Init();
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

    // Show loading screen
    Draw_LoadingScreen();
    usleep(3000000); // 3 seconds

    // Load resources
    Init_Resources();

    bool running = true;
    f32 cursorX = 320, cursorY = 240; // Center cursor

    while(running) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);
        
        // Get IR data for cursor
        WPAD_IR_t *ir = WPAD_IR(0);
        if(ir) {
            cursorX = ir->x;
            cursorY = ir->y;
        }
        
        // Handle exit button press
        if(pressed & WPAD_BUTTON_A) {
            // Check if cursor over exit button
            if(cursorX > 570 && cursorX < 620 && cursorY > 10 && cursorY < 60) {
                SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
            }
        }
        
        // Rendering
        GRRLIB_FillScreen(0x00000000); // Clear screen
        Draw_MainMenu();
        
        // Draw cursor
        GRRLIB_Circle(cursorX, cursorY, 8, 0xFFFFFFFF, 1);
        
        GRRLIB_Render();
    }
    
    Free_Resources();
    GRRLIB_Exit();
    return 0;
}
