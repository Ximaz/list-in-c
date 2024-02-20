# List in C

This project aims to re-build the most powerfull list type in C at ground-0
level, with the most optimized memory management and the most accessible
features.

# Features

Let's talk about the features I want to implement. Each feature can be found
at `include/list.h`. If you scroll down a little bit, you'll see all functions
I'm planning on implementing.

Note that, each feature followed by :
- `_itself` : will affect the current list,
- `_into` : won't affect the current list, and will set the result in `output`,
- `<nothing>`: won't affect the current list and will allocate a new list.
