function [values] = midSquare( seed )
    flag = 0;
    values( 1:500 ) = -1;
    values( 1 )=seed;
    valInd = 2;
    
    len = length( int2str(seed) );
    div = power( 10, ceil(len/2) );
    div2 = power( 10, len );
    
    while(flag~=1)
        
        sqSeed = power( seed, 2 );
        modSeed = mod( sqSeed, div );
        seed = ( sqSeed - modSeed ) / div;
        seed = mod( seed, div2 );
        
        i = find(values == seed);
        if i>0
            flag = 1;
        end
        
        values( valInd ) = seed;
        valInd = valInd + 1;
        
        fprintf( '%d (%d)\n', int64( seed ), int64( sqSeed ) );
    end
    fprintf('\n');
end