clear all;
clc;
for i=1:4
    popu(1,i)=round(generateNo(1,20));
end
for i=1:4
    fit(1,i)=popu(1,i)*popu(1,i);
end
total=sum(fit);
for i=1:4
    prob(1,i)=fit(1,i)/total;
end
for i=1:4
    expCount(1,i)=fit(1,i)/total*4;
end
popuChar={'','','',''};
for i=1:4
    LABELS(1,i)=num2str(popu(1,i));
end
pie(prob,popu);