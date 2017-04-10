clear all;
clc;

empty=9999999;
redial=zeros(1000,2);
redial(:,:)=empty;
redBeg=1;
redEnd=1;
callInd=1;
time = 0;
success=0;
lines=[empty empty]';
miniVal=[0];
line1Empty=0;
line2Empty=0;
emptyTime=0;
redSuccess=0;
delay=0;

calls=round(40+120*rand(1000,1))';
for i=2:1000
    calls(i)=calls(i-1)+calls(i);
end
fprintf('CALLS:\n');
calls'

while callInd<=1000
    i=callInd;
    miniVal=mini(lines(1),lines(2),calls(i),redial(redBeg,1));
    
    if(lines(1)==miniVal)       %IF LINE 1 IS TO BE EMPTIED
        time=lines(1);
        line1Empty=time;
        success=success+1;
        lines(1)=empty;
        
    elseif(lines(2)==miniVal)   %IF LINE 2 IS TO BE EMPTIED
        time=lines(2);
        line2Empty=time;
        success=success+1;
        lines(2)=empty;
        
    elseif(calls(i)==miniVal)   %IF NEXT CALL IS TO BE ALLOCATED
        time=calls(i);
        
        if(lines(1)==empty)
            emptyTime=emptyTime+(time-line1Empty);
            line1Empty=empty;
            lines(1)=calls(i)+round(generateNo(120,240));
            
        elseif(lines(2)==empty)
            emptyTime=emptyTime+(time-line2Empty);
            line2Empty=empty;
            lines(2)=calls(i)+round(generateNo(120,240));
            
        else
            redial(redEnd,1)=calls(i)+round(generateNo(240,360));
            redial(redEnd,2)=calls(i);
            redEnd=redEnd+1;
        end
        callInd=callInd+1;
        
    elseif(redial(redBeg)==miniVal)   %IF REDIAL IS TO BE EVALUATED
        time=redial(redBeg,1);
        
        if(lines(1)==empty)
            emptyTime=emptyTime+(time-line1Empty);
            lines(1)=redial(redBeg)+round(generateNo(120,240));
            delay=delay+(time-redial(redBeg,2));
            success+success+1;
            redSuccess=redSuccess+1;
            
        elseif(lines(2)==empty)
            emptyTime=emptyTime+(time-line2Empty);
            lines(2)=redial(redBeg)+round(generateNo(120,240));
            delay=delay+(time-redial(redBeg,2));
            success=success+1;
            redSuccess=redSuccess+1;
            
        else            
            redBeg=redBeg+1;
        end
    end
end

fprintf('Successful calls: %d\nPercentage: %d%%\n',success,round(success/10));
fprintf('Calls successful after redial: %d\n\n',redSuccess);
utilized=(time*2)-emptyTime;
totalTime=time*2;
fprintf('Time utilized: %d\nTotal time: %d\nUtilization: %.3f\n\n',utilized,totalTime,utilized/totalTime);
fprintf('Average delay per successful call: %.2f\n',delay/success);
