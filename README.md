# Open Liquid

Open Liquid is a parsing and rendering engine for [the Liquid Markup Language](http://www.liquidmarkup.org/) written in C++ with the goal of being bindable to any scripting language interpreter. Currently, only TCL is supported through the TCL C API.

## Prerequisites

Open Liquid compiles to a static library that depends only on the [Perl Compatible Regular Expressions C++ wrapper (pcrecpp)](http://www.gammon.com.au/pcre/pcrecpp.html). Most Linux distributions offer a complete version of the library with all its dependencies through package managers.

For compiling Open Liquid itself, the GNU toolchain and `cmake` is required.

## Compiling

To compile the Open Liquid library, start by installing the prerequisites and cloning the Open Liquid source code base into a directory of your choice.

    $ git clone git://github.com/23/openliquid.git

Open Liquid can be configured either for debugging or release, the difference being compiler optimization level and debugging symbols. The default behavior is to use the release configuration. Compiling is done in a few, simple steps like so:

    $ cd openliquid
    $ ./configure <debug | release>
    $ make

To make sure that the version of the code, that you have checked out from [github](http://www.github.com/) is a functional version, you should also make sure to run the unit tests for the library:

    $ ctest

## License

Copyright (c) 2011 - 23 Visual ApS

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
  claim that you wrote the original software. If you use this software
  in a product, an acknowledgment in the product documentation would be
  appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must not be
  misrepresented as being the original software.

  3. If you meet (any of) the author(s), you're encouraged to buy them a beer,
  a drink or whatever is suited to the situation, given that you like the
  software.

  4. This notice may not be removed or altered from any source
  distribution.
