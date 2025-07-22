#pragma once
#include <grrlib.h>
#include <wiiuse/wpad.h>

// Resources
extern GRRLIB_texImg *tex_background;
extern GRRLIB_texImg *tex_exit_icon;

void Init_Resources();
void Free_Resources();
void Draw_LoadingScreen();
void Draw_MainMenu();
