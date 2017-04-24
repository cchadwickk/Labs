function [val]=generateNo(a,b)
    val = (a+(b-a)*rand(1,1));
    round(val);
end