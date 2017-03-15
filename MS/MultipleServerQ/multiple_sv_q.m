clear all;
clc;
q=0.1;%Time Quantum
thinktime=rand(1,80);%generate random think times of all 80 stations
avg=0;
avgresponsetime=zeros(1,100);
for k=1:100
    responsetime=zeros(1,10);
    jobprocessed=0;
    servicetime=zeros(1,80);
    sortarrivaltime1=zeros(1,10);
    terminal=zeros(1,10);
    b=ones(1,10);
    activeterminals=randi([1 80],1,10);%active terminals random between 1 and 80
    for i=1:10
        j=activeterminals(i);
        servicetime(j)=0+(2-0)*rand(1,1); %random service time 
        sortarrivaltime1(i)=thinktime(j); 
        terminal(i)=j;
    end
    %sorting of arrival times and terminals
    for i=1:10
        for j=i:10
            if sortarrivaltime1(i)>sortarrivaltime1(j)
                temp=sortarrivaltime1(i);
                temp1=terminal(i);
                sortarrivaltime1(i)=sortarrivaltime1(j);
                terminal(i)=terminal(j);
                sortarrivaltime1(j)=temp;
                terminal(j)=temp1;
            end
        end
    end
    j=1:10;
    responsetime(j)=sortarrivaltime1(j);
    if (jobprocessed~=1000)
        for i=1:10
            if (servicetime(terminal(i))~=0)
                if(servicetime(terminal(i)>q))
                    servicetime(terminal(i))=servicetime(terminal(i))-q;
                    responsetime(b)=responsetime(b)+q;
                elseif(servicetime(terminal(i)<=q))
                        servicetime(terminal(i))=0;
                        responsetime(b)=responsetime(b)+servicetime(terminal(i));
                        b(i)=0;
                        jobprocessed=jobprocessed+1;
                end
            end
        end
    end
    avgresponsetime(k)=sum(responsetime);
    avgresponsetime(k)=avgresponsetime(k)/10;
end
avg=sum(avgresponsetime);
avg=avg/100;


fprintf('The Average response time is:: %f\n',avg*100);