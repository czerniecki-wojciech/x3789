
#ifndef __X3789_MACRO_VIEWER_H__
#define __X3789_MACRO_VIEWER_H__

#define _VALUE(x) #x
#define MACRO_VIEWER(var) #var "=" _VALUE(var)

#endif
