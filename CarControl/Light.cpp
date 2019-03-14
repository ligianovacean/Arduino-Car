#include "Light.h"

void initLight() 
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}


long middle(long a,long b,long c)
{
  if(b>=a && b<=c)
    return b;
  if(c>=a && c<=b)
    return c;
  return a;
}


int maxV(long a,long b,long c,long d)
{
  if(a>=b && a>=c && a>=d)
    return 0;
  if(b>=a && b>=c && b>=d)
    return 1;
  if(c>=b && c>=a && c>=d)
    return 2;
  if(d>=b && d>=a && d>=c)
    return 3;
   
}
int getLightDirection()
{
  //    0      1      2     3
  long lightF,lightL,lightB,lightR;
  long partialLights[3];

  for (int i=0;i<=2;i++)
  {
    partialLights[i]=analogRead(A0);
    delay(20);
  }
  lightF=middle(partialLights[0],partialLights[1],partialLights[2]);
  
  for (int i=0;i<=2;i++)
  {
    partialLights[i]=analogRead(A1);
    delay(20);
  }
  lightL=middle(partialLights[0],partialLights[1],partialLights[2]);

  for (int i=0;i<=2;i++)
  {
    partialLights[i]=analogRead(A2);
    delay(20);
  }
  lightB=middle(partialLights[0],partialLights[1],partialLights[2]);

  for (int i=0;i<=2;i++)
  {
    partialLights[i]=analogRead(A3);
    delay(20);
  }
  lightR=middle(partialLights[0],partialLights[1],partialLights[2]);

  int dir=maxV(lightF,lightL,lightB,lightR);

  return dir;
}

  
