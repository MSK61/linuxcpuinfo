# linuxcpuinfo
CPU information visualizer for linux

Requirements
------------
Qt 5.9.1 and(optionally) googletest

Building
--------
The UI application can be built simply by typing

    qmake linuxcpuinfo.pro
A `Makefile` file has now been generated. Now to produce the executable run

    make
You'll notice a new executable called `linuxcpuinfo` generated; this's the UI application you should run.

The building instructions for the test project are similar. First make sure to point `GOOGLETEST_DIR` as an environment variable or qmake variable to the root of the googletest source tree. Now type

    qmake test.pro
to generate the `Makefile`. Then build the test executable.

    make
The generated test executable is called `test`, a command-line application.
