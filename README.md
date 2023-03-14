# Pi Day 2023

I made some simple programs to celebrate pi day. I calculated pi, and then I made two programs that calculate sin, cos and tan from scratch.

## Pi (file compl.c)
I calculated pi by integrating the function 1/z over a square with side one centered at origin. This converges very slowly. I didn't do anything smart with the integration,, when I subdivide each line into a million pieces, I get 12 digits of precision `pi = 3.1415926535895378`.

## sin cos tan by Taylor series (file trig.c)
Does just what it says on the tin. I added some almost clever shifts and reflections so that I only need to calculate values in the interval [0, pi].

## sin cos tan by their defining system of differential equations (file diff.c)
Did the same shift trickery. I calculated sin and cos by using their defining system of ODEs. (sin'=cos, cos'=-sin, sin(0)=0, cos(0)=1)
