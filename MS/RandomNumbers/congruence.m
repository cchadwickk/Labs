function [] = congruence(r0, a, b, m)
    flag = 0;
    values(1:500)=-1;
    valInd = 1;
    x = r0;
    while(flag~=1)
        x = mod(x*a+b,m);
        
        i = find(values == x);
        if i>0
            flag = 1;
        end
        values(valInd) = x;
        valInd = valInd + 1;
        
        fprintf('%d\n',x);
    end
end