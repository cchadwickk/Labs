function [x] = find1(arr)
     i = 0;
     for ii = arr
         i++;
         if(ii == 0)
             break;
         end
     end
     x=i-1;