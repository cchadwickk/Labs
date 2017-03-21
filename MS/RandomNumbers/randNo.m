clear all;
x = input('Enter choice\n1. Mid-Square\n2. Congruence Method\n3. Arithmetic Congruence\n');

switch x
    case 1
        seed = input('Enter seed value: ');
        midSquare(seed);
        
    case 2
        %r0 = input('Enter r0');a = input('a');b = input('b');m = input('m');
        r0 = 1;a = 13;b = 1;m = 19;
        congruence(r0, a, b, m);
        
    case 3
        %r1 = input('Enter r1');r2 = input('Enter r2');m = input('Enter m');
        r1 = 9;r2 = 12;m = 17;
        arithCongruence(r1, r2, m);
        
    otherwise
        disp('ERROR: Invalid Input');
end