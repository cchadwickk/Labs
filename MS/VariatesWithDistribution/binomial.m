n=input('1.Binomial\n2.Poisson:  ');
if n==1
    p=input('Probability:  ');
    v=input('No. of variates: ');
    nt=input('Rand No per variate: ');
    for i=1:v
        x=0;
        n=nt;
        for j=1:n
            y=rand();
            if(y<p)
                x=x+1;
            end
        end
        disp('Random No: ');
        disp(x);
    end
elseif n==2
    lambda=input('Enter lambda (>0): ');
    n=input('Enter no of variates: ');
    mean=lambda;
    for i=1:n
        fact=1;x=0;
        comm_prob=0;
        y=rand();
        while(y>comm_prob)
           p=mod((lambda^x)*exp(-mean),x);
           comm_prob=comm_prob;
           x=n+1;
           fact=fact*x;
        end
        disp(x);
    end
else
    disp('Invalid input');
end