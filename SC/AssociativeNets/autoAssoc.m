clear all;
close all;
clc;
ip_vector=input('Enter training vector');
w=ip_vector'*ip_vector
choice='y';
while choice=='y'
    out=[0 0 0 0];
    ch_vector=input('Enter vector to check');
    out=ch_vector*w;
    for j=1:4
        if(out(j)<0)
            out(j)=-1;
        else
            out(j)=1;
        end
    end
    if(out==ip_vector)
        disp('Match');
    else
        disp('No match');
    end
    choice=char(input('Again ? (y)'));
end
