# Reinvented Wheel

The functions implemented here are almost certainly implemented better somewhere else - I'm aware of that!  
I'm reinventing the wheel here for the purposes of

1. Exam study
2. Convenience for assignments
3. Experience for when I join a soul-sucking corporation plagued with NIH syndrome.

One or more of the above may be firmly tongue in cheek.

## Compilation

For the executables, you can `make Systems1415.e` (for example) to make something that can be executed. Note that dependencies need to be manually added to the makefile, see the one for Systems as an example.

The makefile there now compiles with `clang src/src.c -c -Iincludes/ -g -Werror -Wall -Wextra -pedantic -o compiled/output.o`. Here's why:

| Flag          | What it does                              | Why I use it                                                                                                                    |
|:-------------:|:------------------------------------------|:--------------------------------------------------------------------------------------------------------------------------------|
| **-c**        | Disables linking                          | When you're just building individual files, they don't need to be linked, that comes later.                                     |
| **-I**        | Tells the compiler where the .h files are | If you don't use this one, you'll just get a fatal error when it can't find header files it's looking for.                      |
| **-g**        | Enables debugging symbols                 | I often use `valgrind`, enabling debugging symbols lets it print out line numbers when it can so I can find my bugs faster.     |
| **-Werror**   | Turns warnings into errors                | This forces me to fix all warnings before moving on - letting them pile up seems like a terrible practice to me.                |
| **-Wall**     | Enables more warnings                     | More warnings is a good thing, they help you catch your mistakes sooner rather than later, and any help is good.                |
| **-Wextra**   | Enables even more warnings                | Same as the last.                                                                                                               |
| **-pedantic** | Issues warnings for non-ISO C practices   | This issues even *more* warnings (see a trend yet?), although generally they're less important.                                 |
| **-o**        | Directs the output to a given file        | Self explanatory I hope.                                                                                                        |

One more note, I use a .e extension for executable things, which allows me to simplify clean scripts to simply delete \*\*/\*.e (where \*\* is the globstar, checking all directories under the current one). When I'm not linking immediately, I add a .o deletion rule (and obviously lines for both in .gitignore).

## Bugs, Errors, Help

Run into something? Add it as an issue, email me, or issue a pull request.

### Committing

If you do submit a pull request, please make sure you meet my coding standard - in general look at the rest of the code to see what it's like, but:

| Rule | Reasoning | How to do it |
|:----:|:----------|:-------------|
| Use tabs for indentation. | Forcing your exact indentation width on other people is no fun. I can adjust my tabs without changing any of the code, but I can't remove/add spaces without changing anything. | Starting a new block? Add one more tab than the last line. |
| Use spaces to align broken up lines. | This means the indentation and alignment will look consistent regardless of your tab width, and things will line up nicely. | If you split something across multiple lines, indent as many times as the previous line, then add spaces until it lines up with the relevant thing on the line above. |
| Keep lines to 80 characters or less. | I often have multiple files open on a single screen so I can cross reference headers to source, for example, which means restricted screen space. Narrow files means more stuff on my screen. | A decent text editor/IDE will tell you how long your lines are. Break them up at the nearest logical place that keeps them at or under 80 characters. A decent IDE will even pick logical places to break up lines and do it for you. |
| Use braces on every if/for/while/else etc. | There's not a lot of reasoning to this one, but I think consistency is good. | This one doesn't need explaining, I hope. There's one exception to the rule, though, error checking stuff at the start of functions don't need braces, just keep the return on the same line. If you need to drop it a line to keep the line short, add braces.|
| Keep the naming reasonable. | Consistent, logical naming keeps it easy to write code without constant referencing back. | Take a look at how functions are named, for example `sortsQuick` instead of `sortsQuicksort`. Keep duplication and length to minimum without dropping characters, and since these files are intended to be included in plenty of places, they're prepended with a word describing what they're for to reduce namespace pollution (hopefully!). |
| Use lowerCamelCase. | Similar to using braces, this one's a matter of consistency. I choose lowerCamelCase specifically because I just think it tends to look better than the alternatives. | Describe the variable or function, remove the spaces, capitalise the first word of each word (and drop other capitals in the word, like `parseHtml` instead of `parseHTML`). Again, see the existing code. |

I might add more to this so please do check back before submitting a pull request, but I'll keep changes to a minimum where possible.
