/* realname.c - query the user's real name
 *
 * Copyright 1999, 2000  Jochen Voss  */

static const  char  rcsid[] = "$Id: realname.c,v 1.17 2000/10/16 15:59:02 voss Exp $";

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED 1
#endif

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <assert.h>

#if defined(__hp9000s800)
#include <stdarg.h>
#endif

#include "moon-buggy.h"


int
get_real_user_name (char *buffer, size_t size)
/* Query the real user name.
 * Store the result into BUFFER, but do not write more then SIZE
 * characters.  */
{
  int  res, start;
  char *tmp;

  tmp = xmalloc (size);
  
  if (buffer[0] == '\0') {
    uid_t me = geteuid ();
    struct passwd *my_passwd = getpwuid (me);
    if (my_passwd) {
      char *w = strchr (my_passwd->pw_gecos, ',');
      if (w)  *w = '\0';
      strncpy (buffer, my_passwd->pw_gecos, size);
    }
  }

  werase (message);
  if (buffer[0] == '\0') {
    waddstr (message, "please enter your name: ");
  } else {
    char  tmpl [100];
    int  def_size;

    def_size = COLS - size - strlen("please enter your name (default: \""
				  "\"): ");
    if (def_size >= (int)xstrnlen(buffer, size)) {
      sprintf (tmpl, "please enter your name (default: \"%%.%ds\"): ", size);
    } else {
      def_size -= 2;
      if (def_size < 6)  def_size = 6;
      assert (size >= 8);
      sprintf (tmpl, "please enter your name (default: \"%%.%ds..\"): ",
	       def_size);
    }
    wprintw (message, tmpl, buffer);
  }

  show_cursor ();
  echo ();
  res = wgetnstr (message, tmp, size);
  noecho ();
  hide_cursor ();
  
  start = 0;
  while (start < size && tmp[start] && isspace (tmp[start]))  ++start;
  if (start<size && tmp[start]) {
    strncpy (buffer, tmp+start, size-start);
    if (start>0)  buffer[size-start] = '\0';
  }
  free (tmp);
  return  res;
}
