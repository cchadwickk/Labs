close all;
x=(30:0.1:110);
underp=[35 45 55 65];%40,60
healthyp=[55 65 75 85];%60,80
overp=[75 85 90 100];%80 95
under=trapmf(x,underp);
healthy=trapmf(x,healthyp);
over=trapmf(x,overp);
in=input('Enter weight:');
hold on
plot(x,under,'m')
plot(x,healthy,'g')
plot(x,over,'b')
legend('Under','Healthy','Over');
if (in>=35)&&(in<=65)
        yin=evalmf(in,underp,'trapmf');
        plot(in,yin,'k*')
        plot([in,in],[0,yin],'linestyle','-','color','k')
        plot([0,in],[yin,yin],'linestyle','-','color','k')
        disp(['Weight  ',num2str(in),' has the underweight degree ',num2str(yin)]);
end
if (in>=55)&&(in<=85)
        yin=evalmf(in,healthyp,'trapmf');
        plot(in,yin,'k*')
        plot([in,in],[0,yin],'linestyle','-','color','k')
        plot([0,in],[yin,yin],'linestyle','-','color','k')
        disp(['Weight  ',num2str(in),' has the healthy degree ',num2str(yin)]);
end
if (in>=75)&&(in<=100)
        yin=evalmf(in,overp,'trapmf');
        plot(in,yin,'k*')
        plot([in,in],[0,yin],'linestyle','-','color','k')
        plot([0,in],[yin,yin],'linestyle','-','color','k')
        disp(['Weight  ',num2str(in),' has the overweight degree ',num2str(yin)]);
end
hold off
axis([30 110 0 1.05]);
xlabel('Weight(Kg)')
title('Weight')