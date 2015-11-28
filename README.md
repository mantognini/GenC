# GenC – From Verified Functions to Safe C Code

This project was done at [EPFL](http://epfl.ch) under the supervision of Viktor Kuncak at
[LARA](http://lara.epfl.ch/w/) (Lab for Automated Reasoning and Analysis) in Fall 2015 by Marco Antognini.

## Abstract

As software becomes more and more complex we need ways to ensure it works according to its specification.
While hardware is more and more robust and cheaper, even for extreme environments such as space exploration 
(e.g. spacecraft) or medical device (e.g. pacemaker), software development costs substantially increase
when programs have to be robust and safe. Many companies spend a significant part of their budget in making
sure their software won't put people's life in danger or result in a huge monetary loss.

[Leon](http://leon.epfl.ch) works at solving this issue for programs written in (a subset of) Scala by 
providing tools to verify contracts, repair erroneous implementations or even synthesis implementations.
However, Scala being based on JVM runtime, such tools are close to worthless for many companies that run
their software on very small devices: the lack of memory and CPU resources prevents running virtualised 
code on such devices and most of the implementation are written in C-like languages.

We therefore extend [Leon](http://leon.epfl.ch) to generate standard C99 code from a subset of Scala in
order to benefit from the high-level features of this language and therefore reducing the development
cost of low-level software while avoiding using an error-prone languages. The produced code can then be
compiled using any C compiler, generating a native and optimised assembly code for specific hardware
architectures.


