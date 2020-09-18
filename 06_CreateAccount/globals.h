#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"

(connect);
(login);
(click_itinerary);
(click_flight);
(click_cancel);
(click_find_flight);
(choose_flight);
(fill_pay_info);
(logout);

#include "web_api.h"

random_Generator(char* paramname, int length) {
 char buffer[32] = "";
 int r,i;
 char c;
 rand((unsigned int)time(0));
 for (i = 0; i < length; i++) {
 r = rand() % 25 + 65;
 c = (char)r;
 buffer[i] = c;
  if (buffer[i] == buffer[i-1])
  {
  r = rand() % 25 + 65;
  c = (char)r;
  buffer[i] = c;
  }
 }
 lr_save_string(buffer, paramname);
return 0;
}

#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables

#endif // _GLOBALS_H
