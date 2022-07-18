# TNDS-exercises
some selected exercises carried out during the course of numerical treatment of experimental data (TNDS) at the physics faculty of Unimi. 
I report below some graphical results of the exercises


## - Differential equations:
In these exercises I use some methods for solving ordinary differential equations, in particular I use the Euler and Runge-Kutta methods

### Euler method for the harmonic oscillator (EX.1): 
- Euler's method is not very precise, in fact with a modest integration step we can see how it can be unstable, showing oscillations whose amplitude varies with time. The figure below shows the trend of x as a function of t with an integration step of 0.1 seconds:
![ffffff](https://user-images.githubusercontent.com/72387126/179501057-5bcc11af-4548-42eb-b256-c33fd82a51b8.png)


- To have something even visually acceptable, you have to go in steps of at least 0.0001 s:
![hhhhhh](https://user-images.githubusercontent.com/72387126/179501345-67ff3e88-76d5-47c0-812e-0a56b5356151.png)


- The following figure shows the accumulated error after 70 s of integration for different step values (Note how the slope of the curve is 1 in a log-log scale, showing how the error obtained is proportional to step h):
![jjjjjj](https://user-images.githubusercontent.com/72387126/179501630-9252f1a7-a204-4756-a293-a589cd74a443.png)


### Runge-Kutta method for the harmonic oscillator (EX.2):
- The fourth order Runge-Kutta method is much more precise than the Euler method, in fact, even with an integration step of 0.1 s it produces very stable oscillations:
![kkkkk](https://user-images.githubusercontent.com/72387126/179502080-701f2b64-b6f2-44f6-90f2-75a46b126223.png)


- The following figure shows the accumulated error after 70 s of integration for different values of the step: ![xxxxxx](https://user-images.githubusercontent.com/72387126/179502302-56ad8556-123f-4108-a574-4b013c63f23c.png)

