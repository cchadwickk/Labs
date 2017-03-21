clear;
clc;
x=[1 1 -1 -1;1 -1 1 -1];
t=[1 -1 -1 -1];
out=zeros(4,9);
out(1:4,1)=x(1,1:4)';
out(1:4,2)=x(2,1:4)';
out(1:4,4)=t';
w=[0 0];
b=0;
alpha=input('Learning rate=');
theta=input('Threshold value=');
flag=1;
epoch=1;
while flag==1
    flag=0;
    disp(strcat('Epoch=',num2str(epoch)));
    disp('x y b t yin y w1 w2 wb');
    for i=1:4
        yin=b+x(1,i)*w(1)+x(2,i)*w(2);
        if yin>theta
            y=1;
        end
        if yin <=theta & yin>=-theta
            y=0;
        end
        if yin<-theta
            y=-1;
        end
        if y-t(i)
            flag=1;
            for j=1:2
                w(j)=w(j)+alpha*t(i)*x(j,i);
            end
            b=b+alpha*t(i);
        end
        out(i,3)=b;
    end
    epoch=epoch+1;
end
disp('Weight matrix');
disp(w);
disp('Bias');
disp(b);