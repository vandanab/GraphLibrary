GraphLibrary
============

A C++ Graph Library

Style Guidelines:
naming rules: <br>
1. Classes: CamelCase
2. member variables and member functions: lowercase separated by underscore.
3. enums, macros and constant names: CAPITALS separated by underscore
4. file names: lowercase separated by underscore.
5. complete words in names unless too long.

code: <br>
1. use nullptr or {} (empty initializer list) instead of NULL. 
2. Constructors with initializer lists preferred (new style), people no more write code inside the {} of a constructors, unless its to impose checks.
3. Write code inside a namespace. (for now its lib, we can change it)
4. use const wherever it makes sense to use it.

regarding header files: <br>
1. Don't use an #include when a forward declaration would suffice.
2. Important if we are using templatized classes: http://stackoverflow.com/questions/6807369/undefined-reference-to-constructor-generic-class?rq=1
3. All header files should have #define guards to prevent multiple inclusion. 

code editing guidelines (http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml - Formatting section): <br>
1. feel free to express yourselves in comments wherever needed.
2. indentation length: 2 space characters (or a tab consisting of 2 space characters)
3. try to keep lines of 80 characters, move extra code to next line with an extra indent (moving code to next line requires care).
4. function/class beginning parenthesis ({) at the end of the function signature instead of the next line
5. standard header file includes before self defined header file includes
