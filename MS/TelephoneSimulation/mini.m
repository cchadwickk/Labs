function [val]=mini(a,b,c,d)
    if(a<=b)&&(a<=c)&&(a<=d)
        val =a;
    elseif(b<=a)&&(b<=c)&&(b<=d)
        val =b;
    elseif(c<=a)&&(c<=b)&&(c<=d)
        val =c;
    elseif(d<=b)&&(d<=c)&&(d<=a)
        val =d;
    end
end