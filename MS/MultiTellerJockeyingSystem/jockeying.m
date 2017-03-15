clear all;
clc;
time = 0;
endTime = 480;
i=0;
queues = zeros ( 5,100 );
enterTimes = zeros( 5,100 );
arrTimes = randi ( [1,4],1,500 );
sum = arrTimes (1,1);

for i=1:500
    arrTimes(1,i) = sum;
    sum = sum + arrTimes(1,i+1); 
servTimes = randi ( [1,8],1,500 );
cntr = 1;

while ( time <= endTime )
    %arrival begins
    miniVals = min(queues);
    if( miniVals(1) + time > arrTimes(cntr))
        minArr = 1;
        minArrInd = find1(queues(1));
        for i=2:5
            if(find1(queues(i))<minArrInd)
                minArr = i;
                minArrInd = find1(queues(i));
            end
        end
        queues(i,minArrInd+1) = servTimes (cntr);
        time = arrTimes(1,cntr);
        queues([1:5],1) = queues([1:5],1).-arrTimes(1,cntr);
        cntr = cntr + 1;
    
    %departure begins
    else
        minArr = queues(1,1);
        minArrInd = 1;
        for i=2:5
            if(queues(i,1) < minArr)
                minArrInd = i;
                minArr = queues(i,1);
            end
        end
        time = time + queues(minArrInd);
        queues(,1) = queues(,1).-queues(minArrInd,1);
        circshift(queues(minArrInd),-1);
        
        
        %jockeying here
        minArrLen = -1;
        for i=1:5
            if(i ~= minArrInd) && (find1(queues(i)) > (find1(minArrInd) + 1))
                minArrLen = i;
            end
        end
        
        if(minArrLen>0)
            queues(minArrInd,find1(queues(minArrInd))) = queues(minArrLen,find1(queues(minArrLen)));
            queues(minArrLen,find1(queues(minArrLen))) = 0;
        end
        