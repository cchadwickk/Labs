function [values] = arithCongruence(x, prev, m)
    flag = 0;
    values(1:500)=-1;
    valInd = 1;
    
    while(flag~=1)
        temp = x;
        x = mod(x + prev,m);
        prev = temp;
        
        i = find(values == x);
        if i>1
            for y = i
                if(values(y-1) == prev)
                    flag = 1;
                    break;
                end
            end
        end
        values(valInd) = x;
        valInd = valInd + 1;
        
        fprintf('%d\n',x);
    end
end