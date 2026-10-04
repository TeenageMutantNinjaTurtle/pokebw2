#ifndef POKEBW2_SYSTEM_APP_TASKMENU_H
#define POKEBW2_SYSTEM_APP_TASKMENU_H

#include "types.h"

// The menus of buttons on the lower screen that apps open, such as the trade's. The name is descriptive

typedef struct AppTaskMenu AppTaskMenu;
// A menu of one button
typedef struct AppTaskMenuWin AppTaskMenuWin;

// Frees the menu
void func_0202da54(AppTaskMenu *menu);
// Whether the choice's animation has ended
BOOL func_0202dbe4(AppTaskMenu *menu);
// The button that was chosen
u8 func_0202dc00(AppTaskMenu *menu);
// Shows or hides the cursor on the button
void func_0202dc04(AppTaskMenu *menu, BOOL show);
// Whether a button was touched
BOOL func_0202dc1c(AppTaskMenu *menu);
void func_0202db70(AppTaskMenu *menu);
void func_0202e37c(AppTaskMenuWin *win);

#endif // POKEBW2_SYSTEM_APP_TASKMENU_H
