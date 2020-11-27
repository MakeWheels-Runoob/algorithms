# algorithms
============================
Some useful functions and classes.

## explain
   ### macro
       DEBUG: If you want to debug, define this macro at the beginning of the program.
       LOG: If the macro "DEBUG" is defined, the function of this macro is to output the function and line number of the macro, 
                                             otherwise it is an empty macro.
                                             
       TEMPLATE(name): Expand to "template <class name>".
       TEMPLATE_TWO_NAME(name1, name2): Expand to "template <class name1, class name2>".
       SET_TYPE_TEMPLATE(type,name): Expand to "template <type name>".
       SET_TYPE_TEMPLATE_TWO_NAME(type1,name1,type2,name2): Expand to "template <type1 name1, type2 name2>".
       
