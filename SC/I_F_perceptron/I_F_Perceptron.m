clear all;
clc;
x = zeros(2,3,3);
x(1,:,:)=[1 1 1;-1 1 -1;1 1 1];
x(2,:,:)=[1 1 1;1 1 1;1 -1 -1];
t=[1 -1];
flag=1;
epoch=1;
w=zeros(3,3);
b=0;
 
alpha=input('Learning rate=');
theta=input('Threshold value=');
while flag==1
    flag=0;
    disp('EPOCH :');
    disp(epoch);
    for i=1:2
        yin=b;
        for j=1:3
            for k = 1:3
                yin=yin+x(i,j,k)*w(j,k);
            end
        end
 
        if yin>theta
            y=1;
        end
        if yin <=theta && yin>=-theta
            y=0;
        end
        if yin<-theta
            y=-1;
        end
 
        if y~=t(i)
            flag=1;
            for j=1:3
                for k=1:3
                    w(j,k)=w(j,k)+alpha*t(i)*x(i,j,k);
                end
            end
            b=b+alpha*t(i);
        end
        disp('    Weight:');
        disp(w);
        disp('    Bias:')
        disp(b);
        fprintf('\n\n');
    end
    epoch=epoch+1;
end
 
a=input('Enter now');
yin=b;
for j=1:3
    for k = 1:3
        yin=yin+a(j,k)*w(j,k);
    end
end
 
if yin>theta
    y=1;
end
if yin <=theta && yin>=-theta
    y=0;
end
if yin<-theta
    y=-1;
end
 
if y==t(1)
    disp('match with I');
elseif y==t(2)
    disp('match with F');
else
    disp('no match');
end