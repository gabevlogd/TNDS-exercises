# TNDS-exercises
some selected exercises carried out during the course of numerical treatment of experimental data (TNDS) at the physics faculty of Unimi. 
I report below some graphical results of the exercises


## - Differential equations:
In these exercises I use some methods for solving ordinary differential equations, in particular I use the Euler and Runge-Kutta methods

### Euler method for the harmonic oscillator (EX.1): 
- Euler's method is not very precise, in fact with a modest integration step we can see how it can be unstable, showing oscillations whose amplitude varies with time. The figure below shows the trend of x as a function of t with an integration step of 0.1 seconds:
![4twe4t4](https://user-images.githubusercontent.com/72387126/175076875-1dd7f529-3b32-477b-a9ae-97599af3ae7c.png)


- To have something even visually acceptable, you have to go in steps of at least 0.0001 s:
![Immagine](https://user-images.githubusercontent.com/72387126/175077389-81f4274f-2ff6-4fa0-a856-952481339f72.png)


- The following figure shows the accumulated error after 70 s of integration for different step values (Note how the slope of the curve is 1 in a log-log scale, showing how the error obtained is proportional to step h):
![wrwef](https://user-images.githubusercontent.com/72387126/175078347-6d452e29-23e7-4265-bb4c-e984dda7e9f2.png)


### Runge-Kutta method for the harmonic oscillator (EX.2):
- The fourth order Runge-Kutta method is much more precise than the Euler method, in fact, even with an integration step of 0.1 s it produces very stable oscillations:
![rtegerger](https://user-images.githubusercontent.com/72387126/175080026-6af50642-2dbb-400d-bff6-c5861d7e4156.png)


- The following figure shows the accumulated error after 70 s of integration for different values of the step:![ukkikuyki](https://user-images.githubusercontent.com/72387126/175080265-cbbc0a99-c128-40bb-a701-c159efd01cb9.png)
