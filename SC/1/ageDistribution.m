close all;
clear all;
clc;
x=(15:0.1:100);
youngp=[17 23 27 33];
middle_agedp=[27 33 57 63];
oldp=[57 63 87 93];
young=trapmf(x,youngp);
middle_aged=trapmf(x,middle_agedp);
old=trapmf(x,oldp);
in = input('Enter age:');
hold on
plot(x,young,'m')
plot(x,middle_aged,'g')
plot(x,old,'b')
legend('Young','Middle Aged','Aged');
if (in>=17)&&(in<=33)
        yin=evalmf(in,youngp,'trapmf');
        plot(in,yin,'k*')
        plot([in,in],[0,yin],'linestyle','-','color','k')
        plot([0,in],[yin,yin],'linestyle','-','color','k')
        disp(['Weight  ',num2str(in),' has the young degree ',num2str(yin)]);
end
if (in>=27)&&(in<=63)
        yin=evalmf(in,middle_agedp,'trapmf');
        plot(in,yin,'k*')
        plot([in,in],[0,yin],'linestyle','-','color','k')
        plot([0,in],[yin,yin],'linestyle','-','color','k')
        disp(['Weight  ',num2str(in),' has the middle aged degree ',num2str(yin)]);
end
if (in>=57)&&(in<=93)
        yin=evalmf(in,oldp,'trapmf');
        plot(in,yin,'k*')
        plot([in,in],[0,yin],'linestyle','-','color','k')
        plot([0,in],[yin,yin],'linestyle','-','color','k')
        disp(['Weight  ',num2str(in),' has the old degree ',num2str(yin)]);
end
hold off
axis([15 100 0 1.05]);
xlabel('Age(years)')
title('Age')