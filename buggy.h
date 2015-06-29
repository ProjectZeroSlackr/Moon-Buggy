/* buggy.h - the image data for "buggy.c"
 * Automatically created from file "car.img".
 * DO NOT EDIT !!! */

static char *image[][2] = {
  {
    "   Omm ",
    "(0)-(0)",
  },
  {
    "   OMM ",
    "(U)-(U)",
  },
  {
    "   OMm ",
    "(0)-(0)",
  },
  {
    "   oMm ",
    "(0)-(0)",
  },
  {
    "   omm ",
    "(o)_(o)",
  },
  {
    "   __  ",
    "cnOMMnb",
  },
  {
    "   OMm ",
    "#(0)(0)",
  },
  {
    " n OMm ",
    "##0)(0)",
  },
  {
    "  ##Mm ",
    " ###(0)",
  },
  {
    "   #MM ",
    "(0###0)",
  },
};

enum car_state { 
  car_NORMAL, car_START, car_UP1, car_UP2, car_LAND, car_BROKEN, car_RAM1, car_RAM2, car_RAM3, car_SIT, 
};
