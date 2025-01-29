# wxWidgets printing framework
This is a simple overloading of the wxPrintout class, which is part of the wxWidgets printing framework. I have implemented the drawing to the DC printer through a function that the user can pass through a pointer. This method allows you to write your own print function for each class whose data you want to print, so you don't need to overload wxPrintout for each of them.

