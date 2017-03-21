clear;
clc;
a1=input('A a1=');
a2=input('A a2=');
b1=input('B b1=');
b2=input('B b2=');
d1=input('D d1=');
d2=input('D d2=');
disp('Threshold');
theta=input('theta=');
x1=[0 0 1 1];
x2=[0 1 0 1];
z=[0 1 1 0];
flag=1;
while flag
  zin1=x1*a1+x2*b1;
  zin2=x1*a2+x2*b2;
  for i=1:4
      if zin1(i)>=theta
          y1(i)=1;
      else
          y1(i)=0;
      end     
      if zin2(i)>=theta
          y2(i)=1;
      else
          y2(i)=0;
      end
  end
  yin=y1*d1+y2*d2;
  for i=1:4
      if yin(i)>=theta;
          y(i)=1;
      else
          y(i)=0;
      end
  end
  disp('Output of Net');
  disp(y);
  if y==z
      flag=0;
  else
      disp('Enter new weights and threshold');
      a1=input('A a1=');
      a2=input('A a2=');
      b1=input('B b1=');
      b2=input('B b2=');
      d1=input('D d1=');
      d2=input('D d2=');
      theta=input('theta=');
  end
end
disp('Weights of A');
disp(a1);
disp(a2);
disp('Weights of B');
disp(b1);
disp(b2);
disp('Weights of D');
disp(d1);
disp(d2);
disp('Threshold value');
disp(theta);